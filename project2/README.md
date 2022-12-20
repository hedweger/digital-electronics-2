# Project 2

Precise generation of several PWM channels. Application of two (or more) Servo motors SG90.

### Team members

* Tomáš Hadwiger
* Petr Vaněk

## Hardware description

Jako platformu využíváme Arduino Uno. Piny 9 a 10 jsou využity jako PWM výstupy pro ovládání servo motorků, piny A0 a A1 jako analogové vstupy pro určení polohy joysticky.  

![your figure](schema.png)

## Software description

[**timer.h**](/include/timer.h) - pro generování interruptů používáme 16ms časovač, definováný v knihovně timer.h

[**main.c**](/src/main.c) - hlavní soubor našeho programu

## Video

[Ukázka funkce v simulaci (odkaz na YouTube video)](https://youtu.be/Qu-rFiBgfe8)

## References

1. [atmega328p datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf)
2. [princip servo motoru](https://navody.dratek.cz/arduino-projekty/servo-motor.html?gclid=Cj0KCQiA14WdBhD8ARIsANao07ifRruf_l1Q9S53Kcy6BkveMnA-QAOAwEd9ykN7mnKZPWH7Ini-VLsaAk2rEALw_wcB)
