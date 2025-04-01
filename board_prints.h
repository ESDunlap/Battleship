//File: board_prints.h

#ifndef BOARD_PRINTS_H
#define BOARD_PRINTS_H

#include <stdio.h>

#define COLUMNS 10
#define ROWS 10

int print_board(int choice, int safety, char board[ROWS][COLUMNS]);
int print_boards(int difficulty, int safety, char board_1[ROWS][COLUMNS], char board_2[ROWS][COLUMNS]);

#define MAX_BUFFER_Size 1024

#endif