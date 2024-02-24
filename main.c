#include <16f877a.h>
#fuses HS,NOWDT,NOPROTECT,NOPUT,NOLVP,BROWNOUT
#use delay(clock=2M)
#use standard_io(B)

long contador = 0;

#INT_TIMER0
void timer0_interrupcion()
{
   contador++;
   if(contador == 1000)       // Contador para 1 segundo
   {
      output_toggle(PIN_B0);
      contador = 0;
   }
   set_timer0(254);
}

void main()
{
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_256);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
   set_timer0(254);
   output_high(PIN_B0);
   
   while(true)
   {
      output_high(PIN_B1);
      delay_ms(1000);
      output_low(PIN_B1);
      delay_ms(1000);
   }
}

