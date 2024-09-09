/*
PIC 18F4550
UART receptor
Author: Fabián Barrera Prieto
Mestrado em Sistemas Mecatrônicos
Created on 13 de Outubro de 2023, 12:52
 */

#include <xc.h>
#include <string.h>

#pragma config FOSC = INTOSC_HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 8000000
#define time 10
//LCD
#define CD 0x01 //Clear Display
#define RH 0x02 //(0x03) Return Home
#define EMS 0x06 //Entry Mode Set
#define DC 0x0F //(0x0E) Display Control
#define DSr 0x1C //Display Shift Rigth
#define DSl 0x18 //Display Shift Left
#define FS 0x28 //(0x3C) Function Set
#define RAW1 0x80 //DDRAM display
#define RAW2 0xC0 //DDRAM display
#define button PORTBbits.RB2 //Button start
#define RS LATEbits.LATE1 //Register Selection
#define E LATEbits.LATE0 //Enable

void settings(void);
void __interrupt() RECEIVE(void);
//LCD
void SettingsLCD(unsigned char word);
void WriteLCD(unsigned char word);
void LCD(unsigned char data);

unsigned char flag = 0, d, i, k = 0, data[15];

void main(void) {
    settings();
    while (1) {
        if (flag == 1) {
            for (i = 0; i < strlen(data); i++) {
                if (data[i] == 0x41) {
                    SettingsLCD(RAW1);
                    WriteLCD(data[i]);
                } else if (data[i] == 'B') {
                    SettingsLCD(RAW2);
                    WriteLCD(data[i]);
                } else if (data[i] == 0x0D) {
                    SettingsLCD(RH);
                } else {
                    WriteLCD(data[i]);
                }
            }
            flag = 0;
        }
    }
}

void SettingsLCD(unsigned char word) {
    RS = 0;
    LCD(word >> 4); // 4 MSB
    LCD(word & 0x0F); // 4 LSB
}

void WriteLCD(unsigned char word) {
    RS = 1;
    LCD(word >> 4);
    LCD(word & 0x0F);
}

void LCD(unsigned char data) { //Opción bits
    E = 1;
    __delay_us(time);
    LATD = data;
    __delay_us(time);
    E = 0;
    __delay_us(time);
}

void settings(void) {
    OSCCON = 0x72;
    ADCON1 = 0x0F;
    //LCD
    TRISD = 0;
    TRISE = 0;
    LATD = 0;
    LATE = 0;
    SettingsLCD(0x02); //Iniciar la LCD con el método nibble (4 MSB y 4 LSB)
    SettingsLCD(EMS);
    SettingsLCD(DC);
    SettingsLCD(FS);
    SettingsLCD(CD);
    //Serial UART
    TRISCbits.TRISC6 = 0;
    TRISCbits.TRISC7 = 1;
    SPBRG = 0x0C;
    RCSTA = 0x90;
    TXSTA = 0x20;
    //Interrupción
    GIE = 1;
    PEIE = 1;
    RCIE = 1;
    RCIF = 0;
}

void __interrupt() RECEIVE(void) {
    if (RCIF == 1) {
        d = RCREG;
        data[k] = d;
        k++;
        if (data[k - 1] == 0x0D) {
            flag = 1;
            k = 0;
        }
    }
}