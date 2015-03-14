//
//  AStar.cpp
//  AStar_PathFinding
//
//  Created by Lakshminarayanan Vijayaraghavan and Mrinal Jain on 10/19/14.
//  Copyright (c) 2014 Mrinal Jain. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <queue>
#include "AStar.h"
#include "Game.h"

using namespace std;

AStar::AStar(Game *gameObj) {
    this->gameObj = gameObj;
}


/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------CHECKING THE NEIGHBORING NODES----------------------------------------------------------------------------------------------
																		http://www.cplusplus.com/reference/vector/
*/



vector<Gridcells<int>*> AStar::FindNeighbors(Gridcells<int>* current)
{
    vector<Gridcells<int>*> output;
    
	// Checks all the neighboring 8 nodes and itself
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)   //if it is the current node then skip it
            {
                continue;
            }
            else
            {
				// Skipping visited nodes
                if(current->Parent!=0 && current->Parent->x == current->x+i && current->Parent->y == current->y+j)   
                {
                    continue;
                }
                //Skipping boundaries and obstacles
                if (gameObj->grid[current->x + i][current->y + j].value != gameObj->getObstacle())	
                {
                    Gridcells<int>* cell = &gameObj->grid[current->x + i][current->y + j];
                    if (cell->Parent != 0)
                    {
                        continue;
                    }
                    
                    float h = abs(gameObj->dest->x - cell->x) + abs(gameObj->dest->y - cell->y);			// Calculating the H value
                    
                    float g = abs(i) + abs(j) == 2 ? current->g + DIAG : current->g + ORTHO;				// Calculating the G value
                    
                    //Assigning f, g, h values and parents to each eligible neighbour 
                    
                    cell->g = g;
                    cell->h = h;
                    cell->f = g + h;
                    cell->Parent = &gameObj->grid[current->x][current->y];

					//Adding an eligible neighbour to the vector
                    output.push_back(cell);
                }
            }
        }
    }
    //Returning vector with all eligible neigbhbours of current node
    return output;
}



/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------ADDING THE NODES TO THE PRIORITY QUEUE---------------------------------------------------------------------------------------------*/



bool AStar::Search()
{



    priority_queue<Gridcells<int>*, vector<Gridcells<int>*>, MyComparator> pq;			// Creating the priority queue with node having lowest f value on the top
    gameObj->source->Parent = 0;
    pq.push(gameObj->source);
    while (!pq.empty())
    {
        Gridcells<int>* current = pq.top();												// Current node is the lowest F value node.
        pq.pop();
      
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
																		http://www.cplusplus.com/reference/set/set/
																		http://www.cplusplus.com/reference/queue/priority_queue/
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
        pair<set<string>::iterator, bool> ret = visited.insert(current->toString()); //Create a set to store indices of visited nodes.

        // Skipping visited nodes i.e. not adding them to the visited nodes set

        if (ret.second == false)
        {
            continue;
        }
        
        if (current == gameObj->dest)
        {
            // Target Reached
            SetPath(current);
            return true;
        }
        else
        {
			// If not reached then find neighbours of current node and push them to priority queue
            vector<Gridcells<int>*> nextMoves = FindNeighbors(current);
            for (vector<Gridcells<int>*>::iterator it = nextMoves.begin(); it != nextMoves.end(); it++)
            {
                pq.push(*it);
            }
        }
    }
    return false;
}


/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------SETS THE FINAL PATH--------------------------------------------------------------------------------------------------------*/


void AStar::SetPath(Gridcells<int> *dest)
{
    Gridcells<int>* parent = dest->Parent;
    
	if (parent!=0)     // Print the stars as far the cell's parent is not 0
    {
        SetPath(parent);
        gameObj->grid[dest->x][dest->y].value='*';
    }
}
