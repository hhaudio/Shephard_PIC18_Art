/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.0
        Device            :  PIC18F27Q43
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/
#define __OPTIMIZE_SPEED__

#include "mcc_generated_files/mcc.h"
#include "CosineTables.h"

/*
                         Main application
 */

//uint32_t incr;
uint32_t freq;
uint32_t index;
uint32_t potVal;
uint16_t ind[8] = {};
uint16_t out;
uint16_t top;
uint16_t bot;

//uint16_t potIncr[4] = {0, 0, 0, 0};
//uint16_t incr[4] = {0, 0, 0, 0};

uint16_t incr[2][8] = {};

uint8_t potFlag = 0;
uint8_t potArray = 0;

uint32_t freqCounter = 0;
uint32_t temp;
uint16_t freqIncr;

uint32_t clockCounter = 1;
uint8_t cm1 = 0;
uint8_t cm2 = 0;
uint32_t counterSave = 1;
uint32_t clockVal = 0;

#define DEL_LEN 400
#define DEL_SHIFT 2

uint16_t topDel[DEL_LEN] = {};
uint16_t botDel[DEL_LEN] = {};
uint16_t delCounter = 0;
uint16_t botCounter = 0;
uint8_t whichDel = 0;

uint8_t test = 10;

uint16_t last = 0;

uint8_t shift1 = 0;
uint8_t shift2 = 0;

uint16_t mask1 = 0;
uint8_t mask2 = 0;

#define INDMOD 8192
#define INDMASK 8191
#define INDSHIFT 3

uint16_t decay = 0;
uint8_t ledOff = 0;
uint8_t dacOff = 0;

const uint8_t maskB[9] = {0, 0, 0, 0, 0B1, 0B10, 0B100, 0B1000, 0B10000};
const uint8_t maskC1[9] = {0B00010000, 0B00100000, 0B01000000, 0B10000000, 0, 0, 0, 0, 0};
const uint8_t maskC2[7] = {0, 0, 0, 0B1, 0B10, 0B100, 0B1000};
const uint8_t maskA[7] = {0B00100000, 0B10000000, 0B01000000, 0, 0, 0, 0};

uint8_t compare = 0;
uint8_t lastCompare = 0;

void doAudio(){

    if(potFlag){
        freqIncr = clockVal;
        potArray = !potArray;
        potFlag = 0;
    }
    
    ind[0] += incr[potArray][0];
    if(ind[0] > INDMOD){ ind[0] -= INDMOD; }
    
    ind[1] += incr[potArray][1];
    if(ind[1] > INDMOD){ ind[1] -= INDMOD; }
    
    ind[2] += incr[potArray][2];
    if(ind[2] > INDMOD){ ind[2] -= INDMOD; }
    
    ind[3] += incr[potArray][3];
    if(ind[3] > INDMOD){ ind[3] -= INDMOD; }
    
    ind[4] += incr[potArray][4];
    if(ind[4] > INDMOD){ ind[4] -= INDMOD; }
    
    ind[5] += incr[potArray][5];
    if(ind[5] > INDMOD){ ind[5] -= INDMOD; }
    
    ind[6] += incr[potArray][6];
    if(ind[6] > INDMOD){ ind[6] -= INDMOD; }
    
    ind[7] += incr[potArray][7];
    if(ind[7] > INDMOD){ ind[7] -= INDMOD; }
    

    top = (cosTab[ind[0] >> INDSHIFT] + cosTab[ind[2] >> INDSHIFT] + cosTab[ind[4] >> INDSHIFT] + cosTab[ind[6] >> INDSHIFT]
            + cosTab[ind[1] >> INDSHIFT] + cosTab[ind[3] >> INDSHIFT] + cosTab[ind[5] >> INDSHIFT] + cosTab[ind[7] >> INDSHIFT]) >> 1;
     
    top += (topDel[delCounter]) >> 1;
    topDel[delCounter] = top;
    
    top += (botDel[botCounter]) >> 1;
    botDel[botCounter] = top;
    
    delCounter++;
    if(delCounter >= DEL_LEN){ delCounter = 0; }
    botCounter++;
    if(botCounter >= 247){ botCounter = 0; }
        
    if(freqCounter < freqIncr){
        freqCounter += ((uint32_t)4096 << 16);
    }
    freqCounter -= freqIncr;
    
    clockCounter++;
    
    if(CM1CON0bits.C1OUT && !cm1){
        counterSave = clockCounter;
        clockCounter = 1;
        shift2++;
        if(shift2 == 7){ shift2 = 0; }
    }
    
//    compare = (freqCounter >> 16) & 0B00000111;
////    if(lastCompare < compare){
////        shift1 = (shift1 + 1) % 9;
////    }
//    shift1 += (lastCompare < compare);
//    if(shift1 == 9){ shift1 = 0; }
//
//    lastCompare = compare;
   
        
    if(!dacOff){
        DAC1DATL = (top >> 8) & 255;
    }
    
    cm1 = CM1CON0bits.C1OUT;
    
    LATBbits.LATB5 = CM1CON0bits.C1OUT;
    
}

uint32_t expScale;
uint16_t bitMask = 1;
uint16_t lastTemp = 0;
uint32_t LEDs = 0;
uint8_t stop = 0;

//uint32_t lastTemp;
uint8_t shiftCount = 0;

void readPot(){
    
//    if(!ledOff){
//        LATB = maskB[shift1];
//        LATC = maskC1[shift1] | maskC2[shift2];
//        LATA = maskA[shift2];
//    }else{
//        LATB = 0;
//        LATC = 0;
//        LATA = 0;
//    }
//    LATBbits.LATB5 = CM1CON0bits.C1OUT;
    
    mask1 = (1 << shift1);
    mask2 = (1 << shift2);
    
    if(ledOff){
        mask1 = mask2 = 0;
    }
    
    LATB = CM1CON0bits.C1OUT << 5;
    LATB |= (mask1 >> 4) & 0B00011111;
    LATC = ((mask1 & 0B00001111) << 4) | ((mask2 & 0B01111000) >> 3);
    LATAbits.LATA6 = (mask2 == 0B00000100);
    LATAbits.LATA7 = (mask2 == 0B00000010);
    LATAbits.LATA5 = (mask2 == 0B00000001);
    
    if(ADCC_IsConversionDone()){   
        uint32_t temp1 = ADCC_GetConversionResult();
        temp1 = (temp1 * temp1) >> 12;
        temp1 = (temp1 * temp1) >> 12;
        temp1 = (temp1 * temp1) >> 12;
        temp1 = temp1 >> 1;
        potVal = temp1 + 10;
        NCO1INCU = 0;
        NCO1INCH = (potVal >> 8) & 0B00001111;
        NCO1INCL = (potVal) & 0B11111111;
        
        
        ADCC_StartConversion(channel_ANA0);
    }
    if(!potFlag){
        
//        uint32_t rand1 = rand() % 10000;
//        uint32_t rand2 = rand() % 10000;
//        if(rand2 > rand1){
//            rand1 = rand2;
//        }
        if(CM2CON0bits.C2OUT && !cm2){
            decay++;
        }   
        cm2 = CM2CON0bits.C2OUT;
        
        if(decay > (rand() % 20000)){
            ledOff = 1;
            dacOff = 1;
        }else{
            dacOff = 0;
            ledOff = 0 + CM2CON0bits.C2OUT;
//            DAC1DATL = (top >> 8) & 255;/
        }
        
        temp = freqCounter >> 16;
        for(int i = 0; i < 8; ++i){
            expScale = (temp + 512 * i) % 4096;
//            expScale = (expScale * expScale * expScale) >> 20;
            expScale = (expScale * expScale) >> 12;
//            expScale = (expScale * expScale) >> 10;
            incr[!potArray][i] = expScale + 20;
        }
        
        temp = temp % 8;
        if(lastTemp < temp){
            shift1 = (shift1 + 1) % 9;
        }
            
        lastTemp = temp;
//        
//        bitMask = 1 << shiftCount;
//        
//        LATB = (bitMask >> 3) & 0B00111111;
//        LATC = (bitMask & 0B00000111) << 5;
        
//        if(!((temp >> 4) % 9)){ if(!stop){bitMask++;} stop = 1;}
//        else{ stop = 0; }
//        if(bitMask >= 255){ bitMask = 1; }
//        LEDs = 0;
        
//        LEDs = bitMask << ((temp >> 4) % 9);
//        LEDs |= (LEDs >> 9);
        
//        LATC = 0;
//        LATC = (LEDs << 4) & 0B11110000;
//        LATB = (LEDs >> 4) & 0B00011111;
         
//        LATC = (1 << ((temp % 128) >> 4)) ;
//        LATC = 0B11000000;
//        LATC = 1 << ((potVal % 128) >> 4);
        
        clockVal = (1280000 / counterSave);
        
        potFlag = 1;
    }
}

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    TMR1_SetInterruptHandler(doAudio);
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    while (1)
    {
        readPot();
        // Add your application code
    }
}