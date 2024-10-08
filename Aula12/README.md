<h1>Aula 12</h1>

Esta clase consiste en comprender las interrupciones como tareas imprevistas en un microcontrolador.

<h2>Interrupciones</h2>

Las interrupciones son perturbaciones de la operación normal del programa principal, siendo que la ejecución de la instrucción actual se detiene por un aviso provocado por un módulo del PIC (entradas digitales INTx, temporizadores TMRx, comunicación serial Rx y Tx, ADC, Rutinas de Servicio de Interrupciones (ISRs)).

Bits de las interrupciones:

- IE (Interrupt Enable): Determina si la interrupción está o no habilitada.
- IF (Interrupt Flag): Indica si la condición de la interrupción se ha cumplido.
- IP (Interrupt Priority): Indica si la prioridad de la interrupción es alta (1) o baja (0).

Los registros INTCON son de escritura y lectura, los cuales contienen bits de habilitación, prioridad y flags para las interrupciones.

<div align="center">
<img src="Imagenes/image.png" alt="INTx"/>
<br>
<figcaption>Fuente: Datasheet PIC 18F4550</figcaption>
</div>

<h3>INTCON</h3>

<div align="center">
<img src="Imagenes/image-1.png" alt="INTCON"/>
<br>
<figcaption>Fuente: Datasheet PIC 18F4550</figcaption>
</div>

<div align="center">
<img src="Imagenes/image-2.png" alt="bits INTCON"/>
<br>
<figcaption>Fuente: Datasheet PIC 18F4550</figcaption>
</div>

<h3>INTCON2</h3>

<div align="center">
<img src="Imagenes/image-3.png" alt="INTCON2"/>
<br>
<figcaption>Fuente: Datasheet PIC 18F4550</figcaption>
</div>

<div align="center">
<img src="Imagenes/image-4.png" alt="bits INTCON2"/>
<br>
<figcaption>Fuente: Datasheet PIC 18F4550</figcaption>
</div>

<h3>INTCON3</h3>

<div align="center">
<img src="Imagenes/image-5.png" alt="INTCON3"/>
<br>
<figcaption>Fuente: Datasheet PIC 18F4550</figcaption>
</div>

<div align="center">
<img src="Imagenes/image-6.png" alt="bits INTCON3"/>
<br>
<figcaption>Fuente: Datasheet PIC 18F4550</figcaption>
</div>

<h3>Ejercicio 1</h3>

Utilizar un pulsador como contador para encender 8 leds, los cuales deben mostrar el número binario del contador, a través de una interrupción con flanco de bajada (Pull Up) en el pin INT0 del PIC 18F4550, mientras que un led en otro puerto enciende y apaga con un tiempo de 0.1s.

<div align="center">
<img src="Imagenes/image-7.png" alt="Ejercicio 1"/>
<br>
<figcaption>Fuente: Autor</figcaption>
</div>

```c
/*
PIC 18F4550
Interrupciones externas
Author: Fabián Barrera Prieto
Mestrado em Sistemas Mecatrônicos
Created on 8 de Setembro de 2020, 07:02
 */

#include <xc.h>

#pragma config FOSC = INTOSC_HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ 8000000

void settings(void);
void start(void);
void __interrupt() contador(void);

unsigned char cont = 0;

void main(void) {
    settings();
    while (1) {
        start();
    }
}

void __interrupt() contador(void) {
    if (INT0IF == 1) {
        __delay_ms(100);
	INT0IF = 0;
        cont++; //cont = cont + 1; cont += 1;
        /*if (cont == 256) { //Para cont de tipo int
            cont = 0;
        }*/
        LATD = cont;
    }
}

void settings(void) {
    OSCCON = 0x72;
    ADCON1 = 0x0F;
    TRISB = 0x0F;
    TRISD = 0x00;
    LATB = 0x00;
    LATD = 0x00;
    //Interrupción externa 0
    GIE = 1;
    INT0IE = 1;
    INT0IF = 0;
    INTEDG0 = 0;
}

void start(void) {
    //SLEEP();
    LATBbits.LB4 = 1;
    __delay_ms(100);
    LATBbits.LB4 = 0;
    __delay_ms(100);
}
```