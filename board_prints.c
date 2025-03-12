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
int print_board(int choice, char board[10][10])
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
      if(board[row][col] == 'W' || board[row][col] == 'S') { printf("\033[0;34m"); }
      else if(board[row][col] == 'M') { printf("\033[0;33m"); }
      else if(board[row][col] == 'H') { printf("\033[0;31m"); }
      printf(" %c ", board[row][col]);
      printf("\033[0m");
    }
    printf("|\n");
  }
  printf("--------------------------------------------\n");
  printf("\n\n\n");

	return 0;
}

int print_boards(int difficulty, char board_1[10][10], char board_2[10][10])
{
  print_board(difficulty, board_1);
  print_board(-difficulty, board_2);

  return 0;
}

/*
int main()
{
  char board[10][10] = {{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}, {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}, {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}, {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}, {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}, {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}, {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}, {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}, {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}, {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}};
  print_board(-1, board);
  printf("\na\n");
  print_boards(1, board, board);
}
*/