#include "DBG_uart.h"
#include "lcd_cfg.h"
#include "redef_print.h"
#include <stdio.h>

//重定义putchar函数，将终端显示改到PC端LCDTest.exe小工具上
//这样在调用printf格式输出函数时，就能将字符打印输出到PC端LCDTest.exe上
//char putc (char c, FILE *f)
//{        
//	Send_CharToCpu(c);
//	return 0;
//}										

#pragma import(__use_no_semihosting)
/******************************************************************************  
*标准库需要的支持函数
******************************************************************************/  
struct __FILE  
{  
int handle;  
/* Whatever you require here. If the only file you are using is */  
/* standard output using printf() for debugging, no file handling */  
/* is required. */  
};  
/* FILE is typedef� d in stdio.h. */  
FILE __stdout;  

/// <summary>  
/// 定义_sys_exit()以避免使用半主机模式
/// </summary>  
/// <param name="x"></param>  
/// <returns></returns>  
void _sys_exit(int x)  
{  
x = x;  
}  

 

int fputc(int ch, FILE *f)
{ 
    DBG_UART_TxChar(ch);
    return ch; 
}   
