#include "reg52.h"    //���ļ��ж����˵�Ƭ����һЩ���⹦�ܼĴ���
#include "key.h"
#include "lcd.h"
#include "stdio.h"
#include "AS608.h"

extern char wrong_times;
/*******************************************************************************
* �� �� ��       : main
* ��������		 : ������
* ��    ��       : ��
* ��    ��    	 : ��
*******************************************************************************/

void main()
{
	
  LCDInit();
	//ShowQQChar(0x85,"����",2);		//LCD  80  															
	//ShowQQChar(0x97,"��",1);			//     90
	//ShowQQChar(0x88,"��ҩʱ��:",4); //   88
																		// 98
	ShowQQChar(0x80,"����������:",6);
	UART2_Init();//���ڳ�ʼ��
	while(1)
	{
		key_judge(KeyDown());
		
		if(wrong_times >=3)
		{
			beep();
		}			
		
		

			
	}		
}
