//
//  Game.cpp
//  AStar_PathFinding
//
//  Created by Lakshminarayanan Vijayaraghavan and Mrinal Jain on 10/19/14.
//  Copyright (c) 2014 Mrinal Jain. All rights reserved.
//

#include <ctime>
#include <random>
#include <iostream>
#include <math.h>
#include "Game.h"
#include "AStar.h"

Game::Game()
{ 
	
    srand((unsigned int)time(NULL));
    
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------INITIALIZE THE GRID----------------------------------------------------------------------------------------------*/
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            grid[i][j].x = i;
            grid[i][j].y = j;
            grid[i][j].Parent = 0;
            
            // Set Boundary
            if (i == 0 || i==GRID_SIZE-1 || j==0 || j==GRID_SIZE-1)
            {
                grid[i][j].value = getObstacle();
            }
            else
            {
                grid[i][j].value = ' ';
            }
        }
    }
	// Set start point
	do
	{
		cout << "Enter the values between 1 and 18 for Source X :";
		cin >> startX;
	} while (startX<1 || startX > 18);
	do
	{
		cout << "Enter the values between 1 and 18 for Source Y :";
		cin >> startY;
							
	} while (startY < 1 || startY > 18);

	source = &grid[startX][startY];  // Assigning the Source node 
	// set destination point
	do
	{
		cout << "Enter the values between 1 and 18 for Destination X :";
		cin >> endX;
	} while (endX < 1 || endX > 18);
	do
	{
		cout << "Enter the values between 1 and 18 for Destination Y :";
		cin >> endY;

	} while ( endY < 1 || endY > 18);
	dest = &grid[endX][endY];								// Assigning the Destination node 

    // Set Random Obstacles
    for (int i=0; i <NUM_OBSTACLE; i++)
    {
        int x = rand() % (GRID_SIZE - 2) + 1;
        int y = rand() % (GRID_SIZE - 2) + 1;
		if (grid[x][y].value != getObstacle() && !(&grid[x][y] == source) && !(&grid[x][y]==dest))
        {
            grid[x][y].value = getObstacle();
        }
    }
}

char Game::getObstacle() 
{
    return 'x';
}


/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------PRINT THE NODES-------------------------------------------------------------------------------------------------------------*/


void Game::printBoard() 
{
	source->value = 'S';
	dest->value = 'D';
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
			myfile << grid[i][j].value;
			cout << grid[i][j].value;
        }
		myfile << endl;
		cout << endl;
    }
	cout << "Destination Found" << endl;
	myfile << "Destination Found";
}
