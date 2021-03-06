#include <practica2V2.h>
short estadoSensor;
int16 timer=0;
int16 segundo=0;
short frec = false;

#INT_RTCC
void interrupcionTimer0(){
   set_timer0(131);
   frec = !frec;
   timer++;
   if (timer==8000){
      output_toggle(PIN_B2);
      segundo++;
      timer=0;
   }
}

#INT_RB
void interrupcionPuertoB(){
   estadoSensor=input(PIN_B4);
   if (estadoSensor==0){
      output_high(PIN_B1);
      output_low(PIN_A1);
      output_low(PIN_A2);
      if (segundo !=0 ){
         printf("Duracion en Estado Desbloqueado : %Ld Segundos \n\r " , segundo);
         segundo=0;
      } 
   } else{
      output_low(PIN_B1);
      output_high(PIN_A1);
      output_low(PIN_A2);
      if (segundo != 0){
         printf("Duracion en Estado Bloqueado : %Ld Segundos \n\r" , segundo);
         segundo=0;
      }
   }
   
}

void main()
{
   set_tris_a(0x01);
   set_tris_b(0x10);
   set_tris_c(0x00);
   output_a(0x00);
   output_b(0x00);
   output_c(0x00);
   ENABLE_INTERRUPTS(INT_RB);
   ENABLE_INTERRUPTS(INT_RTCC);
   ENABLE_INTERRUPTS(GLOBAL);
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_1);
   set_timer0(131);
   
   while(TRUE)
   {
      //TODO: User Code
      if (frec=true){
         output_high(PIN_C0);
      } else{
         output_low(PIN_C0);
      }
      
   }

}
