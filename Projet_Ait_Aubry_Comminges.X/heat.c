#include "heat.h"

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
        __delay_ms(500);
    }

}
