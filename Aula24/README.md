<h1>Aula 24</h1>

Esta clase consiste en comprender los temporizadores en el PIC 18F4550

<h2>Temporizadores</h2>

Los temporizadores en un microcontrolador son controlados por software para generar atrasos (delays), conteo de eventos, generación de señales cuadradas (PWM). El PIC 18F4550 cuenta con 4 temporizadores internos (TMR0, TMR1, TMR2 y TMR3), los cuales pueden ser configurados a 8 o 16 bits.

<h3>Temporizadores en el PIC 18F4550</h3>

Para configurar los temporizadores como interrupciones en el PIC18F4550 es necesario tener en cuenta los siguientes pasos:

1. Habilitar la interrupción del (los) temporizador(es) a través de los bits GIE, PEIE y TMRxIE.
2. Configurar el temporizador a través del registro TxCON.
3. Cargar el valor inicial del contador en el registro TMRx.
4. Configurar el TMRxON para comenzar la operación del temporizador.

<h4>Paso 1 - Registro PIE1</h4>

<div align="center">
<img src="Imagenes/image.png" alt="PIE1"/>
<br>
<figcaption>Fuente: Datasheet PIC 18F4550</figcaption>
</div>

<div align="center">
<img src="Imagenes/image-1.png" alt="bits PIE1"/>
<br>
<figcaption>Fuente: Datasheet PIC 18F4550</figcaption>
</div>

<div align="center">
<img src="Imagenes/image-2.png" alt="PIR1"/>
<br>
<figcaption>Fuente: Datasheet PIC 18F4550</figcaption>
</div>

<div align="center">
<img src="Imagenes/image-1.png" alt="bits PIR1"/>
<br>
<figcaption>Fuente: Datasheet PIC 18F4550</figcaption>
</div>

<h4>Paso 2 - Registro T1CON</h4>

<div align="center">
<img src="Imagenes/image-4.png" alt="T1CON"/>
<br>
<figcaption>Fuente: Datasheet PIC 18F4550</figcaption>
</div>

<div align="center">
<img src="Imagenes/image-5.png" alt="bits T1CON"/>
<br>
<figcaption>Fuente: Datasheet PIC 18F4550</figcaption>
</div>

<h4>Paso 3 - TMR1</h4>

El valor de TMR1 (16 bits) se compone de dos registros TMR1H Y TMR1L, cada uno de 8 bits. El TMR1 permite configurar el valor inicial del conteo que realiza el temporizador.

<div align="center">
<img src="Imagenes/image-6.png" alt="Delays con prescalers"/>
<br>
<figcaption>Fuente: Datasheet PIC 18F4550</figcaption>
</div>

El valor del registro TMR1 se puede calcular con respecto al tiempo de atraso (delay) requerido. Por ejemplo, se desea obtener 5ms de atraso con el temporizador.

<div align="center">
<img src="Imagenes/image-7.png" alt="Cálculo de TMR1"/>
<br>
<figcaption>Fuente: Datasheet PIC 18F4550</figcaption>
</div>

<div align="center">
<img src="Imagenes/image-8.png" alt="Overflow TMR1"/>
<br>
<figcaption>Fuente: Adaptado de https://www.electronicwings.com/pic/pic18f4550-timer </figcaption>
</div>

<h3>Ejemplo 1</h3>

Utilizar el temporizador TMR1 como interrupción en el PIC 18F4550 para generar una señal cuadrada con el tiempo máximo del temporizador teniendo un valor de prescaler de 1, así mismo, la salida de la señal debe ser visualizada en 8 leds conectados al puerto D.

<div align="center">
<img src="Imagenes/image-9.png" alt="Ejemplo1"/>
<br>
<figcaption>Fuente: Autor </figcaption>
</div>

```c
/*
PIC 18F4550
TIMER1
Author: Fabián Barrera Prieto
Mestrado em Sistemas Mecatrônicos
Created on 25 de Novembro de 2020, 06:34
 */

#include <xc.h>

#pragma config FOSC = INTOSC_HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 8000000
#define time 10
//TIMER
#define Prescale1_4 0xB0
#define Prescale1_3 0xA0
#define Prescale1_2 0x90
#define Prescale1_1 0x80

void settings(void);
void start(void);
void __interrupt() TMR1_pre(void);

void main(void) {
    settings();
    while(1){

    }
}

void settings(void){
    OSCCON = 0x72;
    ADCON1 = 15;
    TRISD = 0;
    LATD = 0;
    //Habilitação da interrupção do TIMER 1
    GIE = 1;
    PEIE = 1;
    TMR1IE = 1;
    TMR1IF = 0;
    //Configuração do TIMER1
    T1CON = Prescale1_1;
    TMR1 = 0;
    TMR1ON = 1;
}

void __interrupt() TMR1_pre(void){
    if(TMR1IF == 1){
        TMR1 = 0;
        LATD = ~LATD;
        TMR1IF = 0;
    }
}
```

<h3>Ejemplo 2</h3>

Utilizar el temporizador TMR1 como interrupción en el PIC 18F4550 para generar una señal cuadrada con un tiempo establecido de 5ms, la salida de la señal debe ser visualizada en 8 leds conectados al puerto D.

<div align="center">
<img src="Imagenes/image-9.png" alt="Ejemplo2"/>
<br>
<figcaption>Fuente: Autor </figcaption>
</div>

```c
/*
PIC 18F4550
TIMER1
Author: Fabián Barrera Prieto
Mestrado em Sistemas Mecatrônicos
Created on 25 de Novembro de 2020, 06:34
 */

#include <xc.h>

#pragma config FOSC = INTOSC_HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 8000000
#define time 10
//TIMER
#define Prescale1_4 0xB0
#define Prescale1_3 0xA0
#define Prescale1_2 0x90
#define Prescale1_1 0x80


void settings(void);
void start(void);
void __interrupt() TMR1_ISR(void);

void main(void) {
    settings();
    while(1){

    }
}

void settings(void){
    OSCCON = 0x72;
    ADCON1 = 15;
    TRISD = 0;
    LATD = 0;
    //Habilitação da interrupção do TIMER 1
    GIE = 1;
    PEIE = 1;
    TMR1IE = 1;
    TMR1IF = 0;
    //Configuração do TIMER1
    T1CON = Prescale1_1;
    TMR1 = 0xD8EF;
    TMR1ON = 1;
}

void __interrupt() TMR1_ISR(void){
    if(TMR1IF == 1){
        TMR1 = 0xD8EF;
        LATD = ~LATD;
        TMR1IF = 0;
    }
}
```