#include "game.h"
#include "data.h"
#include "mywindows.h"

#include <stdio.h>
#include <conio.h>
#include <mmsystem.h>
#include <time.h>
#pragma comment(lib,"winmm.lib") //播放音乐头文件

/* 游戏逻辑模块实现 */

int grade = 0;
int level = 1;
int one = 0, two = 0, three = 0, four = 0; // 消除的行数
clock_t start_time;

BLOCK cur_block; // 当前方块
BLOCK next_block; // 下一个方块

// 绘制游戏池边框
void windowPrint(int x, int y)
{
	int i, j;
	for (i = 0; i < 25; i++)
	{
		for (j = 0; j < 26; j++)
		{
			if (windowShape[i][j] == 1)
			{
				setColor(0xc0);
				setPos(x + j, y + i);
				printf("%2s", "");
			}
		}
	}
}

// 游戏初始化
void gameInit()
{
	initHandle();
//	mciSendString("音乐文件路径" NULL, 0, NULL);
//	mciSendString(TEXT("play"), NULL, 0, NULL);
	printAnimation();
	gameModeChoose();
}

// 打印操作说明
void printInfo(int n)
{
	setColor(12);
	switch (n)
	{
	case 1:
		setPos(33, 9);
		printf("经典模式");
		setPos(31, 11);
		printf("1.方块匀速下落");
		setPos(31, 12);
		printf("2.方块可见");
		break;
	case 2:
		setPos(33, 9);
		printf("暴走模式");
		setPos(31, 11);
		printf("1.方块加速下落");
		setPos(31, 12);
		printf("2.方块可见");
		break;
	case 3:
		setPos(33, 9);
		printf("地狱模式");
		setPos(31, 11);
		printf("1.方块加速下落");
		setPos(31, 12);
		printf("2.方块不可见");
		break;
	}

	setColor(0x0a);
	setPos(33, 15);
	printf("操作规则");
	setPos(31, 17);
	printf("1.按 ← 或 A 左移");
	setPos(31, 18);
	printf("2.按 → 或 D 右移");
	setPos(31, 19);
	printf("3.按 ↓ 或 S 下移");
	setPos(31, 20);
	printf("4.按 ↑ 或 W 变形");
	setPos(31, 21);
	printf("5.按 回车 直接下落");
	setPos(31, 22);
	printf("6.按 空格 暂停");
}

// 打印分数和等级
void printGradeLevel(int num)
{
	switch (num)
	{
	case 0:
		break;
	case 1:
		grade += 10; one++; break;
	case 2:
		grade += 40; two++; break;
	case 3:
		grade += 60; three++; break;
	case 4:
		grade += 80; four++; break;
	}

	setColor(0x0e);
	setPos(5, 6);
	printf("分数：%d", grade);

	if (grade < 10)
		level = 1;
	else if (grade >= 10 && grade < 50)
		level = 2;
	else if (grade >= 50 && grade < 100)
		level = 3;
	else if (grade >= 100 && grade < 200)
		level = 4;
	else if (grade >= 200 && grade < 400)
		level = 5;
	else if (grade >= 400 && grade < 800)
		level = 6;
	else if (grade >= 800 && grade < 1600)
		level = 7;
	else if (grade >= 1600)
		level = 8;

	setPos(5, 7);
	switch (level)
	{
	case 1:
		printf("段位：倔强青铜"); break;
	case 2:
		printf("段位：秩序白银"); break;
	case 3:
		printf("段位：荣耀黄金"); break;
	case 4:
		printf("段位：尊贵铂金"); break;
	case 5:
		printf("段位：永恒钻石"); break;
	case 6:
		printf("段位：至尊星耀"); break;
	case 7:
		printf("段位：最强王者"); break;
	case 8:
		printf("段位：荣耀王者"); break;
	}

	setPos(5, 11);
	printf("消除一行 %d 次", one);
	setPos(5, 12);
	printf("消除二行 %d 次", two);
	setPos(5, 13);
	printf("消除三行 %d 次", three);
	setPos(5, 14);
	printf("消除四行 %d 次", four);

	time_t timep;
	struct tm* p;
	time(&timep);
	p = gmtime(&timep);

	setColor(15);
	setPos(3, 18);
	printf("Date: %d.%d.%d\n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
	setPos(3, 19);
	printf("Time: %d.%d.%d", 8 + p->tm_hour, p->tm_min, p->tm_sec);
	setPos(3, 22);
	printf("C/C++提供技术支持");
}

// 游戏计时
void gameTime(clock_t start_time)
{
	setColor(15);
	setPos(3, 3);
	printf("本次游戏已运行 %d s", (clock() - start_time) / CLOCKS_PER_SEC);
}

// 左边框
void borderLeft()
{
	setColor(0x09);
	setPos(0, 0);
	printf("□□□□□□□□□□□□□□□\n");
	printf("□                          □\n");
	printf("□                          □\n");
	printf("□                          □\n");
	printf("□                          □\n");
	printf("□                          □\n");
	printf("□                          □\n");
	printf("□                          □\n");
	printf("□                          □\n");
	printf("□                          □\n");
	printf("□                          □\n");
	printf("□                          □\n");
	printf("□                          □\n");
	printf("□                          □\n");
	printf("□                          □\n");
	printf("□                          □\n");
	printf("□                          □\n");
	printf("□                          □\n");
	printf("□                          □\n");
	printf("□                          □\n");
	printf("□                          □\n");
	printf("□                          □\n");
	printf("□                          □\n");
	printf("□                          □\n");
	printf("□□□□□□□□□□□□□□□\n");
}

// 打印方块
void printBlock(int x, int y, int shape, int status, int color)
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (block[shape][status][i][j] == 1)
			{
				setColor(color);
				setPos(x + j, y + i);
				printf("■");
			}
		}
	}
}

// 删除方块
void deleteBlock(int x, int y, int shape, int status)
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (block[shape][status][i][j] == 1)
			{
				setPos(x + j, y + i);
				printf("%2s","");
			}
		}
	}
}

// 产生游戏第一个方块
void startBlock()
{
	srand((unsigned)time(NULL));
	cur_block.x = 22;
	cur_block.y = 1;
	cur_block.shape = rand() % 7;
	cur_block.status = rand() % 4;
	cur_block.color = rand() % 0x10;

	if (cur_block.color == 0x00)
		cur_block.color = 0x0a;
	printBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status, cur_block.color);
}

// 产生下一个方块
void nextBlock()
{
	next_block.x = 33;
	next_block.y = 2;
	deleteBlock(next_block.x, next_block.y, next_block.shape, next_block.status);
	next_block.shape = rand() % 7;
	next_block.status = rand() % 4;
	next_block.color = rand() % 0x10;
	if (next_block.color == 0x00)
		next_block.color = 0x0a;
	printBlock(next_block.x, next_block.y, next_block.shape, next_block.status, next_block.color);
}

// 拷贝方块
void copyBlock()
{
	cur_block = next_block;
	cur_block.x = 22;
	cur_block.y = 1;
	printBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status, cur_block.color);
	nextBlock();
}

// 方块移动
int downBlock(int n)
{
	if (crash(cur_block.x, cur_block.y + 1, cur_block.shape, cur_block.status) == -1)
	{
		save();
		lineClear();
		updataGame(n);
		copyBlock();
		return -1;
	}
	else if (crash(cur_block.x, cur_block.y + 1, cur_block.shape, cur_block.status) == -2)
	{
		return -2;
	}
	else
	{
		deleteBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status);
		cur_block.y += 1;
		printBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status, cur_block.color);
		return 0;
	}
}
void leftBlock()
{
	if (crash(cur_block.x - 1, cur_block.y, cur_block.shape, cur_block.status) == -1)
	{
		return;
	}
	deleteBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status);
	cur_block.x -= 1;
	printBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status, cur_block.color);
}
void rightBlock()
{
	if (crash(cur_block.x + 1, cur_block.y, cur_block.shape, cur_block.status) == -1)
	{
		return;
	}
	deleteBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status);
	cur_block.x += 1;
	printBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status, cur_block.color);
}

// 方块变形
void changeBlock()
{
	if (crash(cur_block.x, cur_block.y, cur_block.shape, (cur_block.status + 1) % 4) == -1)
	{
		return;
	}
	deleteBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status);
	cur_block.status = (cur_block.status + 1) % 4;
	printBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status, cur_block.color);
}

// 方块直接落地
void bottomBlock(int n)
{
	while (1) {
		if (crash(cur_block.x, cur_block.y + 1, cur_block.shape, cur_block.status) == -1)
		{
			save();
			lineClear();
			updataGame(n);
			copyBlock();
			return;
		}
		else if (crash(cur_block.x, cur_block.y + 1, cur_block.shape, cur_block.status) == -2)
		{
			return;
		}
		else
		{
			++cur_block.y;
		}
	}
}

// 碰撞检测
int crash(int x, int y, int shape, int status)
{
	//基于下一个位置的检测，方块均是下一个位置或形态
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (block[shape][status][i][j] == 1)
			{
				if (windowShape[i + y][j + x - 15] == 1)
				{
					// 发生碰撞
					if (cur_block.x == 22 && cur_block.y == 1)
					{
						// 方块产生就发生了碰撞，游戏结束
						return -2;
					}
					// 方块落到游戏池底部
					return -1;
				}
			}
		}
	}
	return 0;
}

// 保存方块
void save()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (block[cur_block.shape][cur_block.status][i][j] == 1)
			{
				windowShape[i + cur_block.y][j + cur_block.x - 15] = 1;
			}
		}
	}
}

// 刷新游戏池
void updataGame(int n)
{
	int i, j;
	for (i = 23; i > 0; i--)
	{
		for (j = 1; j < 15; j++)
		{
			switch (n) 
			{
			case 1:
				if (windowShape[i][j] == 1)
				{
					setColor(0x0e);
					setPos(15 + j, i);
					printf("■");
				}
				else
				{
					setColor(0x00);
					setPos(15 + j, i);
					printf("%2s","");
				}
				break;
			case 2:
				if (windowShape[i][j] == 1)
				{
					setColor(0x0e);
					setPos(15 + j, i);
					printf("%2s", "");
				}
				else
				{
					setColor(0x00);
					setPos(15 + j, i);
					printf("%2s", "");
				}
				break;
			}
			
		}
	}
}

// 游戏暂停
void pause()
{
	while (1)
	{
		if (getch() == 32)
		{
			break;
		}
	}
}

// 消行
void lineClear()
{
	int i, j;
	int number = 0;
	for (i = 23; i > 0; i--)
	{
		int total = 0;
		for (j = 1; j < 15; j++)
		{
			total += windowShape[i][j];
		}
		// 满行执行消行
		if (total == 14)
		{
			lineDown(i);
			i += 1;
			number += 1;
		}
	}
	printGradeLevel(number);
}
void lineDown(int line)
{
	int i, j;
	for (i = line; i > 1; i--)
	{
		for (j = 1; j < 15; j++)
		{
			windowShape[i][j] = windowShape[i - 1][j];
		}
	}
}

// 游戏结束动画
void printOver()
{
	int i, j;
	for (i = 23; i > 0; i--)
	{
		for (j = 1; j < 15; j++)
		{
			setColor(0x2e);
			setPos(j + 15, i);
			printf("☆");
			Sleep(5);
		}
	}
}

// 游戏重新开始提示
void printFinish()
{
	setColor(0x0f);
	setPos(20, 8);
	printf("游戏结束！");
	setPos(20, 10);
	printf("按Y重新开始！");
	setPos(20, 11);
	printf("按N结束游戏！");

	switch (getch())
	{
	case 'y':
	case 'Y':
		againGame(); break;
	case 'n':
	case 'N':
		mciSendString(TEXT("stop a"), NULL, 0, NULL);
		endGame(); break;
	default:
		printFinish();
	}
}

// 重新开始游戏
void againGame()
{
	grade = 0;
	level = 1;
	one = 0, two = 0, three = 0, four = 0;
	int i, j;
	for (i = 1; i < 24; i++)
	{
		for (j = 1; j < 15; j++)
		{
			windowShape[i][j] = 0;
		}
	}
	system("cls");
	gameInit();
}

// 游戏结束界面
void endGame()
{
	system("cls");

	setColor(12);
	setPos(21, 8);
	printf("游戏结束！");

	setPos(21, 10);
	printf("分数：%d",grade);

	setPos(21, 12);
	switch (level)
	{
	case 1:
		printf("段位：倔强青铜"); break;
	case 2:
		printf("段位：秩序白银"); break;
	case 3:
		printf("段位：荣耀黄金"); break;
	case 4:
		printf("段位：尊贵铂金"); break;
	case 5:
		printf("段位：永恒钻石"); break;
	case 6:
		printf("段位：至尊星耀"); break;
	case 7:
		printf("段位：最强王者"); break;
	case 8:
		printf("段位：荣耀王者"); break;
	}

	setPos(21, 14);
	printf("消除一行 %d 次", one);
	setPos(21, 16);
	printf("消除二行 %d 次", two);
	setPos(21, 18);
	printf("消除三行 %d 次", three);
	setPos(21, 20);
	printf("消除四行 %d 次", four);

	setPos(21, 22);
	printf("本次游戏运行共 %d s", (clock() - start_time) / CLOCKS_PER_SEC);

	int i;
	setPos(23, 2);
	setColor(6);
	printf("\\\\\\|///");

	setPos(23, 3);
	printf("\\\\");

	setPos(24, 3);
	setColor(15);
	printf(".-.-");

	setPos(26, 3);
	setColor(6);
	printf("//");

	setPos(23, 4);
	setColor(14);
	printf("(");

	setPos(24, 4);
	setColor(15);
	printf(".@.@");

	setPos(27, 4);
	setColor(14);
	printf(")");

	setPos(8, 5);
	setColor(11);
	printf("+-----------------------");

	setPos(17, 5);
	setColor(14);
	printf("o00o");

	setPos(19, 5);
	setColor(11);
	printf("---------");

	setPos(24, 5);
	setColor(14);
	printf("(-)");

	setPos(26, 5);
	setColor(11);
	printf("---------");

	setPos(30, 5);
	setColor(14);
	printf("o00o");

	setPos(32, 5);
	setColor(11);
	printf("------------------+");

	for (i = 6; i <= 24; i++)
	{
		setPos(8, i);
		printf("|");
		setPos(41, i);
		printf("|");
	}

	setPos(8, 25);
	printf("+-------------------------------");

	setPos(24, 25);
	setColor(14);
	printf("☆☆☆");

	setPos(27, 25);
	setColor(11);
	printf("----------------------------+\n\n");

	_getch();
	exit(0);
}

// 打印开始图案
void printStart(int x, int y)
{
	int color = rand() % 0x10; // 随机图案颜色
	if (color == 0x00)
	{
		color = 0x0f;
	}
	// 绘制图案
	setColor(color);
	setPos(x, y);
	printf("■■■■■ ■■■■■ ■■■■■ ■■■■ ■■■ ■■■■");
	setPos(x, y + 1);
	printf("    ■     ■             ■     ■    ■   ■   ■");
	setPos(x, y + 2);
	printf("    ■     ■■■■       ■     ■■■■   ■    ■■■");
	setPos(x, y + 3);
	printf("    ■     ■             ■     ■  ■     ■          ■");
	setPos(x, y + 4);
	printf("    ■     ■■■■       ■     ■    ■ ■■■ ■■■■");

	setPos(25, 15);
	printf("按Enter键开始游戏！");
}

// 消除开始动画
void deleteStart(int x, int y)
{
	int i, j;
	for (i = y; i <= y + 5; i++)
	{
		for (j = x; j < x + 35; j++)
		{
			setPos(j, i);
			printf("%2s", "");
		}
	}
}

// 动画效果->定时（边界）
void printAnimation()
{
	clock_t time1, time2;
	time1 = clock();
	int x = 5;
	printStart(x, 5);
	while (1)
	{
		time2 = clock();
		if (time2 - time1 > 200)
		{
			time1 = time2;
			deleteStart(x, 5);
			printStart(++x, 5);
			if (x == 22)
			{
				deleteStart(x, 5);
				x = 5;
			}
		}
		//按Enter键开始游戏，退出动画
		if (kbhit())
		{
			if (getch() == 13) break;
			else
			{
				setPos(22, 17);
				int color = rand() % 0x10;
				if (color == 0x00) color = 0x0f;
				printf("输入有误！请按Enter键开始游戏!");
				_getch();
				system("cls");
			}
		}
	}
	system("cls");
}

// 游戏模式
void gameMode(float time, int n)
{
	clock_t startTime = clock();
	clock_t time1, time2;
	time1 = clock();

	while (1)
	{
		if (kbhit())
		{
			switch (getch())
			{
			case 'w':
			case 'W':
				changeBlock(); break;
			case 'a':
			case 'A':
				leftBlock(); break;
			case 'd':
			case 'D':
			case 77:
				rightBlock(); break;
			case 's':
			case 'S':
			case 80:
				downBlock(n); break;
			case 32:
				pause(); break;
			case 13:
				bottomBlock(n); break;
			}
		}
		time2 = clock();
		//每0.65秒下落一次，clock获得的时间转为秒需要除以CLOCKS_PER_SEC
		if (time2 - time1 > time * CLOCKS_PER_SEC)
		{
			gameTime(startTime);
			if (downBlock(n) == -2)
			{
				break;
			}
			time1 = time2;
		}
	}
}

// 游戏模式选择界面
void gameModeChoose()
{
	system("cls");

	int i;
	setPos(23, 2);
	setColor(6);
	printf("\\\\\\|///");

	setPos(22, 3);
	printf("\\\\");

	setPos(24, 3);
	setColor(15);
	printf(".-.-");

	setPos(27, 3);
	setColor(6);
	printf("//");

	setPos(22, 4);
	setColor(14);
	printf("(");

	setPos(24, 4);
	setColor(15);
	printf(".@.@");

	setPos(27, 4);
	setColor(14);
	printf(")");

	setPos(8, 5);
	setColor(11);
	printf("+--------------------");

	setPos(17, 5);
	setColor(14);
	printf("o00o");

	setPos(19, 5);
	setColor(11);
	printf("---------");

	setPos(24, 5);
	setColor(14);
	printf("(_)");

	setPos(26, 5);
	setColor(11);
	printf("---------");

	setPos(31, 5);
	setColor(14);
	printf("o00o");

	setPos(33, 5);
	setColor(11);
	printf("----------------+");

	for (i = 6; i <= 24; i++)
	{
		setPos(8, i);
		printf("|");
		setPos(41, i);
		printf("|");
	}

	setPos(8, 25);
	printf("+--------------------------");

	setPos(23, 25);
	setColor(14);
	printf("☆☆☆");

	setPos(28, 25);
	setColor(11);
	printf("--------------------------\n\n");

	setPos(20, 9);
	setColor(11);
	printf("俄罗斯方块模式选择");

	setPos(12, 15);
	setColor(12);
	printf("1.普通模式");
	setPos(22, 15);
	printf("2.暴走模式");
	setPos(32, 15);
	printf("3.地狱模式");

	setPos(21, 22);
	setColor(3);
	printf("请选择 1 2 3：");
	setColor(14);

	int n;
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:
		system("cls");

		windowPrint(15, 0);
		printInfo(n);
		borderLeft();
		printGradeLevel(0);
		startBlock();
		nextBlock();
		gameMode(0.65, 1);
		printOver();
		printFinish();
		break;
	case 2:
		system("cls");

		windowPrint(15, 0);
		printInfo(n);
		borderLeft();
		printGradeLevel(0);
		startBlock();
		nextBlock();
		gameMode(0.15, 1);
		printOver();
		printFinish();
		break;
	case 3:
		system("cls");

		windowPrint(15, 0);
		printInfo(n);
		borderLeft();
		printGradeLevel(0);
		startBlock();
		nextBlock();
		gameMode(0.15, 2);
		printOver();
		printFinish();
		break;
	default:
		setColor(12);
		setPos(21, 23);
		printf("请输入1~3之间的数！");
		_getch();
		system("cls");
		gameModeChoose();
	}
}
