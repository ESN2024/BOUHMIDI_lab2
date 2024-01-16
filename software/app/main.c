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



int main()
{
	unsigned short cnt = 0;
	unsigned short unit;
	unsigned short dis;
	unsigned short cen;
	unsigned short data;
	
	while (1)
	{
		while (cnt < 999)
		{
			cen = cnt / 100;
			dis = (cnt/10) % 10;
			unit = cnt % 10;
			data = (cen << 8) | (dis << 4) | unit;
			IOWR_ALTERA_AVALON_PIO_DATA(SEG_BASE,data);
			cnt = cnt + 1;
			usleep(50000);
		}
		cnt = 0;
	}
	return 0;
}