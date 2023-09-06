#pragma once
#ifndef WINDOWS_H_INCLUDED
#define WINDOWS_H_INCLUDED

/* 系统调用模块 */
#include <Windows.h>

void initHandle(); // 初始化句柄
void setColor(int color); // 设置颜色
void setPos(int x, int y); // 设置光标位置
void hideCursor(); // 隐藏光标



#endif // !WINDOWS_H_INCLUDED
