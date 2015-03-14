//
//  Gridcells.h
//  AStar_PathFinding
//
//  Created by Lakshminarayanan Vijayaraghavan and Mrinal Jain on 10/19/14.
//  Copyright (c) 2014 Mrinal Jain. All rights reserved.
//
//
//  Gridcells.h
//  AStar
//
#include <string>

using namespace std;

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------CREATE A TEMPLATE STRUCT----------------------------------------------------------------------------------------------
												http://www.codeproject.com/Articles/257589/An-Idiots-Guide-to-Cplusplus-Templates-Part#ClassTempl
*/
template <typename T>
struct Gridcells
{
    T x;
    T y;
	T f;	// F value of the node which is G+H
	T g;	// Movement Cost of the node
	T h;	// Heuristic value of the node


    char value;
    
    Gridcells* Parent;
    
    bool operator==(const Gridcells &cell) const
    {
        return this->x == cell.x && this->y == cell.y;
    }
    
    bool operator<(const Gridcells &cell) const
    {
        return this->f < cell.f;
    }

    string toString() {
        return to_string(this->x) + "," + to_string(this->y);
    }
};


/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------CREATE A SPECIALIZED TEMPLATE STRUCT----------------------------------------------------------------------------------------------
															http://www.cprogramming.com/tutorial/template_specialization.html
*/


template <>
struct Gridcells <int>
{
	int x;
	int y;
	int f;		// F value of the node which is G+H
	int g;		// Movement Cost of the node
	int h;		// Heuristic value of the node

	char value;

	Gridcells* Parent;

	bool operator==(const Gridcells &cell) const
	{
		return this->x == cell.x && this->y == cell.y;
	}

	bool operator<(const Gridcells &cell) const
	{
		return this->f < cell.f;
	}

	string toString() {
		return to_string(this->x) + "," + to_string(this->y);
	}
};