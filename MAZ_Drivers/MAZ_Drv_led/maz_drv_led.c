/*
 * MAZ_Drv_led.c
 *
 *  Created on: Dec 29, 2019
 *      Author: Paul@maziot.com
 */

#include <maz_drv_led.h>

#if defined(R1)
static MAZDRV_LED_CTRL g_mazdrv_led_ctrl[MAZDRV_LED_MAX] =
{
    [MAZDRV_LED0] =
    {
        .port       = MAZDRV_GPIO_PORTA,
        .pin        = MAZDRV_GPIO_PIN8,
        .polarity   = MAZDRV_LED_POLARITY_LOW,
        .status     = MAZDRV_LED_STATUS_OFF,
    },
    [MAZDRV_LED1] =
    {
        .port       = MAZDRV_GPIO_PORTD,
        .pin        = MAZDRV_GPIO_PIN2,
        .polarity   = MAZDRV_LED_POLARITY_LOW,
        .status     = MAZDRV_LED_STATUS_OFF,
    },
};
#endif

/**
 * @brief  MAZ_Drv_led_init
 * @retval Error code
 */
int MAZ_Drv_led_init(void)
{
    MAZDRV_LED led;
    MAZDRV_LED_CTRL *ctrl = NULL;
    GPIO_InitTypeDef GPIO_InitStruct = { 0 };

    ctrl = g_mazdrv_led_ctrl;

    for (led = MAZDRV_LED0; led < MAZDRV_LED_MAX; led++)
    {
        /* GPIO Ports Clock Enable */
        MAZ_Drv_gpio_prot_clk_enable(ctrl[led].port);

        /* Configure GPIO pin */
        GPIO_InitStruct.Pin = ctrl[led].pin;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.Pull = (ctrl[led].polarity == MAZDRV_LED_POLARITY_HIGH) ? GPIO_PULLDOWN : GPIO_PULLUP;
        HAL_GPIO_Init((GPIO_TypeDef*) ctrl[led].port, &GPIO_InitStruct);

        /* Set default status */
        MAZ_Drv_led_set_status(led, ctrl[led].status);
    }

    return MAZRET_NOERR;
}

/**
 * @brief  MAZ_Drv_led_set_status
 * @retval Error code
 */
int MAZ_Drv_led_set_status(MAZDRV_LED led, MAZDRV_LED_STATUS status)
{
    MAZDRV_LED_POLARITY polarity;
    MAZDRV_LED_CTRL *ctrl = NULL;

    if (led < MAZDRV_LED0 || led >= MAZDRV_LED_MAX)
    {
        return MAZRET_EINVAL;
    }

    if (status < MAZDRV_LED_STATUS_ON || status > MAZDRV_LED_STATUS_TOGGLE)
    {
        return MAZRET_EINVAL;
    }

    ctrl = g_mazdrv_led_ctrl;

    switch (status)
    {
        case MAZDRV_LED_STATUS_ON:
            polarity = ctrl[led].polarity;
            HAL_GPIO_WritePin((GPIO_TypeDef*) ctrl[led].port, ctrl[led].pin, polarity);
            break;
        case MAZDRV_LED_STATUS_OFF:
            if (MAZDRV_LED_POLARITY_HIGH == ctrl[led].polarity)
                polarity = MAZDRV_LED_POLARITY_LOW;
            else if (MAZDRV_LED_POLARITY_LOW == ctrl[led].polarity)
                polarity = MAZDRV_LED_POLARITY_HIGH;
            HAL_GPIO_WritePin((GPIO_TypeDef*) ctrl[led].port, ctrl[led].pin, polarity);
            break;
        case MAZDRV_LED_STATUS_TOGGLE:
            HAL_GPIO_TogglePin((GPIO_TypeDef*) ctrl[led].port, ctrl[led].pin);
            break;
    }

    return MAZRET_NOERR;
}



