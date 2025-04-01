#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#define COLUMNS 10
#define ROWS 10

void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

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

int validIntInput()
{
    int userInput;
    while (scanf("%d", &userInput)== 0)
    {
        printf("Invalid Input\n");
        while (getchar()!= '\n');
    }
    return userInput;
}

int validColInput()
{
    char userInput;
    int userNumber;
    while (getchar()!= '\n');
    while (scanf("%c", &userInput) == 0)
    {
        printf("Invalid Character\n");
        while (getchar()!= '\n');
    }
    userInput= tolower(userInput);
    userNumber = (int) userInput - 97;
    return userNumber;
}
int aiShipPlacement(int currentShipSize, char array[ROWS][COLUMNS])
{
    int unplacedShip= 1;
    int selectedRow;
    int selectedColumn;
    int directionVar;
    int i;
    int validPlacement;
    while (unplacedShip)
    {
        validPlacement=1;
        selectedRow= rand()%10;
        selectedColumn= rand()%10;
        directionVar= rand()%2 + 1;
        switch (directionVar)
        {
        case 1:
        {
            if (selectedColumn + currentShipSize > 9)
            {
                break;
            }
            for (i=selectedColumn; i < selectedColumn + currentShipSize; i++)
            {
                if (array[selectedRow][i] != 'W')
                {
                    validPlacement= 0;
                    break;
                }
            }
            if (validPlacement)
            {
                for (i=selectedColumn; i < selectedColumn + currentShipSize; i++)
                {
                    array[selectedRow][i] = 'S';
                }
                unplacedShip= 0;
            }
        }
        case 2:
        {
            if (selectedRow + currentShipSize > 9)
            {
                break;
            }
            for (i=selectedRow; i < selectedRow + currentShipSize; i++)
            {
                if (array[i][selectedColumn] != 'W')
                {
                    validPlacement= 0;
                    break;
                }
            }
            if (validPlacement)
            {
                for (i=selectedRow; i < selectedRow + currentShipSize; i++)
                {
                    array[i][selectedColumn] = 'S';
                }
                unplacedShip= 0;
            }
        }
        }
    }
    //print_board(int difficulty, array array);
    return 0;
}

int shipPlacement(int currentShipSize, char array[ROWS][COLUMNS])
{
    int unplacedShip= 1;
    int selectedRow;
    int selectedColumn;
    int directionVar;
    int i;
    int validPlacement;
    while (unplacedShip)
    {
        validPlacement=1;
        do
        {
            printf("Which row to start?\n");
            selectedRow= validIntInput() - 1;
            if (selectedRow > 9 || selectedRow < 0)
            {
                printf("Invalid Number\n");
            }
        }
        while (selectedRow > 9 || selectedRow < 0);
        do
        {
            printf("Which column?\n");
            selectedColumn= validColInput();
            if (selectedColumn > 9 || selectedColumn < 0)
            {
                printf("Invalid Number\n");
            }
        }
        while (selectedColumn > 9 || selectedColumn < 0);
        do
        {
            printf("Which direction?\n(1 for horizontal)\n(2 for vertical)\n");
            directionVar= validIntInput();
            if (directionVar > 2 || directionVar < 1)
            {
                printf("Invalid Number\n");
            }
        }
        while (directionVar > 2 || selectedRow < 1);
        switch (directionVar)
        {
        case 1:
        {
            if (selectedColumn + currentShipSize > 10)
            {
                printf("Invalid Placement\n");
                break;
            }
            for (i=selectedColumn; i < selectedColumn + currentShipSize; i++)
            {
                if (array[selectedRow][i] != 'W')
                {
                    printf("Invalid Placement\n");
                    validPlacement= 0;
                    break;
                }
            }
            if (validPlacement)
            {
                for (i=selectedColumn; i < selectedColumn + currentShipSize; i++)
                {
                    array[selectedRow][i] = 'S';
                }
                unplacedShip= 0;
            }
            break;
        }
        case 2:
        {
            if (selectedRow + currentShipSize > 10)
            {
                printf("Invalid Placement\n");
                break;
            }
            for (i=selectedRow; i < selectedRow + currentShipSize; i++)
            {
                if (array[i][selectedColumn] != 'W')
                {
                    printf("Invalid Placement\n");
                    validPlacement= 0;
                    break;
                }
            }
            if (validPlacement)
            {
                for (i=selectedRow; i < selectedRow + currentShipSize; i++)
                {
                    array[i][selectedColumn] = 'S';
                }
                unplacedShip= 0;
            }
            break;
        }
        }
    }
    print_board(0, 1, array);
    return 0;
}

int fullPlacementLoop(char array[ROWS][COLUMNS]) 
{
    print_board(0, 1, array);
    printf("Place your Carrier: Size 5\n");
    shipPlacement(5, array);
    printf("Place your Battleship: Size 4\n");
    shipPlacement(4, array);
    printf("Place your Destroyer: Size 3\n");
    shipPlacement(3, array);
    printf("Place your Submarine: Size 3\n");
    shipPlacement(3, array);
    printf("Place your Patrol Boat: Size 2\n");
    shipPlacement(2, array);
    clearScreen();
    return 0;
}

int aiPlacementLoop(char array[ROWS][COLUMNS]) 
{
    srand(time(0));
    aiShipPlacement(5, array);
    aiShipPlacement(4, array);
    aiShipPlacement(3, array);
    aiShipPlacement(3, array);
    aiShipPlacement(2, array);
    print_board(0, 1, array);
    return 0;
}

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
    //printf("\nBoard piece has already been hit\n");
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

//returns 0 if the game should continue, 1 if it shouldn't
int aiLevel1Turn(char userBoard[ROWS][COLUMNS])
{
  int selectedRow;
  int selectedColumn;
  int currentStatus;
  while(1)
  {
    selectedRow= rand()%10;
    selectedColumn= rand()%10;
    currentStatus= fire_and_check(selectedRow, selectedColumn, userBoard);
    if (currentStatus== 0)
    {
      return 0;
    }
    if (currentStatus== 1)
    {
      return 1;
    }
  }
}

/*int aiLevel2Turn(char userBoard[ROWS][COLUMNS], int* searchRow, int* searchColumn, int* currentDirection)
{
  int selectedRow;
  int selectedColumn;
  int currentStatus;
  if(searchRow== -1)
  {
    while(1)
    {
      selectedRow= rand()%10;
      selectedColumn= rand()%10;
      currentStatus= fire_and_check(selectedRow, selectedColumn, userBoard);
      if (currentStatus== 0)
      {
        &searchRow= selectedRow;
        &searchColumn= selectedColumn;
        return 0;
      }
      if (currentStatus== 1)
      {
        return 1;
      }
    }
  }
  else
  {
    if(currentDirection
  }
}*/

int aiLevel3Turn(char userBoard[ROWS][COLUMNS], int* searchRow, int* searchColumn)
{
  int row;
  int col;
  int selectedRow= -1;
  int selectedColumn= -1;
  int currentStatus;
  if(*searchRow != -1)
  {
    printf("Test");
    printf("%d", *searchRow);
    for (row = (*searchRow)-1; (row < (*searchRow)+2 && row < ROWS ); row++)
    {
      printf("%d", row);
      if (userBoard[row][*searchColumn] == 'S')
      {
        selectedRow= row;
        selectedColumn= *searchColumn;
        printf("Test2");
        break;
      }
    }
    if (selectedRow == -1)
    {
      for (col = (*searchColumn)-1; (col < (*searchColumn)+2 && col < COLUMNS); col++)
      {
        if (userBoard[*searchRow][col] == 'S')
        {
          selectedRow= *searchRow;
          selectedColumn= col;
          break;
        }
      }
    }
    if (selectedRow != -1)
    {
      currentStatus= fire_and_check(selectedRow, selectedColumn, userBoard);
      if (currentStatus== 0)
      {
        *searchRow= selectedRow;
        *searchColumn= selectedColumn;
        return 0;
      }
      if (currentStatus== 1)
      {
        return 1;
      }
    }
    *searchRow= -1;
    *searchColumn= -1;
  }

  while(1)
  {
    selectedRow= rand()%10;
    selectedColumn= rand()%10;
    currentStatus= fire_and_check(selectedRow, selectedColumn, userBoard);
    if (currentStatus== 0)
    {
      if(userBoard[selectedRow][selectedColumn] == 'H')
      {
        *searchRow= selectedRow;
        *searchColumn= selectedColumn;
      }
      return 0;
    }
    if (currentStatus== 1)
    {
    return 1;
    }
  }
}

int aiLevel4Turn(char userBoard[ROWS][COLUMNS])
{
  int row;
  int col;
  int selectedRow= -1;
  int selectedColumn= -1;
  int currentStatus;
  for (row = 0; row < ROWS; row++)
  {
    for(col = 0; col < COLUMNS; col++)
    {
      if (userBoard[row][col] == 'S')
      {
        selectedRow= row;
        selectedColumn= col;
        break;
      }
    }
    if (selectedRow != -1)
    {
      break;
    }
  }
  currentStatus= fire_and_check(selectedRow, selectedColumn, userBoard);
  if (currentStatus== 0)
  {
    return 0;
  }
  if (currentStatus== 1)
  {
    printf("Test");
    return 1;
  }
}

int main()
{
    clearScreen();
    int gameEnded= 0;
    int searchRow= -1;
    int searchCol= -1;

    int row;
    int col;
    char matrix[10][10];
    char aiMatrix[10][10];
    for (row=0; row < ROWS; row++)
    {
        for(col=0; col < COLUMNS; col++)
        {
            matrix[row][col] = 'W';
        }
    }
    for (row=0; row < 10; row++)
    {
        for(col=0; col < 10; col++)
        {
            aiMatrix[row][col] = 'W';
        }
    }
    aiPlacementLoop(aiMatrix);
    while(!gameEnded)
    {
      gameEnded= aiLevel3Turn(aiMatrix, &searchRow, &searchCol);
      print_board(0, 1, aiMatrix);
    }
    //fullPlacementLoop(matrix);
    return 0;
}
