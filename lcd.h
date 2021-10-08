#ifndef __LCD_H
#define __LCD_H

#include "reg52.h" 
#include <intrins.h>

//---包含字库头文件
#define CHAR_CODE


//---重定义关键词---//
#ifndef Uint
#define Uint unsigned int
#endif

#ifndef Uchar 
#define Uchar unsigned char
#endif

//--定时使用的IO口--//
sbit REST = P0^3;
sbit RS   = P0^7;
sbit RW   = P0^6;
sbit E	  = P0^5;
sbit PSB  = P0^4;

static void Wait1ms(void);//延迟1 ms
void WaitNms(int n);
void RDBF(void);
void WRCommand(Uchar comm);
void WRData(Uchar TEMP);
void LCDInit(void);
void ShowQQChar(Uchar addr,Uchar *english,Uchar count);
void ShowNUMChar(Uchar addr,Uchar i,Uchar count);

#endif