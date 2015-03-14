//
//  main.cpp
//  AStar_PathFinding
//
//  Created by Lakshminarayanan Vijayaraghavan and Mrinal Jain on 10/19/14.
//  Copyright (c) 2014 Mrinal Jain. All rights reserved.
//

/*
Coding References:

http://www.codeproject.com/Articles/257589/An-Idiots-Guide-to-Cplusplus-Templates-Part#ClassTempl
http://www.cprogramming.com/tutorial/template_specialization.html
http://www.cplusplus.com/reference/fstream/fstream/
http://www.cplusplus.com/reference/queue/priority_queue/
http://www.cplusplus.com/reference/vector/
http://www.cplusplus.com/reference/set/set/
http://www.cplusplus.com/doc/tutorial/pointers/
http://c.learncodethehardway.org/book/ex16.html

A-Star Tutorials:
http://www.policyalmanac.org/games/aStarTutorial.htm
http://www.redblobgames.com/pathfinding/a-star/introduction.html



*/

#include <fstream>
#include <iostream>
#include "Game.h"
#include "AStar.h"


using namespace std;

int main()
{
									
	char ans = 'y';
	// Creating a File called out OUTPUT.txt and writing the output to it
	do
	{
		Game gameObj;												// Object to Game Class
		AStar aSObj(&gameObj);										// Object to AStar Class
		gameObj.myfile.open("Output.txt");
		gameObj.myfile << endl;
		gameObj.myfile << endl;
		gameObj.myfile << "Source Value " << gameObj.source->x << "," << gameObj.source->y << endl;
		gameObj.myfile << "Destination Value " << gameObj.dest->x << "," << gameObj.dest->y << endl;
		cout << "Source Value " << gameObj.source->x << "," << gameObj.source->y << endl;
		cout << "Destination Value " << gameObj.dest->x << "," << gameObj.dest->y << endl;


		// Prints the Output
		gameObj.printBoard();

		// Begin A* process
		if (aSObj.Search()) 
		{
			gameObj.myfile << "Path found" << endl;
			cout << "Path found" << endl;
		}
		else 
		{
			gameObj.myfile << "No Path Found!!!" << endl;
			cout << "No Path Found!!!" << endl;
		}

		// Prints the values on the screen
		gameObj.printBoard();
		cout << "File output created" << endl;
	
		cout << "Do you want to play again? Press Y to play again or any other Key to quit.";
		cin >> ans;
	} while (ans == 'y');
    return 0;
}

