/// @file
#ifndef RGB_HPP
#define RGB_HPP
#include "pwm.hpp"

///\brief
/// namespace for RGB library
///\details
/// this namespace contains all the functions for the RGB class
namespace RGB_lib
{

///\brief
/// RGB class with a virtual dimmer and RGB control
///\details
/// This is a RGB class which controlls 3 pwm channels which are connected to the R,G and B channels of a ledstrip
/// The appropriate constructors and functions are provided
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
	   ///\brief 
	   /// constructor 
	   ///\details
	   /// this constructor initializes the RGB object
	   /// the parameters are for each color (RGB) the PWM channel and the default intensity
	   RGB(const int & red_ch_nr, const int & green_ch_nr, const int & blue_ch_nr, const int & intensity );
	   
	   ///\brief
	   ///function to set a pre programed color
	   ///\details
	   /// this function sets the output to a pre programmed color see list below for the colors, the main intensity is stil effectif 
	   ///the wanted color should be given as a char \n
	   /// 'r' = red, 'g' = green, 'b' = blue, 'c' = cyan, 'm' = magenta, 'y' = yellow, 'w' =  white 
	   void change_color(const char & color);
	   
	   ///\brief
	   /// function to change the intensity of all the leds
	   ///\details
	   /// this function changes the intensity of all the colors at the same time
	   /// intensity should be given as a integer between 0-100.\n
	   /// if a value below 0 is given it will be set to a 0, same for a value above 100 this will be set to 100
	   void change_intensity(const int & new_intensity);
	   
	   ///\brief
	   /// function to change the intensity of the red led channel
	   ///\details
	   /// this function changes the intensity of the red leds
	   /// intensity should be given as a integer between 0-100.\n
	   /// if a value below 0 is given it will be set to a 0, same for a value above 100 this will be set to 100
	   void change_red_intensity(const int & new_red_intensity);
	   
	   ///\brief
	   /// function to change the intensity of the green led channel
	   ///\details
	   /// this function changes the intensity of the green leds
	   /// intensity should be given as a integer between 0-100. \n
	   /// if a value below 0 is given it will be set to a 0, same for a value above 100 this will be set to 100
	   void change_green_intensity(const int & new_green_intensity);
	   
	     ///\brief
	   /// function to change the intensity of the blue led channel
	   ///\details
	   /// this function changes the intensity of the blue leds
	   /// intensity should be given as a integer between 0-100.\n
	   /// if a value below 0 is given it will be set to a 0, same for a value above 100 this will be set to 100
	   void change_blue_intensity(const int & new_blue_intensity);
};

};

#endif // RGB_HPP
