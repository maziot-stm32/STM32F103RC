/*
 * MAZ_Drv_exti.h
 *
 *  Created on: Jan 2, 2020
 *      Author: Paul@maziot.com
 */

#ifndef MAZ_DRV_EXTI_H_
#define MAZ_DRV_EXTI_H_

#include <stm32f1xx_hal.h>
#include <maz_drv_gpio.h>

/* cb: callback */
typedef void (*MAZDRV_EXTI_CB)(void);

int MAZ_Drv_exti_irq_enable(MAZDRV_GPIO_PIN pin, MAZDRV_EXTI_CB cb);

#endif /* MAZ_DRV_EXTI_H_ */
