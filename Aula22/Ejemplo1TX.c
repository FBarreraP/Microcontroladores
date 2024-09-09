/*
PIC 18F4550
UART transmisor
Author: Fabián Barrera Prieto
Mestrado em Sistemas Mecatrônicos
Created on 13 de Outubro de 2023, 12:44
 */

#include <xc.h>
#include <stdio.h>
#include <string.h>

#pragma config FOSC = INTOSC_HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 8000000
#define time 100

void settings(void);
void __interrupt() Tx(void);

unsigned char i, k = 0, j = 0, flag = 0;
char text[20];

void main(void) {
    settings();
    while (1) {
        if (flag == 1) {
            k++;
            sprintf(text, "B) Int.2: %d\n", k);
            for (i = 0; i <= strlen(text); i++) {
                while (TXIF == 0);
                TXREG = text[i];
            }
            while (TXIF == 0);
            TXREG = 0x0D; //Retorno de carro
            flag = 0;
        } else if (flag == 2) {
            j++;
            sprintf(text, "A) Int.1: %d\n", j);
            for (i = 0; i <= strlen(text); i++) {
                while (TXIF == 0);
                TXREG = text[i];
            }
            while (TXIF == 0);
            TXREG = 0x0D; //Retorno de carro
            flag = 0;
        }
    }
}

void settings(void) {
    OSCCON = 0x72;
    ADCON1 = 0x0F;
    //Serial UART
    TRISCbits.TRISC6 = 0;
    TRISCbits.TRISC7 = 1;
    SPBRG = 0x0C;
    RCSTA = 0x90;
    TXSTA = 0x20;
    //Interrupción externa
    GIE = 1;
    INT2IE = 1;
    INT1IE = 1;
    INT2IF = 0;
    INT1IF = 0;
    INTEDG2 = 1;
    INTEDG1 = 0;
}

void __interrupt() Tx(void) {
    if (INT2IF == 1) {
        __delay_ms(time);
        INT2IF = 0;
        flag = 1;
    }
    if (INT1IF == 1) {
        __delay_ms(time);
        INT1IF = 0;
        flag = 2;
    }
}