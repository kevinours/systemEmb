
#include "heat.h"
#include "config.h"

void main(void) {

    TRISC = 0b00000011;
    change_heat();
    for (int i = 0; i < 10; i++) {
        watch_heat();
        __delay_ms(500);
    }
    return;
}
