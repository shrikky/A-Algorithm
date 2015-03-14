//
//  Game.h
//  AStar_PathFinding
//
//  Created by Lakshminarayanan Vijayaraghavan and Mrinal Jain on 10/19/14.
//  Copyright (c) 2014 Mrinal Jain. All rights reserved.
//
#pragma once
#define GRID_SIZE 20
#define NUM_OBSTACLE 40

#include <fstream>
#include "Gridcells.h"


class Game
{
public:
    Game();
	int startX;									// X position of the source
	int startY;									// Y position of the source
	int endX;									// X position of the Endpoint
	int endY;									// Y position of the Endpoint
    Gridcells<int>* source;						// Source Node
    Gridcells<int>* dest;						// Destination node
    Gridcells<int> grid[GRID_SIZE][GRID_SIZE];	// Declaring a Grid of size GRID_SIZE (20)
	ofstream myfile;
	// Return the obstacle "x"
    char getObstacle();
	// Print the values on the screen
    void printBoard();
};


