/********************************************************************************
 * Describe: 使用K210的GPIO实现呼吸灯
 * Date: 2020/11/03
 * Author: liu-huilin
 * Github：https://github.com/liu-huilin
 ********************************************************************************/
#include <fpioa.h>
#include <gpio.h>
#include <sleep.h>
#include <stdio.h>

int main()
{
	gpio_init();                             //初始化IO
	fpioa_set_function(14, FUNC_GPIO0);      //把GPIO0映射到K210的14引脚
	gpio_set_drive_mode(0, GPIO_DM_OUTPUT);  //把GPIO0设置为输出
	gpio_set_pin(0, GPIO_PV_HIGH);           //设置GPIO0为高
	while (1)
	{
		gpio_set_pin(0, 0);  // GPIO0置高电平 点灯
		msleep(500);
		gpio_set_pin(0, 1);  // GPIO0置低电平 灭灯
		msleep(500);
	}

	return 0;
}
