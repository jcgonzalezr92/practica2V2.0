#include <practica2V2.h>
short estadoSensor;
#INT_RB
void interrupcionPuertoB(){
   estadoSensor=input(PIN_B4);
   if (estadoSensor==0){
      output_high(PIN_B1);
   } else{
      output_low(PIN_B1);
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
   ENABLE_INTERRUPTS(GLOBAL);
   while(TRUE)
   {
      //TODO: User Code
   }

}
