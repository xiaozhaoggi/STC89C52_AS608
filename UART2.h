#ifndef __UART2_H
#define __UART2_H

#include "reg52.h" 

#define uchar unsigned char 
#define uint unsigned int
	
#define UART2_MAX_RECV_LEN		50					//�����ջ����ֽ���
#define UART2_MAX_SEND_LEN		50					//����ͻ����ֽ���
//���ڽ��ջ����� 	
uchar  xdata UART2_RX_BUF[UART2_MAX_RECV_LEN]; 				//���ջ���,���USART3_MAX_RECV_LEN���ֽ�.
uchar  xdata UART2_TX_BUF[UART2_MAX_SEND_LEN]; 			  //���ͻ���,���USART3_MAX_SEND_LEN�ֽ�
uint   UART2_RX_STA=0;  

//����2��ʼ��
void UART2_Init()
{
	SCON=0X50;			//����Ϊ������ʽ1
	TMOD=0X20;			//���ü�����������ʽ2
	PCON=0X80;			//�����ʼӱ�
	TH1=0XFF;				//��������ʼֵ���ã�ע�Ⲩ������4800��
	TL1=0XFF;
	ES=1;						//�򿪽����ж�
	EA=1;						//�����ж�
	TR1=1;					//�򿪼�����
}


//����2����һ���ֽ�
void UART2_SendData(uchar c)
{
    SBUF = c;
    while(!TI);  //��S2TI=0���ڴ˵ȴ�
		TI=0;	         //S2TI=0
}

//����2�����ַ���
//void UART2_SendString(char *s)
//{
//    while (*s)              //Check the end of the string
//    {
//        UART2_SendData(*s++);     //Send current char and increment string ptr
//    }
//}

/************���п�2�жϴ�����*************/
void UART2_Interrupt(void) interrupt 4
{
	uchar Res;
	
	Res=SBUF;
	RI = 0;

	UART2_RX_BUF[UART2_RX_STA++]=Res;	//��¼���յ���ֵ

}


#endif