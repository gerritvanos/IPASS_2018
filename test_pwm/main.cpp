#include "hwlib.hpp"
#include "pwm.hpp"
int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   PWM_lib::enable_pwm();
   auto ch_0 = PWM_lib::PWM_class(0);
   auto ch_1 = PWM_lib::PWM_class(1);
   auto ch_2 = PWM_lib::PWM_class(2);
   auto ch_3 = PWM_lib::PWM_class(3);
   auto ch_4 = PWM_lib::PWM_class(4);
   auto ch_5 = PWM_lib::PWM_class(5);
   auto ch_6 = PWM_lib::PWM_class(6);
   auto ch_7 = PWM_lib::PWM_class(7);
   
   for(;;){
	  for (int i=0; i<100;i++){
		 ch_4.change_duty_cycle(i);
		 ch_0.change_duty_cycle(i);
		 hwlib::wait_ms(100);
	  }
   }
}
