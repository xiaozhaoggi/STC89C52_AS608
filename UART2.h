#ifndef __UART2_H
#define __UART2_H

#include "reg52.h" 

#define uchar unsigned char 
#define uint unsigned int
	
#define UART2_MAX_RECV_LEN		50					//最大接收缓存字节数
#define UART2_MAX_SEND_LEN		50					//最大发送缓存字节数
//串口接收缓存区 	
uchar  xdata UART2_RX_BUF[UART2_MAX_RECV_LEN]; 				//接收缓冲,最大USART3_MAX_RECV_LEN个字节.
uchar  xdata UART2_TX_BUF[UART2_MAX_SEND_LEN]; 			  //发送缓冲,最大USART3_MAX_SEND_LEN字节
uint   UART2_RX_STA=0;  

//串口2初始化
void UART2_Init()
{
	SCON=0X50;			//设置为工作方式1
	TMOD=0X20;			//设置计数器工作方式2
	PCON=0X80;			//波特率加倍
	TH1=0XFF;				//计数器初始值设置，注意波特率是4800的
	TL1=0XFF;
	ES=1;						//打开接收中断
	EA=1;						//打开总中断
	TR1=1;					//打开计数器
}


//串口2发送一个字节
void UART2_SendData(uchar c)
{
    SBUF = c;
    while(!TI);  //若S2TI=0，在此等待
		TI=0;	         //S2TI=0
}

//串口2发送字符串
//void UART2_SendString(char *s)
//{
//    while (*s)              //Check the end of the string
//    {
//        UART2_SendData(*s++);     //Send current char and increment string ptr
//    }
//}

/************串行口2中断处理函数*************/
void UART2_Interrupt(void) interrupt 4
{
	uchar Res;
	
	Res=SBUF;
	RI = 0;

	UART2_RX_BUF[UART2_RX_STA++]=Res;	//记录接收到的值

}


#endif