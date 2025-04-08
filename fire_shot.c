#include "fire_shot.h"

/*
	File: fire_shot.c
	Author: Kaeden Daly
	Course: CS125
	Assignement: Final Project
	Date: 03/24/25
	References: 
*/

//Returns one if position is already hit and replaces Water with Miss and Ship with Hit then returns 0
int fire(int row, int col, char board[ROWS][COLUMNS])
{
  if(board[row][col] == 'M' || board[row][col] == 'H')
  {
    return 1; 
  }
  if(board[row][col] == 'W')
  {
    board[row][col] = 'M';
  }
  else if(board[row][col] == 'S')
  {
    board[row][col] = 'H';
  }
  return 0;
}

//Will call the fire function, return -1 if failed to fire, detect if there are any remaining ships (Yes-0, No-1)
int fire_and_check(int rowB, int colB, char board[ROWS][COLUMNS])
{
  if(fire(rowB, colB, board))
  {
    return -1;
  }
  int row, col;
  for(row = 0; row < ROWS; row++)
  {
    for(col = 0; col < COLUMNS; col++)
    {
      if(board[row][col] == 'S')
      {
        return 0; //Ship is found
      }
    }
  }
  return 1; //No ship is found
}
