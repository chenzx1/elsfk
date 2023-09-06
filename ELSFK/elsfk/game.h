#pragma once
#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

/* 游戏逻辑模块 */

#include <stdio.h>
#include <time.h>

// 方块结构体
typedef struct {
	int x;
	int y;
	int shape;
	int status;
	int color;
}BLOCK;

// 绘制游戏池边框
void windowPrint(int x, int y);

// 游戏初始化
void gameInit();

// 打印操作说明
void printInfo(int n);

// 打印分数和等级
void printGradeLevel(int num);

// 游戏计时
void gameTime(clock_t start_time);

// 左边框
void borderLeft();

// 打印方块
void printBlock(int x, int y, int shape, int status, int color);

// 删除方块
void deleteBlock(int x, int y, int shape, int status);

// 产生游戏第一个方块
void startBlock();

// 产生下一个方块
void nextBlock();

// 拷贝方块
void copyBlock();

// 方块移动
int downBlock(int n);
void leftBlock();
void rightBlock();

// 方块变形
void changeBlock();

// 方块直接落地
void bottomBlock(int n);

// 碰撞检测
int crash(int x, int y, int shape, int status);

// 保存方块
void save();

// 刷新游戏池
void updataGame(int n);

// 游戏暂停
void pause();

// 消行
void lineClear();
void lineDown(int line);

// 游戏结束动画
void printOver();

// 游戏重新开始提示
void printFinish();

// 重新开始游戏
void againGame();

// 游戏结束界面
void endGame();

// 打印开始图案
void printStart(int x, int y);

// 消除开始动画
void deleteStart(int x, int y);

// 动画效果->定时（边界）
void printAnimation();

// 游戏模式
void gameMode(float time, int n);

// 游戏模式选择界面
void gameModeChoose();

#endif // !GAME_H_INCLUDED
