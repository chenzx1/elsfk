#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include "game.h"
int main() {
	//HANDLE g_ConsoleOutPut;  // ���þ������
	//g_ConsoleOutPut = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ�������������Ϊ��׼���ģʽ
	//SetConsoleTextAttribute(g_ConsoleOutPut, FOREGROUND_BLUE);  // ����������ɫΪ��ɫ
	//printf("welcome");

	//kbhit();  //������̨�����Ƿ��а��������º�getch���ʹ��
	//getch();  //��ȡ����

	//CloseHandle(g_ConsoleOutPut);
	gameInit();
	return 0;
}