/*
PIC 18F4550
Matriz de leds 8x8 cátodo común
Author: Fabián Barrera Prieto
Mestrado em Sistemas Mecatrônicos
Created on 14 de Setembro de 2023, 11:45
 */

#include <xc.h>
#include <string.h>

#pragma config FOSC = INTOSCIO_EC
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 8000000
#define time 100

void settings(void);
void concatenar(unsigned char *n, unsigned char *letraF, unsigned char *letraA, unsigned char *letraB, unsigned char *letraI, unsigned char *letraN);

unsigned char F[4] = {0xFF, 0x09, 0x09, 0x01};
unsigned char columna[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
int i, j, k, longitud = 29, flag = 0;

void __interrupt() matrizled(void);

void main(void) {
    settings();
    while (1) {
        if (flag) {
            for (k = 0; k < 100; k++) { //tiempo de espera (cambiar por temporizadores)
                for (i = 0; i < 8; i++) {//recorriendo columnas
                    LATD = columna[7 - i]; //(0x80 >> i);
                    if (i >= 4) {//j=4
                        LATA = 255;
                        LATC = 15;
                    } else {
                        LATA = ~F[3 - i];
                        LATC = ~((F[3 - i] & 0x80) >> 7);
                    }
                    __delay_ms(5);
                    //LATA = 255;
                    //LATC = 1;
                }
            }
            LATD = 0;
            flag = 0;
        }
    }
}

void settings(void) {
    OSCCON = 0x72;
    ADCON1 = 0x0F;
    TRISA = 0;
    TRISC = 0;
    TRISD = 0;
    LATA = 255;
    LATC = 1;
    LATD = 0;
    //Interrupción
    GIE = 1;
    INT1IE = 1;
    INT1IF = 0;
    INTEDG1 = 0;
}

void __interrupt() matrizled(void) {
    if (INT1IF) {
        INT1IF = 0;
        flag = 1;
    }
}