#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3
//函数声明
void Initboard(char board[ROW][COL], int row, int col);
void Display(char board[ROW][COL], int row, int col);
void Playermove(char board[ROW][COL], int row, int col);//玩家移动
void Computermove(char board[ROW][COL], int row, int col);//电脑移动
char Iswin(char board[ROW][COL], int row, int col);//判断输赢