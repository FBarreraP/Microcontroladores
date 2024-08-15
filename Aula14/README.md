<h1>Aula 14</h1>

Esta clase consiste en comprender las conexiones y las visualización dinámica de una matriz de leds de 8x8, de ánodo y cátodo común.

<h2>Matriz de leds 8x8</h2>

Las matrices de leds son arreglos de 64 leds, los cuales se conectan en 8 filas y 8 columnas, a través de cátodos o ánodos comunes.

<div align="center">
<img src="image.png" alt="Matriz de leds 8x8"/>
<br>
<figcaption>Fuente: https://programarfacil.com/blog/arduino-blog/matriz-led-arduino-max7219/</figcaption>
<br>
</div>

<h3>Ánodo/Cátodo común</h3>

<div align="center">
<img src="image-1.png" alt="Matriz de leds Ánodo/Cátodo común"/>
<br>
<figcaption>Fuente: https://hetpro-store.com/TUTORIALES/matriz-leds-atmega-8/</figcaption>
<br>
</div>

<h3>Cátodo común</h3>

Si aplican +5V y 0V en diferentes columnas y filas, respectivamente, se encenderán todos los leds que se intersecan en dichas columnas y filas.

<div align="center">
<img src="image-2.png" alt="Matriz de leds Cátodo común"/>
<br>
<figcaption>Fuente: https://programarfacil.com/blog/arduino-blog/matriz-led-arduino-max7219/</figcaption>
<br>
</div>

Para mostrar figuras en las matrices de leds es necesario realizar un barrido por columnas o filas, es decir, solo se encenderá una columna o fila a la vez, los cual es conocido como visualización dinámica.

<div align="center">
<img src="image-3.png" alt="Visualización dinámica matriz de leds Cátodo común"/>
<br>
<figcaption>Fuente: https://programarfacil.com/blog/arduino-blog/matriz-led-arduino-max7219/</figcaption>
<br>
</div>

<h3>MAX7219</h3>

El MAX 7219 es un driver de salidas digitales para displays de 7 segmentos y matrices de leds de cátodo común, el cual utiliza SPI.

<div align="center">
<img src="image-4.png" alt="MAX7219"/>
<br>
<figcaption>Fuente: https://programarfacil.com/blog/arduino-blog/matriz-led-arduino-max7219/</figcaption>
<br>
</div>

<div align="center">
<img src="image-5.png" alt="3 x MAX7219"/>
<br>
<figcaption>Fuente: https://programarfacil.com/blog/arduino-blog/matriz-led-arduino-max7219/</figcaption>
<br>
</div>

<div align="center">
<img src="image-6.png" alt="Circuito electrónico 3 x MAX7219"/>
<br>
<figcaption>Fuente: https://programarfacil.com/blog/arduino-blog/matriz-led-arduino-max7219/</figcaption>
<br>
</div>

<h3>Ejercicio 1</h3>

<div align="center">
<img src="image-7.png" alt="Ejercicio 1"/>
<br>
<figcaption>Fuente: Autor</figcaption>
<br>
</div>