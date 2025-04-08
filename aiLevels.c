#include "aiLevels.h"

/*
	File: aiLevels.c
	Author: Erik Dunlap and Kaeden Daly
	Course: CS125
	Assignement: Final Project
	Date: 04/05/25
	References: N/A
*/

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

int aiLevel2Turn(char userBoard[ROWS][COLUMNS], int* searchRow, int* searchColumn, int* directionSearch)
{
  int row;
  int col;
  int selectedRow= -1;
  int selectedColumn= -1;
  int currentStatus;
  int directionChoice;
  if(*searchRow != -1)
  {
    if(*directionSearch== 0) //if no current ship direction found
    {
      for (row = *searchRow - 1; (row < *searchRow + 2 && row < ROWS); row++)
      {
        if (userBoard[row][*searchColumn] == 'W')
        {
          selectedRow= row;
          selectedColumn= *searchColumn;
          directionChoice= 1;
          break;
        }
        if (userBoard[row][*searchColumn] == 'S')
        {
          selectedRow= row;
          selectedColumn= *searchColumn;
          directionChoice= 1;
          break;
        }
      }
      if (selectedRow == -1)
      {
        for (col = *searchColumn - 1; (col < *searchColumn + 2 && col < COLUMNS); col++)
        {
          if (userBoard[*searchRow][col] == 'W')
          {
            selectedRow= *searchRow;
            selectedColumn= col;
            directionChoice= 2;
            break;
          }
          if (userBoard[*searchRow][col] == 'S')
          {
            selectedRow= *searchRow;
            selectedColumn= col;
            directionChoice= 2;
            break;
          }
        }
      }
      if (selectedRow != -1)
      {
        currentStatus= fire_and_check(selectedRow, selectedColumn, userBoard);
        if (currentStatus== 0)
        {
          if (userBoard[selectedRow][selectedColumn]== 'H')
          {
            *directionSearch= directionChoice;
          }
          return 0;
        }
        if (currentStatus== 1)
        {
          return 1;
        }
      }
    }
    if(*directionSearch== 1)
    {
      for (row = *searchRow; (row < ROWS); row++)
      {
        if (userBoard[row][*searchColumn] == 'M')
        {
          break;
        }
        if (userBoard[row][*searchColumn] == 'W')
        {
          selectedRow= row;
          selectedColumn= *searchColumn;
          break;
        }
        if (userBoard[row][*searchColumn] == 'S')
        {
          selectedRow= row;
          selectedColumn= *searchColumn;
          break;
        }
      }
      if (selectedRow == -1)
      {
        for (row = *searchRow; row > -1; row--)
        {
          if (userBoard[row][*searchColumn] == 'M')
          {
            break;
          }
          if (userBoard[row][*searchColumn] == 'W')
          {
            selectedRow= row;
            selectedColumn= *searchColumn;
            break;
          }
          if (userBoard[row][*searchColumn] == 'S')
          {
            selectedRow= row;
            selectedColumn= *searchColumn;
            break;
          }
        }
      }
      if (selectedRow != -1)
      {
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
      *searchRow= -1;
      *searchColumn= -1;
      *directionSearch= 0;
    }
    if(*directionSearch== 2)
    {
      for (col = *searchColumn; (col < COLUMNS); col++)
      {
        if (userBoard[*searchRow][col] == 'M')
        {
          break;
        }
        if (userBoard[*searchRow][col] == 'W')
        {
          selectedRow= *searchRow;
          selectedColumn= col;
          break;
        }
        if (userBoard[*searchRow][col] == 'S')
        {
          selectedRow= *searchRow;
          selectedColumn= col;
          break;
        }
      }
      if (selectedRow == -1)
      {
        for (col = *searchColumn; col > -1; col--)
        {
          if (userBoard[*searchRow][col] == 'M')
          {
            break;
          }
          if (userBoard[*searchRow][col] == 'W')
          {
            selectedRow= *searchRow;
            selectedColumn= col;
            break;
          }
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
          return 0;
        }
        if (currentStatus== 1)
        {
          return 1;
        }
      }
      *searchRow= -1;
      *searchColumn= -1;
      *directionSearch= 0;
    }
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

int aiLevel3Turn(char userBoard[ROWS][COLUMNS], int* searchRow, int* searchColumn)
{
  int row;
  int col;
  int selectedRow= -1;
  int selectedColumn= -1;
  int currentStatus;
  if(*searchRow != -1)
  {
    for (row = *searchRow; (row < ROWS); row++)
    {
      if (userBoard[row][*searchColumn] == 'S')
      {
        selectedRow= row;
        selectedColumn= *searchColumn;
        break;
      }
      if (userBoard[row][*searchColumn] != 'H')
      {
        break;
      }
    }
    if (selectedRow == -1)
    {
      for (col = *searchColumn; col < COLUMNS; col++)
      {
        if (userBoard[*searchRow][col] == 'S')
        {
          selectedRow= *searchRow;
          selectedColumn= col;
          break;
        }
        if (userBoard[*searchRow][col] != 'H')
        {
          break;
        }
      }
    }
    if (selectedRow == -1)
    {
      for (row = *searchRow; row > -1; row--)
      {
        if (userBoard[row][*searchColumn] == 'S')
        {
          selectedRow= row;
          selectedColumn= *searchColumn;
          break;
        }
        if (userBoard[row][*searchColumn] != 'H')
        {
          break;
        }
      }
    }
    if (selectedRow == -1)
    {
      for (col = (*searchColumn); col > -1; col--)
      {
        if (userBoard[*searchRow][col] == 'S')
        {
          selectedRow= *searchRow;
          selectedColumn= col;
          break;
        }
        if (userBoard[*searchRow][col] != 'H')
        {
          break;
        }
      }
    }
    if (selectedRow != -1)
    {
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
    return 1;
  }
}

void aiGame(char playerBoard[ROWS][COLUMNS], char aiBoard[ROWS][COLUMNS], int aiLevel)
{
  printf("Test");
  int turns = 0;
  int output = 0;
  int aiRow = -1;
  int aiColumn = -1;
  int directionSearch = -1;
  while(output == 0)
  {
    turns += 1;
    if(turns % 2 == 1)
    {
      output = ask_fire(aiBoard);
    }
    else
    {
      switch(aiLevel)
      {
      case 2:
        output = aiLevel1Turn(playerBoard);
        break;
      case 3:
        output = aiLevel2Turn(playerBoard, &aiRow, &aiColumn, &directionSearch);
        break;
      case 4:
        output = aiLevel3Turn(playerBoard, &aiRow, &aiColumn);
        break;
      case 5:
        output = aiLevel4Turn(playerBoard);
        break;
      case 6:
        output = aiLevel4Turn(playerBoard);
        break;
      }
      print_board(1, 0, playerBoard);
    }
  }
  if(output == 1)
  {
    switch(turns % 2)
    {
    case 0:
      printf("AI Wins\n");
      break;
    case 1:
      printf("Player 1 Wins\n");
      break;
    }
  }
  else
  {
    printf("Error: Invalid Outcome");
  }

}
