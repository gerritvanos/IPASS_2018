#include "rgb.hpp"

RGB_lib::RGB::RGB(const int & red_ch_nr, const int & green_ch_nr, const int & blue_ch_nr, const int & intensity):
red(red_ch_nr),
green(green_ch_nr),
blue(blue_ch_nr),
intensity(intensity/100.0)
{
}

void RGB_lib::RGB::change_color(const char & color){
   switch(color){
	  case 'r':
		 change_red_intensity(100);
		 change_green_intensity(0);
		 change_blue_intensity(0);
		 break;
	  case 'g':
		 change_red_intensity(0);
		 change_green_intensity(100);
		 change_blue_intensity(0);
		 break;
	  case 'b':
		 change_red_intensity(0);
		 change_green_intensity(0);
		 change_blue_intensity(100);
		 break;
	  case 'c':
		 change_red_intensity(0);
		 change_green_intensity(100);
		 change_blue_intensity(100);
		 break;
	  case 'm':
		 change_red_intensity(100);
		 change_green_intensity(0);
		 change_blue_intensity(100);
		 break;
	  case 'y':
		 change_red_intensity(100);
		 change_green_intensity(100);
		 change_blue_intensity(0);
		 break;
	  case 'w':
		 change_red_intensity(100);
		 change_green_intensity(100);
		 change_blue_intensity(100);
		 break;
   }
}
void RGB_lib::RGB::change_intensity(const int & new_intensity){
   intensity = new_intensity/100.0;
   change_blue_intensity(blue_intensity);
   change_red_intensity(red_intensity);
   change_green_intensity(green_intensity);   
}
void RGB_lib::RGB::change_red_intensity(const int & new_red_intensity){
   red_intensity = new_red_intensity;
   red.change_duty_cycle((int)red_intensity*intensity);
   
}
void RGB_lib::RGB::change_green_intensity(const int & new_green_intensity){
   green_intensity = new_green_intensity;
   green.change_duty_cycle((int)green_intensity*intensity);
}
void RGB_lib::RGB::change_blue_intensity(const int & new_blue_intensity){
   blue_intensity = new_blue_intensity;
   blue.change_duty_cycle((int)blue_intensity*intensity);
}

