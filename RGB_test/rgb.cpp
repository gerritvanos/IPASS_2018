#include "rgb.hpp"

RGB_lib::RGB::RGB(const int & red_ch_nr, const int & green, const int & blue, const int & intensity):
red(red_ch_nr),
green(green),
blue(blue),
intensity(intensity)
{
}

void RGB_lib::RGB::change_color(const char & color){
   switch(color){
	  case 'r':
		 red.change_duty_cycle(100);
		 green.change_duty_cycle(0);
		 blue.change_duty_cycle(0);
		 break;
	  case 'g':
		 red.change_duty_cycle(0);
		 green.change_duty_cycle(100);
		 blue.change_duty_cycle(0);
		 break;
	  case 'b':
		 red.change_duty_cycle(0);
		 green.change_duty_cycle(0);
		 blue.change_duty_cycle(100);
		 break;
	  case 'c':
		 red.change_duty_cycle(0);
		 green.change_duty_cycle(100);
		 blue.change_duty_cycle(100);
		 break;
	  case 'm':
		 red.change_duty_cycle(100);
		 green.change_duty_cycle(0);
		 blue.change_duty_cycle(100);
		 break;
	  case 'y':
		 red.change_duty_cycle(100);
		 green.change_duty_cycle(100);
		 blue.change_duty_cycle(0);
		 break;
	  case 'w':
		 red.change_duty_cycle(100);
		 green.change_duty_cycle(100);
		 blue.change_duty_cycle(100);
		 break;
   }
}
void RGB_lib::RGB::change_intensity(const int & new_intensity){
   intensity = new_intensity; 
}
void RGB_lib::RGB::change_red_intensity(const int & new_red_intensity){
   red.change_duty_cycle(new_red_intensity);
}
void RGB_lib::RGB::change_green_intensity(const int & new_green_intensity){
   green.change_duty_cycle(new_green_intensity);
}
void RGB_lib::RGB::change_blue_intensity(const int & new_blue_intensity){
   blue.change_duty_cycle(new_blue_intensity);
}

