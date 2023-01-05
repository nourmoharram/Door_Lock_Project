#include<util/delay.h>
#include "../APPLICATION/APP1.h"





int main(void)
{
	MC1_Init();
	while(1)
	{
		APP_Start();
		_delay_ms(1000);
	}
}



