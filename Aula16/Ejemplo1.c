#include <xc.h>
#include <stdio.h>
#include <string.h>

#pragma config FOSC = INTIO67
#pragma config WDTEN = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 16000000
#define time 10
//LCD
#define CD 0x01
#define RH 0x02
#define EMS 0x06
#define DC 0x0F
#define DSr 0x1C
#define DSl 0x18
#define FS 0x38
#define RAW1 0x80 //0b1000 0000
#define RAW2 0xC0 //0b1100 0000
#define E LATE0
#define RS LATE1

void settings(void);
//LCD
void SettingsLCD(unsigned char word);
void LCD(unsigned char data);
void WriteLCD(unsigned char word);
void DisplayShiftRight(void);
void DisplayShiftLeft(void);
void __interrupt() LCD_int(void);
void PrintDataLCD(void);

char name[6]={'F','A','B','I','A','N'}, surname[]="BARRERA";
int i, flag = 0;

void main(void) {
    settings();
    while(1){
        if(flag){
            PrintDataLCD();
            DisplayShiftRight();
            DisplayShiftLeft();
            flag = 0;
        }
    }
}

void settings(void){
    OSCCON = 0x72;
    ANSELB = 0x00;
    ANSELD = 0x00;
    ANSELE = 0x00;
    TRISB = 0x01;
    TRISD = 0;
    TRISE = 0;
    LATB = 0;
    LATD = 0;
    LATE = 0;
    //LCD
    SettingsLCD(EMS);
    SettingsLCD(DC);
    SettingsLCD(FS);
    SettingsLCD(CD);
    //Interrupción externa 2
    GIE = 1;
    INT0IE = 1;
    INT0IF = 0;
    INTEDG0 = 0;
}

void SettingsLCD(unsigned char word){
    RS = 0;
    LCD(word);
}

void WriteLCD(unsigned char word){
    RS = 1;
    LCD(word);
}

void LCD(unsigned char data){
    E = 1;
    __delay_ms(time);
    LATD = data;
    __delay_ms(time);
    E = 0;
    __delay_ms(time);
}

void __interrupt() LCD_int(void){
    if(INT0IF == 1){
        __delay_ms(time*10);
        INT0IF = 0;
        flag = 1;
    }
}

void PrintDataLCD(void){
    SettingsLCD(RAW1+4);
    for(i=0; i<=strlen(name); i++){
        WriteLCD(name[i]);
    }
    SettingsLCD(RAW2+2);
    for(i=0; i<=strlen(surname); i++){
        WriteLCD(surname[i]);
    }
}

void DisplayShiftRight(void){
    for(i=0; i<=3; i++){
        SettingsLCD(DSr);
        __delay_ms(time*10);
    }
}

void DisplayShiftLeft(void){
    for(i=0; i<=3; i++){
        SettingsLCD(DSl);
        __delay_ms(time*10);
    }
}