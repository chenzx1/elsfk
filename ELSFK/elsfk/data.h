#pragma once
#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

/* 数据模块 */

// 界面
int windowShape[25][26] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};  // 边框为1， 游戏池长度为14

// 方块：7种*4个形态*方块数据（4*4）
int block[7][4][4][4] =
{
	{
		{{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
		{{0,1,0,0},{1,1,0,0},{1,0,0,0},{0,0,0,0}},
		{{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
		{{0,1,0,0},{1,1,0,0},{1,0,0,0},{0,0,0,0}}
	},
	{
		{{0,1,1,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
		{{1,0,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}},
		{{0,1,1,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
		{{1,0,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}}
	},
	{
		{{1,0,0,0},{1,0,0,0},{1,1,0,0},{0,0,0,0}},
		{{1,1,1,0},{1,0,0,0},{0,0,0,0},{0,0,0,0}},
		{{1,1,0,0},{0,1,0,0},{0,1,0,0},{0,0,0,0}},
		{{0,0,1,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}}
	},
	{
		{{0,1,0,0},{0,1,0,0},{1,1,0,0},{0,0,0,0}},
		{{1,0,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
		{{1,1,0,0},{1,0,0,0},{1,0,0,0},{0,0,0,0}},
		{{1,1,1,0},{0,0,1,0},{0,0,0,0},{0,0,0,0}}
	},
	{
		{{1,1,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
		{{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0}},
		{{1,1,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
		{{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0}}
	},
	{
		{{1,1,1,0},{0,1,0,0},{0,0,0,0},{0,0,0,0}},
		{{0,1,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}},
		{{0,1,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
		{{1,0,0,0},{1,1,0,0},{1,0,0,0},{0,0,0,0}}
	},
	{
		{{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
		{{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
		{{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
		{{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}}
	}
};


#endif // !DATA_H_INCLUDED
