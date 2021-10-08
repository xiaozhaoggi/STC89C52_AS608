#include "key.h"
#include "reg52.h"
#include "lcd.h"
#include <string.h>

#define GPIO_KEY P1

sbit VOICE = P3^6;	//��������������
char *code1 = "123456";
char *code2 = "654321";
char code_buf[10] = {0};
char lcd_num = 0;
char wrong_times = 0;

/*******************************************************************************
* �� �� ��         : delay
* ��������		   : ��ʱ������i=1ʱ����Լ��ʱ10us
*******************************************************************************/
void delay(unsigned int i)
{
	while(i--);	
}

void delayms(unsigned int ms)               
{
	unsigned int a,b,c;
	for(a=ms;a>0;a--)
		for(b=10;b>0;b--)
			for(c=85;c>0;c--);
}

void beep()
{
  unsigned char i , j;
  for (i=0;i<100;i++)
   {
  
      VOICE=!VOICE;              //BEEPȡ��
      for (j = 0 ; j<250 ; j++)   //��Ҫ��������
      _nop_();
		 
   }
}
/*******************************************************************************
* �� �� ��         : KeyDown
* ��������		   : ����а������²���ȡ��ֵ
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
unsigned char KeyDown(void)
{
	char a=0;
	unsigned char KeyValue = 0;
	GPIO_KEY=0x0f;
	if(GPIO_KEY!=0x0f)//��ȡ�����Ƿ���
	{
		delay(1000);//��ʱ10ms��������
		if(GPIO_KEY!=0x0f)//�ٴμ������Ƿ���
		{	
			//������
			GPIO_KEY=0X0F;
			switch(GPIO_KEY)
			{
				case(0X07):	KeyValue=0;break;
				case(0X0b):	KeyValue=1;break;
				case(0X0d): KeyValue=2;break;
				case(0X0e):	KeyValue=3;break;
			}
			//������
			GPIO_KEY=0XF0;
			switch(GPIO_KEY)
			{
				case(0X70):	KeyValue=KeyValue;break;
				case(0Xb0):	KeyValue=KeyValue+4;break;
				case(0Xd0): KeyValue=KeyValue+8;break;
				case(0Xe0):	KeyValue=KeyValue+12;break;
			}
			while((a<100)&&(GPIO_KEY!=0xf0))	 //��ⰴ�����ּ��
			{
				delay(300);
				a++;
			}			
			return KeyValue;
		}
	}

			return 16;
}

void key_judge(unsigned char key_value)
{
	switch(key_value)
	{
		case 0:
			strcat(code_buf,"0");
		
			if(strlen(code_buf)%2 !=0)
				lcd_num = strlen(code_buf)/2+1;
			else
				lcd_num = strlen(code_buf)/2;
			
			ShowQQChar(0x90,code_buf,lcd_num);
			break;
			
		case 1:
			strcat(code_buf,"1");
			if(strlen(code_buf)%2 !=0)
				lcd_num = strlen(code_buf)/2+1;
			else
				lcd_num = strlen(code_buf)/2;
			
			ShowQQChar(0x90,code_buf,lcd_num);
			
			break;
		
		
		case 2:
			strcat(code_buf,"2");
			if(strlen(code_buf)%2 !=0)
				lcd_num = strlen(code_buf)/2+1;
			else
				lcd_num = strlen(code_buf)/2;
			
			ShowQQChar(0x90,code_buf,lcd_num);
			
			break;
		
		case 3:
			strcat(code_buf,"3");
			if(strlen(code_buf)%2 !=0)
				lcd_num = strlen(code_buf)/2+1;
			else
				lcd_num = strlen(code_buf)/2;
			
			ShowQQChar(0x90,code_buf,lcd_num);
			
			break;
			
		case 4:
			strcat(code_buf,"4");
			if(strlen(code_buf)%2 !=0)
				lcd_num = strlen(code_buf)/2+1;
			else
				lcd_num = strlen(code_buf)/2;
			
			ShowQQChar(0x90,code_buf,lcd_num);
			
			break;		
		
		case 5:
			strcat(code_buf,"5");
			if(strlen(code_buf)%2 !=0)
				lcd_num = strlen(code_buf)/2+1;
			else
				lcd_num = strlen(code_buf)/2;
			
			ShowQQChar(0x90,code_buf,lcd_num);
			
			break;
		
		case 6:
			strcat(code_buf,"6");
			if(strlen(code_buf)%2 !=0)
				lcd_num = strlen(code_buf)/2+1;
			else
				lcd_num = strlen(code_buf)/2;
			
			ShowQQChar(0x90,code_buf,lcd_num);

			break;
		
		case 7:
			strcat(code_buf,"7");
			if(strlen(code_buf)%2 !=0)
				lcd_num = strlen(code_buf)/2+1;
			else
				lcd_num = strlen(code_buf)/2;
			
			ShowQQChar(0x90,code_buf,lcd_num);
			break;
		
		case 8://ȷ�� 
			
		if(strcmp(code_buf,code1) == 0 || strcmp(code_buf,code2) == 0)
		{
			WRCommand(0x01);
			ShowQQChar(0x80,"������ȷ:",4);
			memset(code_buf, 0,sizeof(code_buf));
			wrong_times = 0;
		}
		else
		{
			WRCommand(0x01);
			ShowQQChar(0x80,"�������:",4);
			memset(code_buf, 0,sizeof(code_buf));
			wrong_times++;
		}
		delayms(500);
		WRCommand(0x01);
		if(wrong_times < 3)
		ShowQQChar(0x80,"����������:",6);
		else
		ShowQQChar(0x80,"��������������",8);	
			break;
		
		case 9://���
		memset(code_buf, 0,sizeof(code_buf));
		WRCommand(0x01);
		ShowQQChar(0x80,"����������:",6);
		if(wrong_times >=3)
		{
			wrong_times = 0;
		}		
			break;
		
		case 10:
			WRCommand(0x01);
			Add_FR();		
			
			break;
		
		case 11:
			WRCommand(0x01);
			Del_FR();
			
			break;
		
		case 12:
			WRCommand(0x01);
			ShowQQChar(0x80,"�밴��ָ",4);
			press_FR(); 
			
			break;
		
		case 13:
			
			break;
		
		case 14:
			
			break;
		
		case 15:
			
			break;
		
		
		
	}
}