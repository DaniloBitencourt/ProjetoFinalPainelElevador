/* 
 * File:   main.c
 * Author: danil
 *
 * Created on 17 de Dezembro de 2021, 15:33
 */
#include "config.h"
#include "lcd.h"
#include "stdio.h"
#include <pic18f4520.h>
#include "bits.h"
#include "config.h"  
#include "io.h"
#include "so.h"
#include "delay.h"
#include "keypad.h"
#define ON 0x0F

static const char valor[] = {
    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D,
    0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C,
    0x39, 0x5E, 0x79, 0x71
};
static const char leds []= {0b00000001, 0b00000010,0b00000100,0b00001000};

void main(void){
    int andar = 1;
    TRISD = 0x00;
    PORTD = 0xFF;
    
    lcdInit();
    printf("Escolha o andar desejado\npelo teclado");//LCD pela biblioteca stdio
    
    
    pinMode(DISP_1_PIN, OUTPUT);
    soInit();
    kpInit();
    
    for(;;){ 
        soWrite(0x00);
        digitalWrite(DISP_1_PIN, HIGH);
        soWrite(valor[andar]);
        PORTD = leds[andar-1];
        atraso(5);
        
        kpDebounce();
        if (kpReadKey() != 0) {//Leitura do Teclado
                andar = kpRead();
                if(andar == 4){
                    andar = 3;
                }    
        }        
        if ((andar != 1) && (andar != 2) && (andar != 3)){
            andar = 4;
        }
    }
}