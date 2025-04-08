#include "game_manager.h"

/*
	File: game_manager.c
	Authors: Kaeden Daly, Erik Dunlap
	Course: CS125
	Assignement: Final Project
	Date: 03/31/25
	References: 
*/

int main()
{
  printf("Welcome to Battleship\n");
  printf("By Kaeden Daly and Erik Dunlap\n\n");
  
  int restart = 1;
  
  while(restart)
  {
    clearScreen();
    int difficulty;
    printf("Please choose difficulty\n\n");
    printf("Type \"1\" for Player vs Player\n");
    printf("Type \"2\" for Easy AI\n"); //Completely Random
    printf("Type \"3\" for Medium AI\n"); //Random then adjacent Tiles
    printf("Type \"4\" for Hard AI\n"); //Random then known Ships Tiles
    printf("Type \"5\" for Very Hard AI\n"); //Known Ship Tiles
    printf("Type \"6\" for Impossible AI\n"); //Known Ship Tiles, Goes First
    printf("...: ");
    while(scanf("%d", &difficulty) != 1 || difficulty < 1 || difficulty > 6)
    {
    	while (getchar()!= '\n');
      printf("Error: Invalid input\n");
      printf("Please Try Again: ");
    }
    while (getchar()!= '\n');
    clearScreen();
    char player1[ROWS][COLUMNS];
    char player2[ROWS][COLUMNS];
    char ai[ROWS][COLUMNS];
    
    //printf("\n\n\n");
    
    switch(difficulty)
    {
      case 1:
      {
      	createArray(player1);
  			createArray(player2);
  			
        printf("Player 1: \n\n");
        fullPlacementLoop(player1);
        
        printf("Player 2: \n\n");
        fullPlacementLoop(player2);
        
        game(player1, player2);
        break;
      }
      case 2:
      {
      }
      case 3:
      {
      }
      case 4:
      {
      }
      case 5:
      {
      	createArray(player1);
  			createArray(ai);
  			
        printf("Player: \n\n");
        fullPlacementLoop(player1);
        aiPlacementLoop(ai);
        
        aiGame(player1, ai, difficulty);
        break;
      }
      case 6:
      {
      	createArray(player1);
  			createArray(ai);
  			
        printf("Player: \n\n");
        fullPlacementLoop(player1);
        aiPlacementLoop(ai);
        
        printf("\033[0;32m");
        printf("AI Turn: \n\n");
        aiLevel4Turn(player1);
        printf("\033[0;31m");
        print_board(-2, 1, player1);
        aiGame(player1, ai, difficulty);
        break;
      }
    }
    
    while(1)
    {
      printf("Play Again (Y/N): ");
      char userInput;
      while(scanf(" %c", &userInput) == 0)
      {
        printf("Invalid Character\n");
        while(getchar()!= '\n');
      }
      userInput = tolower(userInput);
      
      if(userInput == 'y')
      {
        restart = 1;
        clearScreen();
        break;
      }
      else if(userInput == 'n')
      {
        clearScreen();
        printf("\n\nApplication Shutting Down\n\n");
        restart = 0;
        break;
      }
      else
      {
        printf("Error: Invalid Input\n");
      }
    }
  }
  
}