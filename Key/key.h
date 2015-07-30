/*
功能；k60平台，LPLD库控制，4*4矩阵键盘程序
*/
#ifndef _KEY_H_ 
#define _KEY_H_

#define Row0 PTC8_O
#define Row1 PTC9_O
#define Row2 PTC10_O
#define Row3 PTC11_O


#define Column0 PTC12_I
#define Column1 PTC13_I
#define Column2 PTC14_I
#define Column3 PTC15_I

/*简单延时程序*/
void delay();
int key_scan(void);
/*键盘端口定义*/
void init_gpio1();
void init_gpio2();
/*键盘扫描程序*/
int  KeyDown();


#endif
