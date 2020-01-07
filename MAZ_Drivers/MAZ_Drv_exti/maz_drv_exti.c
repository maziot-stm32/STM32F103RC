/*
 * MAZ_Drv_exti.c
 *
 *  Created on: Jan 2, 2020
 *      Author: Paul@maziot.com
 */

#include <maz_drv_exti.h>

MAZDRV_EXTI_CB MAZ_Drv_exti_irq_cb[16];

int MAZ_Drv_exti_irq_enable(MAZDRV_GPIO_PIN pin, MAZDRV_EXTI_CB cb)
{
    if (pin < MAZDRV_GPIO_PIN0 || pin > MAZDRV_GPIO_PIN15)
    {
        return MAZRET_EINVAL;
    }

    /* GPIO Ports Clock Enable */
    switch (pin)
    {
        case MAZDRV_GPIO_PIN0:
            HAL_NVIC_SetPriority(EXTI0_IRQn, 8, 0);
            HAL_NVIC_EnableIRQ(EXTI0_IRQn);
            MAZ_Drv_exti_irq_cb[0] = cb;
            break;
        case MAZDRV_GPIO_PIN1:
            HAL_NVIC_SetPriority(EXTI1_IRQn, 8, 0);
            HAL_NVIC_EnableIRQ(EXTI1_IRQn);
            MAZ_Drv_exti_irq_cb[1] = cb;
            break;
        case MAZDRV_GPIO_PIN2:
            HAL_NVIC_SetPriority(EXTI2_IRQn, 8, 0);
            HAL_NVIC_EnableIRQ(EXTI2_IRQn);
            MAZ_Drv_exti_irq_cb[2] = cb;
            break;
        case MAZDRV_GPIO_PIN3:
            HAL_NVIC_SetPriority(EXTI3_IRQn, 8, 0);
            HAL_NVIC_EnableIRQ(EXTI3_IRQn);
            MAZ_Drv_exti_irq_cb[3] = cb;
            break;
        case MAZDRV_GPIO_PIN4:
            HAL_NVIC_SetPriority(EXTI4_IRQn, 8, 0);
            HAL_NVIC_EnableIRQ(EXTI4_IRQn);
            MAZ_Drv_exti_irq_cb[4] = cb;
            break;
        case MAZDRV_GPIO_PIN5:
            HAL_NVIC_SetPriority(EXTI9_5_IRQn, 8, 0);
            HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
            MAZ_Drv_exti_irq_cb[5] = cb;
            break;
        case MAZDRV_GPIO_PIN6:
            HAL_NVIC_SetPriority(EXTI9_5_IRQn, 8, 0);
            HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
            MAZ_Drv_exti_irq_cb[6] = cb;
            break;
        case MAZDRV_GPIO_PIN7:
            HAL_NVIC_SetPriority(EXTI9_5_IRQn, 8, 0);
            HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
            MAZ_Drv_exti_irq_cb[7] = cb;
            break;
        case MAZDRV_GPIO_PIN8:
            HAL_NVIC_SetPriority(EXTI9_5_IRQn, 8, 0);
            HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
            MAZ_Drv_exti_irq_cb[8] = cb;
            break;
        case MAZDRV_GPIO_PIN9:
            HAL_NVIC_SetPriority(EXTI9_5_IRQn, 8, 0);
            HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
            MAZ_Drv_exti_irq_cb[9] = cb;
            break;
        case MAZDRV_GPIO_PIN10:
            HAL_NVIC_SetPriority(EXTI15_10_IRQn, 8, 0);
            HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
            MAZ_Drv_exti_irq_cb[10] = cb;
            break;
        case MAZDRV_GPIO_PIN11:
            HAL_NVIC_SetPriority(EXTI15_10_IRQn, 8, 0);
            HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
            MAZ_Drv_exti_irq_cb[11] = cb;
            break;
        case MAZDRV_GPIO_PIN12:
            HAL_NVIC_SetPriority(EXTI15_10_IRQn, 8, 0);
            HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
            MAZ_Drv_exti_irq_cb[12] = cb;
            break;
        case MAZDRV_GPIO_PIN13:
            HAL_NVIC_SetPriority(EXTI15_10_IRQn, 8, 0);
            HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
            MAZ_Drv_exti_irq_cb[13] = cb;
            break;
        case MAZDRV_GPIO_PIN14:
            HAL_NVIC_SetPriority(EXTI15_10_IRQn, 8, 0);
            HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
            MAZ_Drv_exti_irq_cb[14] = cb;
            break;
        case MAZDRV_GPIO_PIN15:
            HAL_NVIC_SetPriority(EXTI15_10_IRQn, 8, 0);
            HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
            MAZ_Drv_exti_irq_cb[15] = cb;
            break;
    }

    return MAZRET_NOERR;
}

/**
 * @brief This function handles EXTI line0 interrupt.
 */
void EXTI0_IRQHandler(void)
{
    if(NULL != MAZ_Drv_exti_irq_cb[0])
    {
        MAZ_Drv_exti_irq_cb[0]();
    }
}

/**
 * @brief This function handles EXTI line1 interrupt.
 */
void EXTI1_IRQHandler(void)
{
    if(NULL != MAZ_Drv_exti_irq_cb[1])
    {
        MAZ_Drv_exti_irq_cb[1]();
    }
}

/**
 * @brief This function handles EXTI line1 interrupt.
 */
void EXTI2_IRQHandler(void)
{
    if(NULL != MAZ_Drv_exti_irq_cb[2])
    {
        MAZ_Drv_exti_irq_cb[2]();
    }
}

/**
 * @brief This function handles EXTI line1 interrupt.
 */
void EXTI3_IRQHandler(void)
{
    if(NULL != MAZ_Drv_exti_irq_cb[3])
    {
        MAZ_Drv_exti_irq_cb[3]();
    }
}

/**
 * @brief This function handles EXTI line1 interrupt.
 */
void EXTI4_IRQHandler(void)
{
    if(NULL != MAZ_Drv_exti_irq_cb[4])
    {
        MAZ_Drv_exti_irq_cb[4]();
    }
}

/**
 * @brief This function handles EXTI line[9:5] interrupts.
 */
void EXTI9_5_IRQHandler(void)
{
    if(NULL != MAZ_Drv_exti_irq_cb[5])
    {
        MAZ_Drv_exti_irq_cb[5]();
    }

    if(NULL != MAZ_Drv_exti_irq_cb[6])
    {
        MAZ_Drv_exti_irq_cb[6]();
    }

    if(NULL != MAZ_Drv_exti_irq_cb[7])
    {
        MAZ_Drv_exti_irq_cb[7]();
    }

    if(NULL != MAZ_Drv_exti_irq_cb[8])
    {
        MAZ_Drv_exti_irq_cb[8]();
    }

    if(NULL != MAZ_Drv_exti_irq_cb[9])
    {
        MAZ_Drv_exti_irq_cb[9]();
    }
}

/**
 * @brief This function handles EXTI line[15:10] interrupts.
 */
void EXTI15_10_IRQHandler(void)
{
    if(NULL != MAZ_Drv_exti_irq_cb[10])
    {
        MAZ_Drv_exti_irq_cb[10]();
    }

    if(NULL != MAZ_Drv_exti_irq_cb[11])
    {
        MAZ_Drv_exti_irq_cb[11]();
    }

    if(NULL != MAZ_Drv_exti_irq_cb[12])
    {
        MAZ_Drv_exti_irq_cb[12]();
    }

    if(NULL != MAZ_Drv_exti_irq_cb[13])
    {
        MAZ_Drv_exti_irq_cb[13]();
    }

    if(NULL != MAZ_Drv_exti_irq_cb[14])
    {
        MAZ_Drv_exti_irq_cb[14]();
    }

    if(NULL != MAZ_Drv_exti_irq_cb[15])
    {
        MAZ_Drv_exti_irq_cb[15]();
    }
}
