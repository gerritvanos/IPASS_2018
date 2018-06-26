#ifndef PWM_HPP
#define PWM_HPP

namespace PWM_lib
{
   

   class PWM_class
   {
	  private:
		 int ch_nr;
	  public:
		  PWM_class(const int & ch_nr);
		  void change_duty_cycle(const int & new_duty_cycle);
	  };

   void enable_pwm();
};

#endif // PWM_HPP
