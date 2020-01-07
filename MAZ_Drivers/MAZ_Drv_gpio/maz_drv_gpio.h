/*
 * maz_drv_gpio.h
 *
 *  Created on: Dec 29, 2019
 *      Author: Paul@maziot.com
 */

#ifndef MAZ_DRV_GPIO_H_
#define MAZ_DRV_GPIO_H_

#include <stm32f1xx_hal.h>

typedef enum _MAZDRV_GPIO_PORT_
{
    MAZDRV_GPIO_PORTA = GPIOA_BASE,
    MAZDRV_GPIO_PORTB = GPIOB_BASE,
    MAZDRV_GPIO_PORTC = GPIOC_BASE,
    MAZDRV_GPIO_PORTD = GPIOD_BASE,
    MAZDRV_GPIO_PORTE = GPIOE_BASE,
    MAZDRV_GPIO_PORTF = GPIOF_BASE,
    MAZDRV_GPIO_PORTG = GPIOG_BASE,
} MAZDRV_GPIO_PORT;

typedef enum _MAZDRV_GPIO_PIN_
{
    MAZDRV_GPIO_PIN0 = GPIO_PIN_0,
    MAZDRV_GPIO_PIN1 = GPIO_PIN_1,
    MAZDRV_GPIO_PIN2 = GPIO_PIN_2,
    MAZDRV_GPIO_PIN3 = GPIO_PIN_3,
    MAZDRV_GPIO_PIN4 = GPIO_PIN_4,
    MAZDRV_GPIO_PIN5 = GPIO_PIN_5,
    MAZDRV_GPIO_PIN6 = GPIO_PIN_6,
    MAZDRV_GPIO_PIN7 = GPIO_PIN_7,
    MAZDRV_GPIO_PIN8 = GPIO_PIN_8,
    MAZDRV_GPIO_PIN9 = GPIO_PIN_9,
    MAZDRV_GPIO_PIN10 = GPIO_PIN_10,
    MAZDRV_GPIO_PIN11 = GPIO_PIN_11,
    MAZDRV_GPIO_PIN12 = GPIO_PIN_12,
    MAZDRV_GPIO_PIN13 = GPIO_PIN_13,
    MAZDRV_GPIO_PIN14 = GPIO_PIN_14,
    MAZDRV_GPIO_PIN15 = GPIO_PIN_15,
} MAZDRV_GPIO_PIN;

int MAZ_Drv_gpio_prot_clk_enable(MAZDRV_GPIO_PORT port);

#endif /* MAZ_DRV_GPIO_H_ */
