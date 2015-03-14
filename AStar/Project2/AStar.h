//
//  AStar.h
//  AStar_PathFinding
//
// Created by Lakshminarayanan Vijayaraghavan and Mrinal Jain on 10/19/14.
//  Copyright (c) 2014 Mrinal Jain. All rights reserved.
//
#include <list>
#include <queue>
#include <set>
#include <string>
#define ORTHO 10
#define DIAG 14
#include "Game.h"

using namespace std;

class AStar
{
public:
    AStar(Game *gameObj);       // Pointer Object to AStar
    bool Search();				// Adding the nodes to the priority queue
    void SetPath(Gridcells<int>* dest);	// sets the path once found
    
private:
    Game *gameObj;				
    set<string> visited;		// Set of visited nodes
    vector<Gridcells<int>*> FindNeighbors(Gridcells<int>* current);			//Find the neighbors and puts it in the vector
};

//The following is used to change the priority queue to ascending mode.
struct MyComparator {	
    bool operator() (Gridcells<int>* arg1, Gridcells<int>* arg2) {
        return *arg2 < *arg1;
    }
};
