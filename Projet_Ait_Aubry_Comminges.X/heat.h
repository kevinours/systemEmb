
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#ifndef CONFIG_BITS_H
#define CONFIG_BITS_H

// CONFIG
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF // FLASH Program Memory Code Protection bits
#pragma config BOREN = ON // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low Voltage In-Circuit Serial Programming Enable bit
#pragma config CPD = OFF // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = ON // FLASH Program Memory Write Enable

#endif /* CONFIG_BITS_H */

#include <xc.h>
#include "pic16f877.h"

volatile float tension = 0.0f;
volatile float temp;

#define _XTAL_FREQ 4000000 // clock 4Mhz
#define VREF_plus 5.0f // vref + = Vcc tension d'alimentation
#define VREF_moins 0.0f // vref - = 0V
#define PLEINE_ECH 1024 // convertisseur 10 bits. pleine echelle = 2^10 = 1024

void watch_heat(void);

#endif	/* XC_HEADER_TEMPLATE_H */

