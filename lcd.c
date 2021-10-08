#include "lcd.h"
#include <intrins.h>
const Uchar delay_count=250; //��ʱʱ�䳣��
static void Wait1ms(void)//�ӳ�1 ms
{
Uchar cnt=0;
while (cnt<delay_count) cnt++;
}

//�ӳ�n ms
void WaitNms(int n)
{
Uchar i;
for(i=1;i<=n;i++)
Wait1ms();
}

/**************************************************************************/
//�����ǲ���ʱ�ſ���
//��æ��־,
void RDBF(void)
{
Uchar temp;
RS=0; // RS=0
RW=1; // RW=1
Wait1ms();
while(1)
{
P2=0xFF; //������Ϊ����
E=1;
temp=P2;
Wait1ms();
E=0; // E=0
if ((temp&0x80)==0) break;
}
}
//д���ݵ�ָ��Ĵ���
void WRCommand(Uchar comm)
{
RDBF();
RW=0;
P2=comm;
Wait1ms();
E=1;
E=0;
}
//д���ݵ����ݼĴ���
void WRData(Uchar TEMP)
{
RDBF();
RS=1;
RW=0;
P2=TEMP;
Wait1ms();
E=1;
E=0;
}

/*******************************************************************/
//��ʼ��LCD-8 λ�ӿ�
void LCDInit(void)
{ // PSB=0; //����
PSB=1;//����ʱѡ���,��һ��ȡ��
REST=1;
REST=0;
REST=1;
WRCommand(0x30); //����ָ�,8 λ����
WRCommand(0x06); //��ʼ���趨���������
WRCommand(0x01); //�����ʾDDRAM
WRCommand(0x0C); //��ʾ״̬���أ�������ʾ���������ʾ�أ������ʾ���׹�
WRCommand(0x02); //��ַ����
}

//��ʾ�����ַ���(��ʾ�������16*8 ����)
void ShowQQChar(Uchar addr,Uchar *english,Uchar count)
{
Uchar i;
WRCommand(addr);//�趨DDRAM ��ַ
for(i=0;i<count;)
{
WRData(english[i*2]);	
WRData(english[i*2+1]);
i++;
}
}

/*//��ʾ�����ַ���(��ʾ�������16*8 ����)
void ShowNUMChar(Uchar addr,Uchar *english,Uchar count)
{
Uchar i;
WRCommand(addr);//�趨DDRAM ��ַ
for(i=0;i<count;)
{
WRData(english[i*2]);
i++;
}
}*/

//��ʾ�����ִ�(����ַ�)
void ShowNUMChar(Uchar addr,Uchar i,Uchar count)
{
Uchar j;
for(j=0;j<count;)
{
WRCommand(addr);//�趨DDRAM ��ַ
WRData(i+j);
j++;
WRData(i+j);
addr++;
j++;
}
}

