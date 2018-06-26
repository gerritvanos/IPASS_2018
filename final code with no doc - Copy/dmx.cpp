#include "DMX.hpp"
#include "hwlib.hpp"
#include <array>

DMX::DMX::DMX(const int & start_adress, const int & nr_off_ch):
start_adress(start_adress),
nr_off_ch(nr_off_ch)
{
}

int DMX::DMX::get_data(std::array<int,4> & DmxRxField){   
  
	  
	  volatile uint16_t DmxAddress = start_adress;    //start address
	  static  uint16_t DmxCount;
	  int break_detect =0;
	  enum {IDLE, BREAK, STARTB, STARTADR}; //DMX states
 
	  volatile uint8_t DmxState;
	  for(;;){
	  if (REG_USART0_CSR&(0x01<<0)){
        
        uint8_t  USARTstate= REG_USART0_CSR;    //get state before data!
        uint8_t  DmxByte   = REG_USART0_RHR;          //get data
        if (USARTstate &(1<<2) && break_detect==0)               //check for break
        {
			   break_detect =1;
				REG_USART0_CR |= (0x01<<8);
				REG_USART0_CR |= (0<<8);
        }
		else if (USARTstate &(1<<2) && break_detect==1) {
			   DmxCount =  DmxAddress;         //reset channel counter (count channels before start address)
                DmxState= STARTB;
				REG_USART0_CR |= (0x01<<8);
				REG_USART0_CR |= (0<<8);
		}
 
      
 
        else if (DmxState == STARTB)
        {
                if (--DmxCount == 0)    //start address reached?
                {
                        DmxCount= 1;            //set up counter for required channels
                        DmxRxField[0]= DmxByte/2.55; //get 1st DMX channel of device
                        DmxState= STARTADR;
						
                }
        }
 
        else if (DmxState == STARTADR)
        {
                DmxRxField[DmxCount++]= DmxByte;        //get channel
                if (DmxCount >= DmxRxField.size()) //all ch received?
                {
                        DmxState= IDLE;        //wait for next break
						return 0;
                }
        }
	  
	  }
	  }
}
  
void DMX::enable_dmx(){

    REG_PMC_PCER0 |= PMC_PCER0_PID17; // enable usart0
	REG_USART0_CR  |= (0x01<<4); // enable reciever 
    REG_USART0_CR |= (0x01<<8);//reset status bits
	REG_USART0_MR |= (0x03<<6); //set character length to 8 bits
	REG_USART0_MR |= (0x04<<9); // set parity to non
	REG_USART0_MR |= (0x02<<12);//set stopbits to 2
	REG_USART0_BRGR |= (21<<0); //set baudrate to 250kbit
}

