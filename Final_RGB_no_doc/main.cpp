#include "hwlib.hpp"
#include "rgb.hpp"
#include "pwm.hpp"
int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   PWM_lib::enable_pwm();
   auto led1 = RGB_lib::RGB(0,1,2,100);
   
   for(;;){
		 led1.change_color('r');
		 hwlib::wait_ms(500);
		 led1.change_color('g');
		 hwlib::wait_ms(500);
		 led1.change_color('b');
		 hwlib::wait_ms(500);
		 led1.change_color('c');
		 hwlib::wait_ms(500);
		 led1.change_color('m');
		 hwlib::wait_ms(500);
		 led1.change_color('y');
		 hwlib::wait_ms(500);
		 led1.change_color('w');
		 hwlib::wait_ms(500);
		 for (int i=100;i>0;i--){
			led1.change_intensity(i);
			hwlib::wait_ms(50);
		 }
   }
}
