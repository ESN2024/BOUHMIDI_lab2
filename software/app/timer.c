#include<stdio.h>
#include<stdint.h>
#include "system.h"
#include <io.h>
#include "altera_avalon_pio_regs.h"
#include "sys/alt_stdio.h"
#include <unistd.h>
#include <sys/alt_irq.h>
#include "altera_avalon_timer_regs.h"
#include "altera_avalon_timer.h"


int cnt = 0;


void handle_timer_interrupt(void*p, alt_u32 param)

{
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0b1);
/* 	alt_printf("tic\n"); */
	int unit;
	int dis;
	int cen;
	int data;

	if (cnt < 999)
	{
		cen = cnt / 100;
		dis = (cnt/10) % 10;
		unit = cnt % 10;
		data = (cen << 8) | (dis << 4) | unit;
		IOWR_ALTERA_AVALON_PIO_DATA(SEG_BASE,data);
	}else
		cnt = 0;
	cnt = cnt + 1;



}


int main()
{
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE,ALTERA_AVALON_TIMER_CONTROL_CONT_MSK | ALTERA_AVALON_TIMER_CONTROL_START_MSK | ALTERA_AVALON_TIMER_CONTROL_ITO_MSK);
	alt_irq_register(TIMER_0_IRQ,NULL,handle_timer_interrupt);
	while (1)
	{
		
	}
	return 0;
}