#include "heat.h"

void change_heat(void) {
    TRISC = 0b00000011; // 
    if (RC0 == 0) {
        if(temp_cible >= 26){
            temp_cible -=4;
        }
    }
    if (RC1 == 0) { 
        if(temp_cible <= 34){
            temp_cible +=4;
        }
    }
}

void check_heat(float temp) {
    TRISD = 0b00000000; // 
    if(temp > temp_cible +1 ){
        RD0 = 1;
        RD1 = 0;
    }
    if(temp <= temp_cible +0.3 || temp <= temp_cible +0.3){
        RD0 = 0;
        RD1 = 0;
    }
    if(temp < temp_cible -1){
        RD0 = 0;
        RD1 = 1;
    }
}

void watch_heat(void) {
    unsigned long ValeurADC = 0L;

    TRISA = 0xFF; //port A tout en entree doc p 111
    ADCON1 = 0b10001110; // right justified vref+=Vdd vref- = Vss RA0 an autres entrées digitales doc p 112
    ADCON0 = 0b01000001; // Fosc/8 RA0 stop x AD on
    ADCON0bits.GO_DONE = 1; // lancer laconversion
    while (ADCON0bits.GO_DONE == 1); // attente fin de conversion
    ValeurADC = ADRESH << 8; // lecture valeur convertie MSB
    ValeurADC += ADRESL; // + LSB => valeur 16 bits
    tension = (VREF_plus - VREF_moins) * ValeurADC / PLEINE_ECH; // calcul de la tension
    temp = (tension * 8) + 10;
    light(temp_cible);
    change_heat();
    check_heat(temp);
    

}

void light(float temp) {
    if (temp == 22 ) {
        RC4 = 0;
        RC5 = 0;
        RC6 = 0;
        RC7 = 0;

        RC3 = 1;
    }
    if (temp == 26) {
        RC3 = 0;
        RC5 = 0;
        RC6 = 0;
        RC7 = 0;

        RC4 = 1;
    }
    if (temp == 30 ) {
        RC3 = 0;
        RC4 = 0;
        RC6 = 0;
        RC7 = 0;

        RC5 = 1;
    }
    if (temp == 34) {
        RC3 = 0;
        RC4 = 0;
        RC5 = 0;
        RC7 = 0;

        RC6 = 1;
    }
    if (temp == 38) {
        RC3 = 0;
        RC4 = 0;
        RC5 = 0;
        RC6 = 0;

        RC7 = 1;
    }
}
