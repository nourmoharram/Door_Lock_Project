#include<util/delay.h>
#include "../APPLICATION/APP2.h"

int main(void)
{
	MC2_Init();
	while(1)
	{
		APP_Start();
		_delay_ms(1000);

	}
}