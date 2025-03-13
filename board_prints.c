#include <stdio.h>
#include "board_prints.h"

/*
	File: board_prints.c
	Author: Kaeden Daly
	Course: CS125
	Assignement: Final Project
	Date: 02/26/25
	References: Google
*/

//
int print_board(int choice, int safety,  char board[10][10])
{
  switch(choice)
  {
  case 0:
    break;
  case 1:
    printf("Player 1's board: \n");
    break;
  case -1:
    printf("Player 2's board: \n");
    break;
  }
  int row, col;
  printf("   - A | B | C | D | E | F | G | H | I | J -\n");
  for(row = 0; row < 10; row++)
  {
    printf("--------------------------------------------\n");
    if(row != 9) { printf(" %d ", row + 1); }
    else { printf("%d ", row + 1); } 
    for(col = 0; col < 10; col++)
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
  printf("--------------------------------------------\n");
  printf("\n\n\n");

	return 0;
}

int print_boards(int difficulty, int safety, char board_1[10][10], char board_2[10][10])
{
  print_board(difficulty, safety, board_1);
  print_board(-difficulty, safety, board_2);

  return 0;
}

/*
int main()
{
  char board[10][10] = {{'W', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}, {'S', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}, {'M', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}, {'H', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}, {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}, {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}, {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}, {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}, {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}, {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}};
  print_board(-1, 0, board);
  printf("\na\n");
  print_board(1, 1, board);
}
*/