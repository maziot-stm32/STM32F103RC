/*
 * port.h
 *
 *  Created on: 2019年12月28日
 *      Author: Paul@maziot.com
 */

#ifndef ARM_CM3_PORT_H_
#define ARM_CM3_PORT_H_

/*
 * Setup the timer to generate the tick interrupts.  The implementation in this
 * file is weak to allow application writers to change the timer used to
 * generate the tick interrupt.
 */
void vPortSetupTimerInterrupt( void );

/*
 * Exception handlers.
 */
void xPortPendSVHandler( void ) __attribute__ (( naked ));
void xPortSysTickHandler( void );
void vPortSVCHandler( void ) __attribute__ (( naked ));

#endif /* ARM_CM3_PORT_H_ */
