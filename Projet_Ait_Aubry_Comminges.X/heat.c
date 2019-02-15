#include "heat.h"


void change_heat(void) {
    TRISC = 0b00000011; // 
    __delay_ms(500);
    if(RC0 == 1)
    {
        __delay_ms(500);
    }
    if(RC1 == 1)
    {
        __delay_ms(500);
    }
}
void watch_heat(void) {
    unsigned long ValeurADC = 0L;

    TRISA = 0xFF; //port A tout en entree doc p 111
    ADCON1 = 0b10001110; // right justified vref+=Vdd vref- = Vss RA0 an autres entrées digitales doc p 112
    ADCON0 = 0b01000001; // Fosc/8 RA0 stop x AD on
    __delay_us(100);
    while (1) {
        ADCON0bits.GO_DONE = 1; // lancer laconversion
        while (ADCON0bits.GO_DONE == 1); // attente fin de conversion
        ValeurADC = ADRESH << 8; // lecture valeur convertie MSB
        ValeurADC += ADRESL; // + LSB => valeur 16 bits
        tension = (VREF_plus - VREF_moins) * ValeurADC / PLEINE_ECH; // calcul de la tension
        temp = (tension * 8) + 10;
        heat = temp;
        light(temp);
        __delay_ms(500);
    }

}

void light(float temp){
    if(temp >=22 && temp<26 ){
        RC4 = 0;
        RC5 = 0;
        RC6 = 0;
        RC7 = 0;
        
        RC3= 1;
    }
    if(temp >=26 && temp<30 ){
        RC3 = 0;
        RC5 = 0;
        RC6 = 0;
        RC7 = 0;
        
        RC4= 1;
    }
    if(temp >=30 && temp<34 ){
        RC3 = 0;
        RC4 = 0;
        RC6 = 0;
        RC7 = 0;
        
        RC5= 1;
    }
    if(temp >=34 && temp<38 ){
        RC3 = 0;
        RC4 = 0;
        RC5 = 0;
        RC7 = 0;
        
        RC6= 1;
    }
    if(temp == 38 ){
        RC3 = 0;
        RC4 = 0;
        RC5 = 0;
        RC6 = 0;
        
        RC7= 1;
    }
}
