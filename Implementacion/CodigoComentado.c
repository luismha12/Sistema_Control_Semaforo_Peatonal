// Código comentado del sistema de semáforo peatonal

#include <xc.h>

#pragma config FOSC = XT, WDTE = OFF, PWRTE = OFF, BOREN = ON, LVP = OFF, CPD = OFF, WRT = OFF, CP = OFF
#define _XTAL_FREQ 4000000

#define LED_ROJO_AUTO     RC0
#define LED_AMARILLO_AUTO RC1
#define LED_VERDE_AUTO    RC2
#define LED_ROJO_PEATON   RC3
#define LED_VERDE_PEATON  RC4
#define BUZZER            RC5
#define BOTON             RB0

void apagarLuces() {
    LED_ROJO_AUTO = 0;
    LED_AMARILLO_AUTO = 0;
    LED_VERDE_AUTO = 0;
    LED_ROJO_PEATON = 0;
    LED_VERDE_PEATON = 0;
    BUZZER = 0;
}

void cicloVehicular() {
    LED_ROJO_PEATON = 1; // Peatón no puede cruzar

    LED_ROJO_AUTO = 0;
    LED_VERDE_AUTO = 1;
    __delay_ms(5000);

    LED_VERDE_AUTO = 0;
    LED_AMARILLO_AUTO = 1;
    __delay_ms(2000);

    LED_AMARILLO_AUTO = 0;
    LED_ROJO_AUTO = 1;
    __delay_ms(3000);
}

void cicloPeatonal() {
    LED_VERDE_AUTO = 0;
    LED_AMARILLO_AUTO = 0;
    LED_ROJO_AUTO = 1; // Detener autos

    LED_ROJO_PEATON = 0;
    LED_VERDE_PEATON = 1; // Permitir paso
    __delay_ms(4000);

    for (int i = 0; i < 4; i++) {
        BUZZER = 1;
        __delay_ms(200);
        BUZZER = 0;
        __delay_ms(200);
    }

    LED_VERDE_PEATON = 0;
    LED_ROJO_PEATON = 1;
    __delay_ms(1000);
}

void main(void) {
    TRISC = 0x00;
    TRISB = 0x01;
    PORTC = 0x00;
    PORTB = 0x00;

    while (1) {
        if (BOTON == 1) {
            __delay_ms(50);
            if (BOTON == 1) {
                cicloPeatonal();
            }
        }
        cicloVehicular();
    }
}
