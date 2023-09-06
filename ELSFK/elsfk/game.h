#pragma once
#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

/* ��Ϸ�߼�ģ�� */

#include <stdio.h>
#include <time.h>

// ����ṹ��
typedef struct {
	int x;
	int y;
	int shape;
	int status;
	int color;
}BLOCK;

// ������Ϸ�ر߿�
void windowPrint(int x, int y);

// ��Ϸ��ʼ��
void gameInit();

// ��ӡ����˵��
void printInfo(int n);

// ��ӡ�����͵ȼ�
void printGradeLevel(int num);

// ��Ϸ��ʱ
void gameTime(clock_t start_time);

// ��߿�
void borderLeft();

// ��ӡ����
void printBlock(int x, int y, int shape, int status, int color);

// ɾ������
void deleteBlock(int x, int y, int shape, int status);

// ������Ϸ��һ������
void startBlock();

// ������һ������
void nextBlock();

// ��������
void copyBlock();

// �����ƶ�
int downBlock(int n);
void leftBlock();
void rightBlock();

// �������
void changeBlock();

// ����ֱ�����
void bottomBlock(int n);

// ��ײ���
int crash(int x, int y, int shape, int status);

// ���淽��
void save();

// ˢ����Ϸ��
void updataGame(int n);

// ��Ϸ��ͣ
void pause();

// ����
void lineClear();
void lineDown(int line);

// ��Ϸ��������
void printOver();

// ��Ϸ���¿�ʼ��ʾ
void printFinish();

// ���¿�ʼ��Ϸ
void againGame();

// ��Ϸ��������
void endGame();

// ��ӡ��ʼͼ��
void printStart(int x, int y);

// ������ʼ����
void deleteStart(int x, int y);

// ����Ч��->��ʱ���߽磩
void printAnimation();

// ��Ϸģʽ
void gameMode(float time, int n);

// ��Ϸģʽѡ�����
void gameModeChoose();

#endif // !GAME_H_INCLUDED
