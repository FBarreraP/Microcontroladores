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
        LATE = 0x06;
        __delay_ms(time);
        LATE = 0x03;
        __delay_ms(time);
        LATE = 0x01;
        LATA = 0x20;
        __delay_ms(time);
        LATE = 0x00;
        LATA = 0x30;
        __delay_ms(time);
        LATA = 0x18;
        __delay_ms(time);
        LATA = 0x0C;
        __delay_ms(time);
        LATA = 0x06;
        __delay_ms(time);
        LATA = 0x03;
        __delay_ms(time);
        LATA = 0x01;
        LATB = 0x80;
        __delay_ms(time);
        LATA = 0x00;
        LATB = 0xC0;
        __delay_ms(time);
        LATB = 0x60;
        __delay_ms(time);
        LATB = 0x30;
        __delay_ms(time);
        LATB = 0x18;
        __delay_ms(time);
        LATB = 0x0C;
        __delay_ms(time);
        LATB = 0x06;
        __delay_ms(time);
        LATB = 0x03;
        __delay_ms(time);
        LATB = 0x01;
        LATC = 0x80;
        __delay_ms(time);
        LATB = 0x00;
        LATC = 0xC0;
        __delay_ms(time);
        LATC = 0x60;
        __delay_ms(time);
        LATC = 0x30;
        __delay_ms(time);
        LATC = 0x14;
        __delay_ms(time);
        LATC = 0x06;
        __delay_ms(time);
        LATC = 0x03;
        __delay_ms(time);
        LATC = 0x01;
        LATD = 0x80;
        __delay_ms(time);
        LATC = 0x00;
        LATD = 0xC0;
        __delay_ms(time);
        LATD = 0x60;
        __delay_ms(time);
        LATD = 0x30;
        __delay_ms(time);
        LATD = 0x18;
        __delay_ms(time);
        LATD = 0x0C;
        __delay_ms(time);
        LATD = 0x06;
        __delay_ms(time);
        LATD = 0x03;
        __delay_ms(time);
        LATD = 0x06;
        __delay_ms(time);
        LATD = 0x0C;
        __delay_ms(time);
        LATD = 0x18;
        __delay_ms(time);
        LATD = 0x30;
        __delay_ms(time);
        LATD = 0x60;
        __delay_ms(time);
        LATD = 0xC0;
        __delay_ms(time);
        LATD = 0x80;
        LATC = 0x01;
        __delay_ms(time);
        LATD = 0x00;
        LATC = 0x03;
        __delay_ms(time);
        LATC = 0x06;
        __delay_ms(time);
        LATC = 0x14;
        __delay_ms(time);
        LATC = 0x30;
        __delay_ms(time);
        LATC = 0x60;
        __delay_ms(time);
        LATC = 0xC0;
        __delay_ms(time);
        LATC = 0x80;
        LATB = 0x01;
        __delay_ms(time);
        LATC = 0x00;
        LATB = 0x03;
        __delay_ms(time);
        LATB = 0x06;
        __delay_ms(time);
        LATB = 0x0C;
        __delay_ms(time);
        LATB = 0x18;
        __delay_ms(time);
        LATB = 0x30;
        __delay_ms(time);       
        LATB = 0x60;
        __delay_ms(time);
        LATB = 0xC0;
        __delay_ms(time);
        LATB = 0x80;
        LATA = 0x01;
        __delay_ms(time);
        LATB = 0x00;
        LATA = 0x03;
        __delay_ms(time);
        LATA = 0x06;
        __delay_ms(time);
        LATA = 0x0C;
        __delay_ms(time);
        LATA = 0x18;
        __delay_ms(time);
        LATA = 0x30;
        __delay_ms(time);
        LATA = 0x20;
        LATE = 0x01;
        __delay_ms(time);
        LATA = 0x0;
        LATE = 0x03;
        __delay_ms(time);       
        LATE = 0x06;
        __delay_ms(time);       
    }
}