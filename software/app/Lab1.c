#include "sys/alt_stdio.h"

#include "system.h"
#include "altera_avalon_pio_regs.h"

#include <sys/alt_irq.h> 
#include <alt_types.h>
#include "sys/alt_sys_init.h"

alt_u32 delay;

static void changeSpeed(void * context, alt_u32 id){
	if(delay==100000){
		delay=500000;
	}else{
		delay-=100000;
	}
	//clear
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(PIO_IN_BASE,0x01);
}

int main() {
	alt_printf("\nLab 1 : LED Chaser");
	
	alt_u32 ledId = 1;
	alt_u32 i = 0;
	 delay = 500000;
	
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(PIO_IN_BASE, 0x01);
	alt_irq_register(PIO_IN_IRQ, NULL, (void*)changeSpeed);
	
	
	while(1){
		//DELAY
		while(i<delay){
			i++;
		}
		i=0;
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_OUT_BASE,ledId);
		ledId=ledId*2;
		if(ledId>512){
			ledId=1;
		}
	}
	return 0;
}

