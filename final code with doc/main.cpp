#include "hwlib.hpp"
#include "rgb.hpp"
#include "pwm.hpp"
#include "dmx.hpp"
#include <array>

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   PWM_lib::enable_pwm();
   DMX::enable_dmx();
   
   const int nr_off_ch = 4;
   auto led1 = RGB_lib::RGB(0,1,2,100);
   auto dmx1 = DMX::DMX(1,nr_off_ch);
   std::array<int,nr_off_ch> dmx_data;
   for (int i=0; i<nr_off_ch;i++){ //set all array values to zero
	  dmx_data[i]=0;
   }
   
	  for(;;){//infinite loop
		dmx1.get_data(dmx_data); //get dmx data and store in array
		hwlib::wait_us(4);
		led1.change_red_intensity(dmx_data[0]); 	// set red intensity with value from array
		led1.change_green_intensity(dmx_data[1]); 	// set green intensity with value from array
		led1.change_blue_intensity(dmx_data[2]);	// set blue intensity with value from array
		led1.change_intensity(dmx_data[3]);			// set intensity with value from array
	  }
   
}
