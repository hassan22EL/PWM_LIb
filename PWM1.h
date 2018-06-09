/* 
 * File:  Pulse width modulation 
 * Author: Hassan Elsaied Mohammed Mohammed  
 * Comments:
 * ***********************************************************************
 * the micro computer able to Generates cycles From Clock , store period *
 * in PR2 register when T_PWM=[PR2+1]*4* prescaler(TRM2) * TOSC          *
 * and Store the Duty cycle in CCP1L and CCPH                            *
 * PWM using control output the voltage 0 to 5 at Duty cycle 50% the     *
 * Voltage = 2.5 V and the low calculator                                *
 *  Duty cycle =((Duty/1024)*(FOSC/(FPWM*prescaler)))-1 at resolution    * 
 * 10bits                                                                *
 * period Store in PR2 and Duty cycle Store CCP1L at SR Latch NOt change *
 * when the TRM2 NOT equal PR1 or CCP2L when CCP1L = TRM2 SR Latch Rest  *
 * and the Counter increment up to PR2 at Counter equal PR2 the SR Latch *
 * Set and the Counter Rest to zero                                      *                                                           *
 * ***********************************************************************
 * Revision history: 
 */
#ifndef _PWM1_H
#define	_PWM1_H
#include <xc.h> // include processor files - each processor file is guarded.
void PWM1_OPEN();
void PWM1_Init(long F);
void PWM1_Set_Duty(unsigned int duty);
void PWM1_CLOSE();
#endif	/*_PWM1_H*/