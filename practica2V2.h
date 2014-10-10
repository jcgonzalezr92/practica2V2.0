#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4MHz)
#use rs232(baud=9600,parity=N,bits=8,stream=PORT1)

#use pwm(CCP1,TIMER=2,FREQUENCY=38000,DUTY=50)

