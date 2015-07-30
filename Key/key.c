#include "common.h"
#include "key.h"

GPIO_InitTypeDef gpio_init_struct1;
GPIO_InitTypeDef gpio_init_struct2;

/*键盘扫描程序*/
int key_scan(void)
{
  Row0=1;Row1=1;Row2=1;Row3=1;
  if(Column0 || Column1 || Column2|| Column3)
  {
    LPLD_LPTMR_DelayMs(10);//10ms延时
    if(Column0 || Column1 || Column2|| Column3)
    {
      Row0=1;Row1=0;Row2=0;Row3=0;//判断第一行
      if(Column0 || Column1 || Column2|| Column3)
      { 
        if(Column0) 
        { 
          while(Column0);
          return 1;
        }
        else if(Column1) 
        { 
          while(Column1);
          return 2;
        }
        else if(Column2) 
        {
          while(Column2);
          return 3;
        }
        else if(Column3) 
        {
          while(Column3);
          return 10;
        }
        else
          return 16;
      }
      Row0=0;Row1=1;Row2=0;Row3=0;//判断第二行
      if(Column0 || Column1 || Column2|| Column3)
      {
        if(Column0) 
        {
          while(Column0);
          return 4;
        }
        else if(Column1) 
        {
          while(Column1);
          return 5;
        }
         else if(Column2) 
        {
          while(Column2);
          return 6;
        }
        else if(Column3) 
        {
          while(Column3);
          return 11;
        }
        else 
          return 16;
      
      }
      Row0=0;Row1=0;Row2=1;Row3=0;//判断第三行
      if(Column0 || Column1 || Column2|| Column3)
      {
        if(Column0) 
        {
          while(Column0);
          return 7;
        }
         else if(Column1) 
        {
          while(Column1);
          return 8;
        }
         else if(Column2) 
        {
          while(Column2);
          return 9;
        }
         else if(Column3) 
        {
          while(Column3);
          return 12;
        }
        else
          return 16;
       
      }
      Row0=0;Row1=0;Row2=0;Row3=1;//判断第四行
      if(Column0 || Column1 || Column2|| Column3)
      {
        if(Column0) 
        {
          while(Column0);
          return 0;
        }
        else if(Column1) 
        {
          while(Column1);
          return 13;
        }
        else if(Column2) 
        {
          while(Column2);
          return 14;
        }
        else if(Column3) 
        {
          while(Column3);
          return 15;
        }
        else
          return 16;
      }
    }
   else
     return 16;
  }
  else
    return 16;
}

void init_gpio1()
{
  gpio_init_struct1.GPIO_PTx = PTC;
  gpio_init_struct1.GPIO_Pins = GPIO_Pin8|GPIO_Pin9|GPIO_Pin10|GPIO_Pin11;
  gpio_init_struct1.GPIO_Dir = DIR_OUTPUT;
  gpio_init_struct1.GPIO_Output = OUTPUT_H;
  gpio_init_struct1.GPIO_PinControl = IRQC_DIS;
  LPLD_GPIO_Init(gpio_init_struct1);
}
void init_gpio2()
{
  gpio_init_struct2.GPIO_PTx = PTC;
  gpio_init_struct2.GPIO_Pins = GPIO_Pin12|GPIO_Pin13|GPIO_Pin14|GPIO_Pin15;
  gpio_init_struct2.GPIO_Dir = DIR_INPUT;
  gpio_init_struct2.GPIO_PinControl = INPUT_PULL_DOWN|IRQC_DIS;
  LPLD_GPIO_Init(gpio_init_struct2);
}
