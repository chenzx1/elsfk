#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include "game.h"
int main() {
	//HANDLE g_ConsoleOutPut;  // 设置句柄变量
	//g_ConsoleOutPut = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取句柄，参数设置为标准输出模式
	//SetConsoleTextAttribute(g_ConsoleOutPut, FOREGROUND_BLUE);  // 设置字体颜色为蓝色
	//printf("welcome");

	//kbhit();  //检测控制台窗口是否有按键被按下和getch组合使用
	//getch();  //获取按键

	//CloseHandle(g_ConsoleOutPut);
	gameInit();
	return 0;
}