#include <xc.h>
#include <pic16f877a.h>
#define _XTAL_FREQ 8000000
#define TMR2PRESCALAR  4
long FPWM;
void PWM1_CLOSE() {
    CCP1CON = 0x00;
}
void PWM1_Init(long F) {
    PR2 = ((_XTAL_FREQ) / (F * 4 * TMR2PRESCALAR)) - 1;
    FPWM = F;
}
void PWM1_OPEN() {
    CCP1CONbits.CCP1M3 = 1;
    CCP1CONbits.CCP1M2 = 1;
#if TMR2PRESCALAR == 1
    T2CONbits.T2CKPS0 = 0;
    T2CONbits.T2CKPS1 = 0;
#elif TMR2PRESCALAR == 4
    T2CONbits.T2CKPS0 = 1;
    T2CONbits.T2CKPS1 = 0;
#elif TMR2PRESCALAR == 16
    T2CONbits. T2CKPS0 = 1;
    T2CONbits.T2CKPS1 = 1;
#endif
    T2CONbits.TMR2ON = 1;
    TRISCbits.TRISC2 = 0;
}
void PWM1_Set_Duty(unsigned int duty) {
    if (duty < 256){
        duty = (((float) duty / 256)*(_XTAL_FREQ / (FPWM * TMR2PRESCALAR))) - 1;
        CCP1CONbits.CCP1X = (duty >> 1) & 1; //second bit Store in CCP1X_bit 
        CCP1CONbits.CCP1Y = duty & 1; //first bit Store in  CCP1Y_bit
        CCPR1L = duty >> 2;          //store 8 bit in register CCPR1L
   }
}