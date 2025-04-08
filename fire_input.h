//File: fire_input.h

#ifndef FIRE_INPUT_H
#define FIRE_INPUT_H

#include <stdio.h>
#include "fire_shot.h"
#include "board_prints.h"
#include "battleShipPlacement.h"

#define COLUMNS 10
#define ROWS 10

int ask_fire(char board[ROWS][COLUMNS]);
void game(char board1[ROWS][COLUMNS], char board2[ROWS][COLUMNS]);

#define MAX_BUFFER_Size 1024

#endif