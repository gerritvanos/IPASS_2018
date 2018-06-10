#ifndef DMX_HPP
#define DMX_HPP

namespace DMX
{

class DMX
{
   private:
	  int start_adress;
	  int nr_off_ch;
   public:
	  DMX(const int & start_adress, const int & nr_off_ch = 1);
	  int get_data();
	  
	
};

   void enable_dmx();

}

#endif // DMX_HPP
