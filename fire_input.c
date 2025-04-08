#include "fire_input.h"

/*
	File: fire_input.c
	Author: Kaeden Daly
	Course: CS125
	Assignement: Final Project
	Date: 03/31/25
	References: 
*/


int ask_fire(char board[ROWS][COLUMNS])
{
  int row, col;
  fail_fire:
  printf("Type the row to fire at: ");
  row = validIntInput() - 1;
  printf("Type the column to fire at: ");
  col = validColInput();
  
  int output;
  output = fire_and_check(row, col, board);
  
  if(output == -1)
  {
    printf("Tile has already been shot\n");
    printf("Please try again\n");
    goto fail_fire;
  }
  return output;
}

void game(char board1[ROWS][COLUMNS], char board2[ROWS][COLUMNS])
{
  int turns = 0, output = 0;
  while(output == 0)
  {
    turns++;
    printf("\n\n\n");
    if(turns % 2 == 1)
    {
      printf("Player 1's Turn\n\n");
      print_board(-1, 0, board2);
      output = ask_fire(board2);
    }
    else
    {
      printf("Player 2's Turn\n\n");
      print_board(1, 0, board1);
      output = ask_fire(board1);
    }
  }
  if(output == 1)
  {
    switch(turns % 2)
    {
    case 0:
      printf("Player 2 Wins\n");
      break;
    case 1:
      printf("Player 1 Wins\n");
      break;
    }
    print_boards(1, 1, board1, board2);
  }
  else
  {
    printf("Error: Invalid Outcome");
  }

}