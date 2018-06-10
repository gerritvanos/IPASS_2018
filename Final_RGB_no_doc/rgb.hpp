#ifndef RGB_HPP
#define RGB_HPP
#include "pwm.hpp"

namespace RGB_lib
{

class RGB
{
   private:
	  PWM_lib::PWM_class red;
	  PWM_lib::PWM_class green;
	  PWM_lib::PWM_class blue;
	  float intensity;
	  int red_intensity;
	  int green_intensity;
	  int blue_intensity;
 
   public:
	   RGB(const int & red_ch_nr, const int & green_ch_nr, const int & blue_ch_nr, const int & intensity );
	   void change_color(const char & color);
	   void change_intensity(const int & new_intensity);
	   void change_red_intensity(const int & new_red_intensity);
	   void change_green_intensity(const int & new_green_intensity);
	   void change_blue_intensity(const int & new_blue_intensity);
};

};

#endif // RGB_HPP
