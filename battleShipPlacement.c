#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#define COLUMNS 10
#define ROWS 10

/*
	File: shipPlacement.c
	Author: Erik Dunlap
	Course: CS125
	Assignement: Final Project
	Date: 03/31/25
	References: N/A
*/

/*void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}*/

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
        selectedRow= rand()%ROWS;
        selectedColumn= rand()%COLUMNS;
        directionVar= rand()%2 + 1;
        switch (directionVar)
        {
        case 1:
        {
            if (selectedColumn + currentShipSize > ROWS-1)
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
            if (selectedRow + currentShipSize > COLUMNS)
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
            if (selectedRow > ROWS-1 || selectedRow < 0)
            {
                printf("Invalid Number\n");
            }
        }
        while (selectedRow > ROWS-1 || selectedRow < 0);
        do
        {
            printf("Which column?\n");
            selectedColumn= validColInput();
            if (selectedColumn > COLUMNS-1 || selectedColumn < 0)
            {
                printf("Invalid Number\n");
            }
        }
        while (selectedColumn > COLUMNS-1 || selectedColumn < 0);
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
            if (selectedColumn + currentShipSize > COLUMNS)
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
            if (selectedRow + currentShipSize > COLUMNS)
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
    //print_board(0, 1, array);
    return 0;
}

int fullPlacementLoop(char array[ROWS][COLUMNS]) 
{
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
    //clearScreen();
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
    return 0;
}

int main()
{
    int row;
    int col;
    char matrix[10][10];
    char aiMatrix[10][10];
    for (row=0; row < 10; row++)
    {
        for(col=0; col < 10; col++)
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
    fullPlacementLoop(matrix);
    return 0;
}
