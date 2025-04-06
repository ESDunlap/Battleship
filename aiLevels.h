#ifndef AILEVELS_H
#define AILEVELS_H

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define COLUMNS 10
#define ROWS 10

int fire(int row, int col, char board[ROWS][COLUMNS]);
int fire_and_check(int rowB, int colB, char board[ROWS][COLUMNS]);
int aiLevel1Turn(char userBoard[ROWS][COLUMNS]);
int aiLevel2Turn(char userBoard[ROWS][COLUMNS], int* searchRow, int* searchColumn, int* directionSearch);
int aiLevel3Turn(char userBoard[ROWS][COLUMNS], int* searchRow, int* searchColumn);
int aiLevel4Turn(char userBoard[ROWS][COLUMNS]);

#define MAX_BUFFER_SIZE 1024

#endif