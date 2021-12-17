#include "lcd.h"
void printf(char msg[34]){
    int i; 
    for(i=0; i<40; i++){
        if(msg[i] == '\0'){
            return;
        }
        else if(msg[i] == '\n'){
            lcdCommand(0xC0);
        }
        else{
            lcdChar(msg[i]);
        }
    }
}