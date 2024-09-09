#include <xc.h>

#pragma config FOSC = INTOSC_HS 
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 8000000
#define time 200

void main(void) {
    OSCCON = 0x72;
    ADCON1 = 0x0F;
    TRISA = 0x00;
    TRISB = 0x00;
    TRISC = 0x00;
    TRISD = 0x00;
    TRISE = 0x00;
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;
    LATD = 0x00;
    LATE = 0x00;
    
    while(1){
        LATE = 0xFF;
        __delay_ms(time);
        LATE = 0x00;
        LATA = 0xFF;
        __delay_ms(time);
        LATA = 0x00;
        LATB = 0xFF;
        __delay_ms(time);
        LATB = 0x00;
        LATC = 0xFF;
        __delay_ms(time);
        LATC = 0x00;
        LATD = 0xFF;
        __delay_ms(time);
        LATD = 0x00;
    }
}