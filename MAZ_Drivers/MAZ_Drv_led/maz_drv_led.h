/*
 * MAZ_Drv_led.h
 *
 *  Created on: Dec 29, 2019
 *      Author: Paul@maziot.com
 */

#ifndef MAZ_DRV_LED_H_
#define MAZ_DRV_LED_H_

#include <stm32f1xx_hal.h>
#include <maz_drv_gpio.h>

#if defined(R1)
typedef enum _MAZDRV_LED_
{
    MAZDRV_LED0 = 0,
    MAZDRV_LED1,
    MAZDRV_LED_MAX,
} MAZDRV_LED;
#endif

typedef enum _MAZDRV_LED_GPIO_LEVEL_
{
    MAZDRV_LED_POLARITY_HIGH = GPIO_PIN_SET,
    MAZDRV_LED_POLARITY_LOW = GPIO_PIN_RESET,
} MAZDRV_LED_POLARITY;

typedef enum _MAZDRV_LED_STATUS_
{
    MAZDRV_LED_STATUS_ON = 0,
    MAZDRV_LED_STATUS_OFF,
    MAZDRV_LED_STATUS_TOGGLE,
} MAZDRV_LED_STATUS;

typedef struct _MAZDRV_LED_CTRL_
{
    MAZDRV_GPIO_PORT port;                  // 连接LED的GPIO PORT
    MAZDRV_GPIO_PIN pin;                    // 连接LED的GPIO PIN
    MAZDRV_LED_POLARITY polarity;           // 高电平还是低电平点亮
    MAZDRV_LED_STATUS status;               // 默认状态是点亮还是熄灭
} MAZDRV_LED_CTRL;

int MAZ_Drv_led_init(void);
int MAZ_Drv_led_set_status(MAZDRV_LED led, MAZDRV_LED_STATUS status);

#endif /* MAZ_DRV_LED_H_ */
