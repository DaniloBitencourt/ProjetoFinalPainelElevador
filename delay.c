#include "delay.h"

void atraso(unsigned char x) {
    volatile unsigned char j, k;
    volatile unsigned int i;
    
    for (i = 0; i < (x*25); i++) {        
        for (j = 0; j < 41; j++) {
            for (k = 0; k < 3; k++);
        }
    }
}

