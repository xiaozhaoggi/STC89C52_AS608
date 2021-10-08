#include "reg52.h"    //此文件中定义了单片机的一些特殊功能寄存器
#include "key.h"
#include "lcd.h"
#include "stdio.h"
#include "AS608.h"

extern char wrong_times;
/*******************************************************************************
* 函 数 名       : main
* 函数功能		 : 主函数
* 输    入       : 无
* 输    出    	 : 无
*******************************************************************************/

void main()
{
	
  LCDInit();
	//ShowQQChar(0x85,"星期",2);		//LCD  80  															
	//ShowQQChar(0x97,"℃",1);			//     90
	//ShowQQChar(0x88,"吃药时间:",4); //   88
																		// 98
	ShowQQChar(0x80,"请输入密码:",6);
	UART2_Init();//串口初始化
	while(1)
	{
		key_judge(KeyDown());
		
		if(wrong_times >=3)
		{
			beep();
		}			
		
		

			
	}		
}
