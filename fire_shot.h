//File: fire_shot.h

#ifndef FIRE_SHOT_H
#define FIRE_SHOT_H

#define COLUMNS 10
#define ROWS 10

int fire(int row, int col, char board[ROWS][COLUMNS]);
int fire_and_check(int rowB, int colB, char board[ROWS][COLUMNS]);

#define MAX_BUFFER_Size 1024

#endif