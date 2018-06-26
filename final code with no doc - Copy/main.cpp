#include "hwlib.hpp"
#include "rgb.hpp"
#include "pwm.hpp"
#include "dmx.hpp"
#include <array>

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   PWM_lib::enable_pwm();
   auto led1 = RGB_lib::RGB(0,1,2,100);
   DMX::enable_dmx();
   auto dmx1 = DMX::DMX(1,4);
   std::array<int,4> dmx_data;
   for (int i=0; i<4;i++){
	  dmx_data[i]=0;
   }
	  for(;;){
		hwlib::cout << dmx1.get_data(dmx_data);
		hwlib::wait_us(10);
		for (int i=0;i<4;i++){
		   hwlib::cout << "ch " <<i <<": " << "data: " << (int)dmx_data[i] << "\n";
		   hwlib::wait_us(10);
		}
		led1.change_red_intensity(dmx_data[0]);
		led1.change_green_intensity(dmx_data[1]);
		led1.change_blue_intensity(dmx_data[2]);
		led1.change_intensity(dmx_data[3]);
	  }
   
}
