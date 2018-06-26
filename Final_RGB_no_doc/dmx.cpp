#include "DMX.hpp"
#include "hwlib.hpp"

DMX::DMX::DMX(const int & start_adress, const int & nr_off_ch):
start_adress(start_adress),
nr_off_ch(nr_off_ch)
{
}

int DMX::DMX::get_data(){   
		hwlib::cout << REG_USART1_BRGR<<"\n";
		hwlib::wait_us(4);
		 return 0;									 
}

void DMX::enable_dmx(){

    REG_PMC_PCER0 |= PMC_PCER0_PID17; // enable usart0
	REG_USART1_CR  = (0x01<<5); // enable reciever 
	REG_USART1_MR = (14528<<0); //set nr. of stopbits to 2bits &parity to non and chlength to 8
	REG_USART1_BRGR = (0X15<<0); //set baudrate to 0.25mhz
	REG_USART1_IER = (0x01 << 2);//enable break interupt 
}

