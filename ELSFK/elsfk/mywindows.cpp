#include "mywindows.h"

/* ʵ��ϵͳ����ģ�� */

HANDLE handle;
// ��ʼ�����
void initHandle()
{
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	hideCursor();
}
// ������ɫ
void setColor(int color)
{
	SetConsoleTextAttribute(handle, color);
}
// ���ù��λ��
void setPos(int x, int y)
{
	COORD coord = { x * 2,y };
	SetConsoleCursorPosition(handle, coord);
}
// ���ع��
void hideCursor()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false; // ���ù���Ƿ�ɼ�
	info.dwSize = 1; // ���ù���ȣ�0~100��
	SetConsoleCursorInfo(handle, &info);
}