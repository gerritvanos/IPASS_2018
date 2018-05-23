#include "hwlib.hpp"
#include "rgb.hpp"
#include "pwm.hpp"
int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   PWM_lib::enable_pwm();
   auto led1 = RGB_lib::RGB(0,1,2,100);

   
   for(;;){
		 led1.change_blue_intensity(0);
		 led1.change_green_intensity(0);
		 led1.change_red_intensity(0);
		 for (int i=0;i<100;i++){
			led1.change_red_intensity(i);
			hwlib::wait_ms(100);
		 }
		 
		 for (int i=0;i<100;i++){
			led1.change_green_intensity(i);
			hwlib::wait_ms(100);
		 }
		 for (int i=0;i<100;i++){
			led1.change_blue_intensity(i);
			hwlib::wait_ms(100);
		 }
		 for (int i=100; i>0;i--){
			led1.change_intensity(i);
			hwlib::wait_ms(100);
		 }
	  }
}
