/*
 * File:   main.c
 * Author: Alan Saucedo A01421445
 *
 * Created on 18 de noviembre de 2020, 03:12 PM
 */

#include "device_config.h"
#include <xc.h>


void portInit(){
    //PUERTO B0:3 outputs
    //PUERTO B4:7 inputs
    ANSELB = 0; //Se configura el puerto B como digital
    ANSELD = 0;//Se configura el puerto D como digital
    TRISB = 0b11110000; //El nibble superior del puerto B se configura como input y el inferior como output
    TRISD = 0b00000000; //Se configuran como outputs para los LED's
}

void main(void) {
    portInit();
    unsigned short columnas = 0;
    
    while(1){
        if (columnas < 3){
            columnas++;
        } else{
            columnas = 0;
        }
        
        switch(columnas){
            case 0: LATB |= 0x0E; break; //1110 Col-1  
            case 1: LATB |= 0x0D; break; //1101 Col-2 
            case 2: LATB |= 0x0B; break; //1011 Col-3 
            case 3: LATB |= 0x07; break; // 0111 Col-4 
            default : LATB &= 0x0; break; //0000
        }
        
        //PORTB=0b11101110, la tecla 1 se presionó
        if (PORTB == 0xEE){
            //Corrimiento de 4 bits a la izquierda para mostrar el nuevo valor
            LATD <<= 4;
            //Mediante el "Or" se asigna el valor de la tecla presionada
            LATD |= 0x01;
        } else if (PORTB == 0xDE){
            //PORTB=0b11011110, la tecla 4 se presionó
            //Corrimiento de 4 bits a la izquierda para mostrar el nuevo valor
            LATD <<= 4;
            //Mediante el "Or" se asigna el valor de la tecla presionada
            LATD |= 0x04;
        } else if (PORTB == 0xBE){
            //PORTB=0b10111110, la tecla 7 se presionó
            //Corrimiento de 4 bits a la izquierda para mostrar el nuevo valor
            LATD <<= 4;
            //Mediante el "Or" se asigna el valor de la tecla presionada
            LATD |= 0x07;
        } else if (PORTB == 0x7E){
            //PORTB=0b01111110, la tecla * se presionó
            //El * vale 0x0F
            //Corrimiento de 4 bits a la izquierda para mostrar el nuevo valor
            LATD <<= 4;
            //Mediante el "Or" se asigna el valor de la tecla presionada
            LATD |= 0x0F;
        } else if (PORTB == 0xED){
            //PORTB=0b11101101, la tecla 2 se presionó
            //Corrimiento de 4 bits a la izquierda para mostrar el nuevo valor
            LATD <<= 4;
            //Mediante el "Or" se asigna el valor de la tecla presionada
            LATD |= 0x02;
        } else if (PORTB == 0xDD){
            //PORTB=0b11011101, la tecla 5 se presionó
            //Corrimiento de 4 bits a la izquierda para mostrar el nuevo valor
            LATD <<= 4;
            //Mediante el "Or" se asigna el valor de la tecla presionada
            LATD |= 0x05;
        } else if (PORTB == 0xBD){
            //PORTB=0b10111101, la tecla 8 se presionó
            //Corrimiento de 4 bits a la izquierda para mostrar el nuevo valor
            LATD <<= 4;
            //Mediante el "Or" se asigna el valor de la tecla presionada
            LATD |= 0x08;
        } else if (PORTB == 0x7D){
            //PORTB=0b0111101, la tecla 0 se presionó
            //Corrimiento de 4 bits a la izquierda para mostrar el nuevo valor
            LATD <<= 4;
            //Mediante el "Or" se asigna el valor de la tecla presionada
            LATD |= 0x00;
        } else if (PORTB == 0xEB){
            //PORTB=0b11101011, la tecla 3 se presionó
            //Corrimiento de 4 bits a la izquierda para mostrar el nuevo valor
            LATD <<= 4;
            //Mediante el "Or" se asigna el valor de la tecla presionada
            LATD |= 0x03;
        } else if (PORTB == 0xDB){
            //PORTB=0b11011011, la tecla 6 se presionó
            //Corrimiento de 4 bits a la izquierda para mostrar el nuevo valor
            LATD <<= 4;
            //Mediante el "Or" se asigna el valor de la tecla presionada
            LATD |= 0x06;
        } else if (PORTB == 0xBB){
            //PORTB=0b10111011, la tecla 9 se presionó
            //Corrimiento de 4 bits a la izquierda para mostrar el nuevo valor
            LATD <<= 4;
            //Mediante el "Or" se asigna el valor de la tecla presionada
            LATD |= 0x09;
        } else if (PORTB == 0x7B){
            //PORTB=0b01111011, la tecla # se presionó
            //El # vale 0x0E
            //Corrimiento de 4 bits a la izquierda para mostrar el nuevo valor
            LATD <<= 4;
            //Mediante el "Or" se asigna el valor de la tecla presionada
            LATD |= 0x0E;
        } else if (PORTB == 0xE7){
            //PORTB=0b11100111, la tecla A se presionó
            //Corrimiento de 4 bits a la izquierda para mostrar el nuevo valor
            LATD <<= 4;
            //Mediante el "Or" se asigna el valor de la tecla presionada
            LATD |= 0x0A;
        } else if (PORTB == 0xD7){
            //PORTB=0b11010111, la tecla B se presionó
            //Corrimiento de 4 bits a la izquierda para mostrar el nuevo valor
            LATD <<= 4;
            //Mediante el "Or" se asigna el valor de la tecla presionada
            LATD |= 0x0B;
        } else if (PORTB == 0xB7){
            //PORTB=0b10110111, la tecla C se presionó
            //Corrimiento de 4 bits a la izquierda para mostrar el nuevo valor
            LATD <<= 4;
            //Mediante el "Or" se asigna el valor de la tecla presionada
            LATD |= 0x0C;
        } else if (PORTB == 0x77){
            //PORTB=0b01110111, la tecla D se presionó
            //Corrimiento de 4 bits a la izquierda para mostrar el nuevo valor
            LATD <<= 4;
            //Mediante el "Or" se asigna el valor de la tecla presionada
            LATD |= 0x0D;
        }    
        
    }
   
    
    return;
}