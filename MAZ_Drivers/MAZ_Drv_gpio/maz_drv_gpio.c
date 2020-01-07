/*
 * maz_drv_gpio.c
 *
 *  Created on: Dec 29, 2019
 *      Author: Paul@maziot.com
 */

#include <maz_drv_gpio.h>

/**
 * @brief  MAZ_Drv_gpio_prot_clk_enable
 * @retval Error code
 */
int MAZ_Drv_gpio_prot_clk_enable(MAZDRV_GPIO_PORT port)
{
    if (port < MAZDRV_GPIO_PORTA || port > MAZDRV_GPIO_PORTG)
    {
        return MAZRET_EINVAL;
    }

    /* GPIO Ports Clock Enable */
    switch (port)
    {
        case MAZDRV_GPIO_PORTA:
            __HAL_RCC_GPIOA_CLK_ENABLE();
            break;
        case MAZDRV_GPIO_PORTB:
            __HAL_RCC_GPIOB_CLK_ENABLE();
            break;
        case MAZDRV_GPIO_PORTC:
            __HAL_RCC_GPIOC_CLK_ENABLE();
            break;
        case MAZDRV_GPIO_PORTD:
            __HAL_RCC_GPIOD_CLK_ENABLE();
            break;
        case MAZDRV_GPIO_PORTE:
            __HAL_RCC_GPIOE_CLK_ENABLE();
            break;
        case MAZDRV_GPIO_PORTF:
            __HAL_RCC_GPIOF_CLK_ENABLE();
            break;
        case MAZDRV_GPIO_PORTG:
            __HAL_RCC_GPIOG_CLK_ENABLE();
            break;
    }

    return MAZRET_NOERR;
}

