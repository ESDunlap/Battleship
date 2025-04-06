#ifndef AILEVELS_H
#define AILEVELS_H

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "fire_input.h"

#define COLUMNS 10
#define ROWS 10

int aiLevel1Turn(char userBoard[ROWS][COLUMNS]);
int aiLevel2Turn(char userBoard[ROWS][COLUMNS], int* searchRow, int* searchColumn, int* directionSearch);
int aiLevel3Turn(char userBoard[ROWS][COLUMNS], int* searchRow, int* searchColumn);
int aiLevel4Turn(char userBoard[ROWS][COLUMNS]);
void aiGame(char playerBoard[ROWS][COLUMNS], char aiBoard[ROWS][COLUMNS], int aiLevel);

#define MAX_BUFFER_SIZE 1024

#endif