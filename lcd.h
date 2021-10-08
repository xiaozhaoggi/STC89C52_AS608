#ifndef __LCD_H
#define __LCD_H

#include "reg52.h" 
#include <intrins.h>

//---�����ֿ�ͷ�ļ�
#define CHAR_CODE


//---�ض���ؼ���---//
#ifndef Uint
#define Uint unsigned int
#endif

#ifndef Uchar 
#define Uchar unsigned char
#endif

//--��ʱʹ�õ�IO��--//
sbit REST = P0^3;
sbit RS   = P0^7;
sbit RW   = P0^6;
sbit E	  = P0^5;
sbit PSB  = P0^4;

static void Wait1ms(void);//�ӳ�1 ms
void WaitNms(int n);
void RDBF(void);
void WRCommand(Uchar comm);
void WRData(Uchar TEMP);
void LCDInit(void);
void ShowQQChar(Uchar addr,Uchar *english,Uchar count);
void ShowNUMChar(Uchar addr,Uchar i,Uchar count);

#endif