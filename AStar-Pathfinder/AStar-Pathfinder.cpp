//Jpaku93 / AStar - Pathfinding - Agorythm 
// Pathfinding Algo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "AStar.h"


using namespace std;
int main()
{
	// make a maze matrix and copy it to maze values
	vector<vector<int>> maze_matrix = {
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 4, 4, 4, 4, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 4, 0, 0, 0, 0, 4 },
		{ 4, 0, 4, 0, 4, 4, 4, 0, 0, 4 },
		{ 4, 0, 4, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 4, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 4, 4, 0, 4, 4, 4, 4, 4 },
		{ 2, 0, 0, 4, 0, 0, 0, 0, 0, 4 },
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 }
	};

	cout << endl;
	// create a new Astar object
	Astar astar(maze_matrix);
	astar.getPath();
	cout << endl;
	cout << "MAZE1" << endl;
	// make a maze matrix and copy it to maze values
	vector<vector<int>> maze_matrix2 = {
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 4, 4, 4, 4, 0, 0, 0, 0, 4 },
		{ 4, 0, 0, 0, 4, 4, 4, 4, 0, 4 },
		{ 4, 0, 4, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 4, 4, 4, 4, 4, 4, 0, 4 },
		{ 4, 0, 4, 0, 0, 0, 0, 0, 0, 4 },
		{ 4, 0, 4, 4, 0, 4, 4, 4, 4, 4 },
		{ 2, 0, 0, 4, 0, 0, 0, 0, 0, 1 },
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 }
	};

	cout << endl;
	// create a new Astar object
	Astar astar2(maze_matrix2);
	astar2.getPath();
	cout << endl;
	cout << "MAZE2" << endl;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

