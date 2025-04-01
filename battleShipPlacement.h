//File: battleShipPlacement.h

#ifndef BATTLESHIPPLACEMENT_H
#define BATTLESHIPPLACEMENT_H

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "board_prints.h"

#define COLUMNS 10
#define ROWS 10

void clearScreen();
int validIntInput();
int validColInput();
int aiShipPlacement(int currentShipSize, char array[ROWS][COLUMNS]);
int shipPlacement(int currentShipSize, char array[ROWS][COLUMNS]);
int fullPlacementLoop(char array[ROWS][COLUMNS]);
int aiPlacementLoop(char array[ROWS][COLUMNS]);

#define MAX_BUFFER_SIZE 1024

#endif