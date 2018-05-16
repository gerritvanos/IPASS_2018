#include "pwm.hpp"
#include "hwlib.hpp"

PWM_lib::PWM_class::PWM_class(const int & ch_nr):
ch_nr(ch_nr)
{ 
	  switch (ch_nr){
		 case 0:
			REG_PWM_CPRD0 = 256; // set period
			REG_PWM_CDTY0 = 128; // set dutycyle (50%)
			REG_PWM_CMR0 = PWM_CMR_CALG | PWM_CMR_CPRE_CLKA; // link clock and enable dualslope 
			REG_PWM_ENA = PWM_ENA_CHID0; // enable ch
			break;
		 case 1:
			REG_PWM_CPRD1 = 256;
			REG_PWM_CDTY1 = 128;
			REG_PWM_CMR1 = PWM_CMR_CALG | PWM_CMR_CPRE_CLKA;
			REG_PWM_ENA = PWM_ENA_CHID1;
			break;
		 case 2:
			REG_PWM_CPRD2 = 256;
			REG_PWM_CDTY2 = 128;
			REG_PWM_CMR2 = PWM_CMR_CALG | PWM_CMR_CPRE_CLKA;
			REG_PWM_ENA = PWM_ENA_CHID2;
			break;
		 case 3:
			REG_PWM_CPRD3 = 256;
			REG_PWM_CDTY3 = 128;
			REG_PWM_CMR3 = PWM_CMR_CALG | PWM_CMR_CPRE_CLKA;
			REG_PWM_ENA = PWM_ENA_CHID3;
			break;
		 case 4:
			REG_PWM_CPRD4 = 256;
			REG_PWM_CDTY4 = 128;
			REG_PWM_CMR4 = PWM_CMR_CALG | PWM_CMR_CPRE_CLKA;
			REG_PWM_ENA = PWM_ENA_CHID4;
			break;
		 case 5:
			REG_PWM_CPRD5 = 256;
			REG_PWM_CDTY5 = 128;
			REG_PWM_CMR5 = PWM_CMR_CALG | PWM_CMR_CPRE_CLKA;
			REG_PWM_ENA = PWM_ENA_CHID5;
			break;
		 case 6:
			REG_PWM_CPRD6 = 256;
			REG_PWM_CDTY6 = 128;
			REG_PWM_CMR6 = PWM_CMR_CALG | PWM_CMR_CPRE_CLKA;
			REG_PWM_ENA = PWM_ENA_CHID6;
			break;	
		 case 7:
			REG_PWM_CPRD7 = 256;
			REG_PWM_CDTY7 = 128;
			REG_PWM_CMR7 = PWM_CMR_CALG | PWM_CMR_CPRE_CLKA;
			REG_PWM_ENA = PWM_ENA_CHID7;
			break;
	  }
	 
}

void PWM_lib::PWM_class::change_duty_cycle(const int & new_duty_cycle){
   int output_duty_cycle;
   if (new_duty_cycle>100){
	  output_duty_cycle=255;
   }
   else if(new_duty_cycle<0){
	  output_duty_cycle =0;
   }
   else{
	  output_duty_cycle=new_duty_cycle*2.55;
   }
   switch (ch_nr){
		 case 0:
			REG_PWM_CDTYUPD0 = output_duty_cycle;
			break;
		 case 1:
			REG_PWM_CDTYUPD1 = output_duty_cycle;
			break;
		 case 2:
			REG_PWM_CDTYUPD2 = output_duty_cycle;
			break;
		 case 3:
			REG_PWM_CDTYUPD3 = output_duty_cycle;
			break;
		 case 4:
			REG_PWM_CDTYUPD4 = output_duty_cycle;
			break;
		 case 5:
			REG_PWM_CDTYUPD5 = output_duty_cycle;
			break;
		 case 6:
			REG_PWM_CDTYUPD6 = output_duty_cycle;
			break;
		 case 7:
			REG_PWM_CDTYUPD7 = output_duty_cycle;
			break;
	  }
}
void PWM_lib::enable_pwm(){
   REG_PMC_PCER1 |= PMC_PCER1_PID36; //enable PWM
   REG_PWM_CLK = PWM_CLK_PREA(0) | PWM_CLK_DIVA(1); // set clock
   REG_PWM_SCM = (0x01<<16); // enable auto update
   
   //set ch's to proper output pins
   // ch0 PIO: C2 perpheral: B arduino_board_pin: 34
   REG_PIOC_ABSR |= PIO_ABSR_P2;                     
   REG_PIOC_PDR |= PIO_PDR_P2; 
   //ch1 PIO C4 perpheral: B arduino_board_pin: 36
   REG_PIOC_ABSR |= PIO_ABSR_P4;                     
   REG_PIOC_PDR |= PIO_PDR_P4; 
   //ch2 PIO C6 perpheral: B arduino_board_pin: 38
   REG_PIOC_ABSR |= PIO_ABSR_P6;                     
   REG_PIOC_PDR |= PIO_PDR_P6; 
   //ch3 PIO C8 perpheral: B arduino_board_pin: 40
   REG_PIOC_ABSR |= PIO_ABSR_P8;                     
   REG_PIOC_PDR |= PIO_PDR_P8;
   //ch4 PIO C21 perpheral: B arduino_board_pin: 9
   REG_PIOC_ABSR |= PIO_ABSR_P21;                     
   REG_PIOC_PDR |= PIO_PDR_P21;  
   //ch5 PIO C22 perpheral: B arduino_board_pin: 8
   REG_PIOC_ABSR |= PIO_ABSR_P22;                     
   REG_PIOC_PDR |= PIO_PDR_P22;
   //ch6 PIO C23 perpheral: B arduino_board_pin: 7
   REG_PIOC_ABSR |= PIO_ABSR_P23;                     
   REG_PIOC_PDR |= PIO_PDR_P23;  
   //ch7 PIO C24 perpheral: B arduino_board_pin: 6
   REG_PIOC_ABSR |= PIO_ABSR_P24;                     
   REG_PIOC_PDR |= PIO_PDR_P24; 
}


