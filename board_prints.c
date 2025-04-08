#include "board_prints.h"

/*
	File: board_prints.c
	Author: Kaeden Daly
	Course: CS125
	Assignement: Final Project
	Date: 02/26/25
	References: Google
*/

/*
  choice: What the owner of the board is
  safety: 0 is safe and hides ships, 1 is unsafe and shows ships
  boards: The boards for the players
*/

//Will print one board
int print_board(int choice, int safety, char board[ROWS][COLUMNS])
{
  switch(choice)
  {
  case 0:
    break;
  case 2:
    printf("Player's board: \n");
    break;
  case 1:
    printf("Player 1's board: \n");
    break;
  case -1:
    printf("Player 2's board: \n");
    break;
  case -2:
    printf("AI's board: \n");
    break;
  }
  printf("\033[0m");
  int row, col;
  printf("   - A ");
  for(col = 1; col < COLUMNS; col++)
  {
    printf("| %c ", (char)(65 + col));
  }
  printf("-\n");
  for(row = 0; row < ROWS; row++)
  {
    for(col = -1; col < COLUMNS; col++)
    {
      printf("----");
    }
    printf("\n");
    if(row <= 8) { printf(" %d ", row + 1); }
    else { printf("%d ", row + 1); } 
    for(col = 0; col < COLUMNS; col++)
    {
      printf("|");
      if(board[row][col] == 'W') { printf("\033[0;34m"); }
      else if(board[row][col] == 'S') { printf("\033[0;35m"); }
      else if(board[row][col] == 'M') { printf("\033[0;33m"); }
      else if(board[row][col] == 'H') { printf("\033[0;31m"); }
      if(safety)
      {
        printf(" %c ", board[row][col]);
      }
      else
      {
        if(board[row][col] == 'S') 
        { 
          printf("\033[0;34m"); 
          printf(" %c ", 'W');
        }
        else
        {
          printf(" %c ", board[row][col]);
        }
      }
      printf("\033[0m");
    }
    printf("|\n");
  }
  for(col = -1; col < COLUMNS; col++)
  {
    printf("----");
  }
  printf("\n");
  printf("\n\n\n");

	return 0;
}

//Will print both boards
int print_boards(int difficulty, int safety, char board_1[ROWS][COLUMNS], char board_2[ROWS][COLUMNS])
{
  print_board(difficulty, safety, board_1);
  print_board(-difficulty, safety, board_2);

  return 0;
}

/*
int main()
{
  char board[ROWS][COLUMNS];
  int row, col;
  for(row = 0; row < ROWS; row++)
  {
    for(col = 0; col < COLUMNS; col++)
    {
      board[row][col] = (char)(65 + row + col);
    }
  }
  print_board(-1, 0, board);
  printf("\na\n");
  print_board(1, 1, board);
}
*/