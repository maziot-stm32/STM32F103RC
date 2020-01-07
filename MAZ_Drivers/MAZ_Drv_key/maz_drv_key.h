/*
 * maz_drv_key.h
 *
 *  Created on: Dec 29, 2019
 *      Author: Paul@maziot.com
 */

#ifndef MAZ_DRV_KEY_H_
#define MAZ_DRV_KEY_H_

#include <stm32f1xx_hal.h>
#include <maz_drv_gpio.h>

typedef void (*MAZDRV_KEY_HANDLE)(void);

typedef enum _MAZDRV_KEY_
{
    MAZDRV_KEY0 = 0,
    MAZDRV_KEY1,
    MAZDRV_KEY2,
    MAZDRV_KEY_MAX,
} MAZDRV_KEY;

typedef enum _MAZDRV_KEY_POLARITY_
{
    MAZDRV_KEY_POLARITY_HIGH = GPIO_PIN_SET,
    MAZDRV_KEY_POLARITY_LOW = GPIO_PIN_RESET,
} MAZDRV_KEY_POLARITY;

typedef enum _MAZDRV_KEY_MODE_
{
    MAZDRV_KEY_INTERRUPT = 0,
    MAZDRV_KEY_SCAN,
} MAZDRV_KEY_MODE;

typedef struct _MAZDRV_KEY_CTRL_
{
    MAZDRV_GPIO_PORT port;                  // 连接KEY的GPIO PORT
    MAZDRV_GPIO_PIN pin;                    // 连接KEY的GPIO PIN
    MAZDRV_KEY_POLARITY polarity;           // 按下后GPIO是高电平还是低电平
    MAZDRV_KEY_MODE mode;                   // 检测方式是中断还是扫描
    MAZDRV_KEY_HANDLE handle;               // 中断回调函数
} MAZDRV_KEY_CTRL;

int MAZ_Drv_key_init(void);

#endif /* MAZ_DRV_KEY_H_ */
