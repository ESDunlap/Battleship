#include <stdio.h>
#define COLUMNS 10
#define ROWS 10

int validIntInput()
{
    int userInput;
    while (scanf("%d", &userInput)== 0)
    {
        printf("Invalid Input");
        while (getchar()!= '\n');
    }
    return userInput;
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
            selectedColumn= validIntInput() - 1;
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
            if (selectedColumn + currentShipSize > 9)
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
        }
        case 2:
        {
            if (selectedRow + currentShipSize > 9)
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
        }
        }
    }
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
    return 0;
}

int main()
{
    int row;
    int col;
    char matrix[10][10];
    for (row=0; row < 10; row++)
    {
        for(col=0; col < 10; col++)
        {
            matrix[row][col] = 'W';
        }
    }
    fullPlacementLoop(matrix);
    return 0;
}