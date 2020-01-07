/*
 * maz_drv_key.c
 *
 *  Created on: Dec 29, 2019
 *      Author: Paul@maziot.com
 */

#include <maz_drv_key.h>
#include <maz_drv_led.h>
#include <maz_drv_exti.h>

void MAZ_Drv_key0_handle(void);
void MAZ_Drv_key1_handle(void);
void MAZ_Drv_key2_handle(void);

static MAZDRV_KEY_CTRL g_mazdrv_key_ctrl[MAZDRV_KEY_MAX] =
{
    [MAZDRV_KEY0] =
    {
        .port       = MAZDRV_GPIO_PORTC,
        .pin        = MAZDRV_GPIO_PIN1,
        .polarity   = MAZDRV_KEY_POLARITY_LOW,
        .mode       = MAZDRV_KEY_INTERRUPT,
        .handle     = MAZ_Drv_key0_handle,
    },
    [MAZDRV_KEY1] =
    {
        .port       = MAZDRV_GPIO_PORTC,
        .pin        = MAZDRV_GPIO_PIN13,
        .polarity   = MAZDRV_KEY_POLARITY_LOW,
        .mode       = MAZDRV_KEY_INTERRUPT,
        .handle     = MAZ_Drv_key1_handle,
    },
    [MAZDRV_KEY2] =
    {
        .port       = MAZDRV_GPIO_PORTA,
        .pin        = MAZDRV_GPIO_PIN0,
        .polarity   = MAZDRV_KEY_POLARITY_HIGH,
        .mode       = MAZDRV_KEY_INTERRUPT,
        .handle     = MAZ_Drv_key2_handle,
    },
};

/* Interrupt handler */
void MAZ_Drv_key0_handle(void)
{
    if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_1) != 0x00u)
    {
        MAZ_Drv_led_set_status(MAZDRV_LED0, MAZDRV_LED_STATUS_TOGGLE);
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_1);
    }
}

void MAZ_Drv_key1_handle(void)
{
    if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_13) != 0x00u)
    {
        MAZ_Drv_led_set_status(MAZDRV_LED1, MAZDRV_LED_STATUS_TOGGLE);
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_13);
    }
}

void MAZ_Drv_key2_handle(void)
{
    if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_0) != 0x00u)
    {
        MAZ_Drv_led_set_status(MAZDRV_LED0, MAZDRV_LED_STATUS_TOGGLE);
        MAZ_Drv_led_set_status(MAZDRV_LED1, MAZDRV_LED_STATUS_TOGGLE);
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_0);
    }
}

int MAZ_Drv_key_init(void)
{
    MAZDRV_KEY key;
    MAZDRV_KEY_CTRL *ctrl = NULL;
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    ctrl = g_mazdrv_key_ctrl;

    for (key = MAZDRV_KEY0; key < MAZDRV_KEY_MAX; key++)
    {
        /* GPIO Ports Clock Enable */
        MAZ_Drv_gpio_prot_clk_enable(ctrl[key].port);

        /* Configure GPIO pin */
        if(MAZDRV_KEY_INTERRUPT == ctrl[key].mode)
        {
            GPIO_InitStruct.Mode = (MAZDRV_KEY_POLARITY_LOW == ctrl[key].polarity) ? GPIO_MODE_IT_FALLING : GPIO_MODE_IT_RISING;
        }
        else
        {
            GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        }

        GPIO_InitStruct.Pin = ctrl[key].pin;
        GPIO_InitStruct.Pull = (MAZDRV_KEY_POLARITY_LOW == ctrl[key].polarity) ? GPIO_PULLUP : GPIO_PULLDOWN;
        HAL_GPIO_Init((GPIO_TypeDef*) ctrl[key].port, &GPIO_InitStruct);

        if(MAZDRV_KEY_INTERRUPT == ctrl[key].mode)
        {
            MAZ_Drv_exti_irq_enable(ctrl[key].pin, ctrl[key].handle);
        }
    }

    return MAZRET_NOERR;
}
