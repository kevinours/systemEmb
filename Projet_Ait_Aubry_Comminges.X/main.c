
#include "heat.h"
#include "config.h"

void main(void) {
    
    TRISC = 0b00000011;
    change_heat();
    watch_heat();
    return;
}
