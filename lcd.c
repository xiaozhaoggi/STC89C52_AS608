#include "lcd.h"
#include <intrins.h>
const Uchar delay_count=250; //延时时间常数
static void Wait1ms(void)//延迟1 ms
{
Uchar cnt=0;
while (cnt<delay_count) cnt++;
}

//延迟n ms
void WaitNms(int n)
{
Uchar i;
for(i=1;i<=n;i++)
Wait1ms();
}

/**************************************************************************/
//以下是并口时才开的
//读忙标志,
void RDBF(void)
{
Uchar temp;
RS=0; // RS=0
RW=1; // RW=1
Wait1ms();
while(1)
{
P2=0xFF; //数据线为输入
E=1;
temp=P2;
Wait1ms();
E=0; // E=0
if ((temp&0x80)==0) break;
}
}
//写数据到指令寄存器
void WRCommand(Uchar comm)
{
RDBF();
RW=0;
P2=comm;
Wait1ms();
E=1;
E=0;
}
//写数据到数据寄存器
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
//初始化LCD-8 位接口
void LCDInit(void)
{ // PSB=0; //串口
PSB=1;//并口时选这个,上一行取消
REST=1;
REST=0;
REST=1;
WRCommand(0x30); //基本指令集,8 位并行
WRCommand(0x06); //启始点设定：光标右移
WRCommand(0x01); //清除显示DDRAM
WRCommand(0x0C); //显示状态开关：整体显示开，光标显示关，光标显示反白关
WRCommand(0x02); //地址归零
}

//显示数组字符串(显示半宽字型16*8 点阵)
void ShowQQChar(Uchar addr,Uchar *english,Uchar count)
{
Uchar i;
WRCommand(addr);//设定DDRAM 地址
for(i=0;i<count;)
{
WRData(english[i*2]);	
WRData(english[i*2+1]);
i++;
}
}

/*//显示数组字符串(显示半宽字型16*8 点阵)
void ShowNUMChar(Uchar addr,Uchar *english,Uchar count)
{
Uchar i;
WRCommand(addr);//设定DDRAM 地址
for(i=0;i<count;)
{
WRData(english[i*2]);
i++;
}
}*/

//显示连续字串(半宽字符)
void ShowNUMChar(Uchar addr,Uchar i,Uchar count)
{
Uchar j;
for(j=0;j<count;)
{
WRCommand(addr);//设定DDRAM 地址
WRData(i+j);
j++;
WRData(i+j);
addr++;
j++;
}
}

