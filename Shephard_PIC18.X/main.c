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


uint16_t ind[8] = {};
uint16_t incr[2][8] = {};

uint16_t out;
uint16_t top;

uint32_t potVal;
uint8_t potFlag = 0;
uint8_t potArray = 0;

uint32_t freqCounter = 0;
uint16_t freqIncr;

uint32_t temp;
uint32_t expScale;

uint32_t clockCounter = 1;
uint32_t counterSave = 1;
uint32_t clockVal = 0;
uint8_t cm1 = 0;
uint8_t cm2 = 0;

#define DEL_LEN 400

uint16_t topDel[DEL_LEN] = {};
uint16_t botDel[DEL_LEN] = {};
uint16_t delCounter = 0;
uint16_t botCounter = 0;

uint8_t shift1 = 0;
uint8_t shift2 = 0;

#define INDMOD 8192
#define INDMASK 8191
#define INDSHIFT 3

uint32_t decay = 0;
uint8_t ledOff = 0;

const uint8_t maskB[9] = {0, 0, 0, 0, 0B1, 0B10, 0B100, 0B1000, 0B10000};
const uint8_t maskC1[9] = {0B00010000, 0B00100000, 0B01000000, 0B10000000, 0, 0, 0, 0, 0};
const uint8_t maskC2[7] = {0, 0, 0, 0B1, 0B10, 0B100, 0B1000};
const uint8_t maskA[7] = {0B00100000, 0B10000000, 0B01000000, 0, 0, 0, 0};

uint8_t compare = 0;
uint8_t lastCompare = 0;

uint8_t alt = 0;
uint8_t capture;
uint32_t decayCounter = 0;

void doAudio(){

    if(potFlag){
        freqIncr = clockVal;
        potArray = !potArray;
        potFlag = 0;
    }
    
//    ind[0] += incr[potArray][0];
//    if(ind[0] > INDMOD){ ind[0] -= INDMOD; }
//    
//    ind[1] += incr[potArray][1];
//    if(ind[1] > INDMOD){ ind[1] -= INDMOD; }
//    
//    ind[2] += incr[potArray][2];
//    if(ind[2] > INDMOD){ ind[2] -= INDMOD; }
//    
//    ind[3] += incr[potArray][3];
//    if(ind[3] > INDMOD){ ind[3] -= INDMOD; }
//    
//    ind[4] += incr[potArray][4];
//    if(ind[4] > INDMOD){ ind[4] -= INDMOD; }
//    
//    ind[5] += incr[potArray][5];
//    if(ind[5] > INDMOD){ ind[5] -= INDMOD; }
//    
//    ind[6] += incr[potArray][6];
//    if(ind[6] > INDMOD){ ind[6] -= INDMOD; }
//    
//    ind[7] += incr[potArray][7];
//    if(ind[7] > INDMOD){ ind[7] -= INDMOD; }
    
    ind[0] = (ind[0] + incr[potArray][0]) & INDMASK;
    ind[1] = (ind[1] + incr[potArray][1]) & INDMASK;
    ind[2] = (ind[2] + incr[potArray][2]) & INDMASK;
    ind[3] = (ind[3] + incr[potArray][3]) & INDMASK;
    ind[4] = (ind[4] + incr[potArray][4]) & INDMASK;
    ind[5] = (ind[5] + incr[potArray][5]) & INDMASK;
    ind[6] = (ind[6] + incr[potArray][6]) & INDMASK;
    ind[7] = (ind[7] + incr[potArray][7]) & INDMASK;

    top = (cosTab[ind[0]] + cosTab[ind[2]] + cosTab[ind[4]] + cosTab[ind[6]]
            + cosTab[ind[1]] + cosTab[ind[3]] + cosTab[ind[5]] + cosTab[ind[7]]) >> 1;
     
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
    
    capture = CM1CON0bits.C1OUT;
    
    if(capture && !cm1){
        counterSave = clockCounter;
        clockCounter = 1;
        shift2++;
        if(shift2 == 7){ shift2 = 0; }
    }
    cm1 = capture;
    
    capture = CM2CON0bits.C2OUT;
    if(capture && !cm2){
        decay++;
    }   
    cm2 = capture;
    ledOff |= cm2;
    
    compare = (freqCounter >> 16) & 0B00000111;
    
    shift1 += (lastCompare < compare);
    if(shift1 == 9){ shift1 = 0; }

    lastCompare = compare;
        
    if(!ledOff){
        DAC1DATL = (top >> 8) & 255;
        LATB = maskB[shift1] | (cm1 << 5);
        LATC = maskC1[shift1] | maskC2[shift2];
        LATA = maskA[shift2];
    }else{
        DAC1DATL = 0;
        LATB = (cm1 << 5);
        LATC = 0;
        LATA = 0;
    }
    
    decayCounter++;
    
//    LATAbits.LATA1 = alt;
//    alt = !alt;
    
}

void readPot(){
    
    if(decayCounter > 100){
        ledOff = (decay > (rand() % 50000));
        decayCounter = 0;
    }
    
    if(ADCC_IsConversionDone()){   
        
        uint32_t temp1 = ADCC_GetConversionResult() >> 1;
        temp1 = (temp1 * temp1) >> 11;
        temp1 = (temp1 * temp1) >> 11;
        potVal = temp1 + 10;
        
        NCO1INCU = 0;
        NCO1INCH = (potVal >> 8) & 0B00001111;
        NCO1INCL = (potVal) & 0B11111111;
        
        ADCC_StartConversion(channel_ANA0);
    }
    
    if(!potFlag){
        
        temp = freqCounter >> 16;
        for(int i = 0; i < 8; ++i){
            expScale = (temp + 512 * i) % 4096;
            expScale = (expScale * expScale) >> 12;
            incr[!potArray][i] = expScale + 20;
        }

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