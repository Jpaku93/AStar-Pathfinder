#include<vector>
#include <iostream>
#include"Node.h"

#pragma once

using namespace std;
class Astar
{
private:
	int start;
	int end;
	vector<Node> map;
	vector<int> visited;
	vector<int> path;
	vector<int> path_x;
public:
	Astar(vector<vector<int>> maze_matrix)
	{


		
		// loop through matrix initializing a node at each position
		for (int i = 0; i < maze_matrix.size(); i++)
		{
			for (int j = 0; j < maze_matrix[i].size(); j++)
			{
				// create a node with the value of the maze cell
				Node node(maze_matrix[i][j], i, j);
				if (maze_matrix[i][j] == 1) {
					node.setValue('S');
					// get the start node int
					start = i * 10 + j;

				}
				else if (maze_matrix[i][j] == 2) {
					node.setValue('E');
					// get the end node int
					end = i * 10 + j;
				}
				else if (maze_matrix[i][j] == 4)
					node.setValue('#');
				else
					node.setValue(' ');
				// add the node to the map
				map.push_back(node);
			}
		}

		if (start == 0) {
			cout << "No start node found" << endl;
			return;
		}
		if (end == 0) {
			cout << "No end node found" << endl;
			return;
		}
		this->map[start].setVisited(true);
		this->map[start].setCost(0);
		this->map[start].setTotal(0);
		this->map[start].setHeuristic(0);
	}

	void SearchNeighbors(int current_node)
	{
		if (map[current_node - 1].getValue() == 'E' || map[current_node + 1].getValue() == 'E' || map[current_node - 10].getValue() == 'E' || map[current_node + 10].getValue() == 'E') {
			map[end].setParent(current_node);
			map[end].setVisited(true);
		}


		if (map[current_node - 1].getValue() != '#' && map[current_node - 1].getVisited() == false) {	// if left is not a wall
			//map[current_node - 1].setValue('*');														// mark the node as visited
			map[current_node - 1].setHeuristic(Distance(current_node - 1, end));						// set the heuristic cost
			map[current_node - 1].setCost(Distance(current_node - 1, start));								// set the cost
			map[current_node - 1].setVisited(true);
			// set parent as current node
			map[current_node - 1].setParent(current_node);												// set the parent

			visited.push_back(current_node - 1);														// add the node to the visited vector
		}
		// if right is not a wall
		if (map[current_node + 1].getValue() != '#' && map[current_node + 1].getVisited() == false) {	// if left is not a wall
			//map[current_node + 1].setValue('*');														// mark the node as visited
			map[current_node + 1].setHeuristic(Distance(current_node + 1, end));						// set the heuristic cost
			map[current_node + 1].setCost(Distance(current_node + 1, start));								// set the cost
			map[current_node + 1].setVisited(true);														// set the visited flag
			// set parent as current node
			map[current_node + 1].setParent(current_node);												// set the parent
			visited.push_back(current_node + 1);														// add the node to the visited vector
		}
		// if up is not a wall
		if (map[current_node - 10].getValue() != '#' && map[current_node - 10].getVisited() == false) {	// if left is not a wall
			//map[current_node - 10].setValue('*');														// mark the node as visited
			map[current_node - 10].setHeuristic(Distance(current_node - 10, end));						// set the heuristic cost
			map[current_node - 10].setCost(Distance(current_node - 10, start));							// set the cost
			map[current_node - 10].setVisited(true);													// set the visited flag
			// set parent as current node
			map[current_node - 10].setParent(current_node);												// set the parent

			visited.push_back(current_node - 10);														// add the node to the visited vector
		}
		// if down is not a wall
		if (map[current_node + 10].getValue() != '#' && map[current_node + 10].getVisited() == false) {	// if left is not a wall
			//map[current_node + 10].setValue('*');														// mark the node as visited
			map[current_node + 10].setHeuristic(Distance(current_node + 10, end));						// set the heuristic cost
			map[current_node + 10].setCost(Distance(current_node + 10, start));							// set the cost
			map[current_node + 10].setVisited(true);													// set the visited flag
			// set parent as current node
			map[current_node + 10].setParent(current_node);												// set the parent
			visited.push_back(current_node + 10);														// add the node to the visited vector
		}

	}

	int Distance(int target, int node) {
		// return the distance from
		return abs(map[node].getX() - map[target].getX()) + abs(map[node].getY() - map[target].getY());
	}
	void getPath() {

		map[start].setCost(0);
		// Search neighbours of start node
		SearchNeighbors(start);

		// while the end node is not visited
		while (map[end].getVisited() == false)
		{
			// find the node with the lowest heuristic
			int lowest_heuristic = INT_MAX;
			int lowest_heuristic_node = 0;
			for (int i = 0; i < visited.size(); i++)
			{
				if (map[visited[i]].getHeuristic() + map[visited[i]].getCost() < lowest_heuristic)
				{
					lowest_heuristic = map[visited[i]].getHeuristic() + map[visited[i]].getCost();
					lowest_heuristic_node = visited[i];

				}
			}
			//map[lowest_heuristic_node].setValue('+');
			//cout << endl << "Lowest Cost: " << Distance(lowest_heuristic, end) << endl;
			//cout << "Heuristic: " << Distance(lowest_heuristic, start) << endl;

			// remove from visited list
			visited.erase(remove(visited.begin(), visited.end(), lowest_heuristic_node), visited.end());
			path.push_back(lowest_heuristic_node);
			// search the neighbours of the lowest heuristic node
			SearchNeighbors(lowest_heuristic_node);


		}
		printMap(map);

		// empty visited
		visited.clear();
		// empty path
		path.clear();
		// set all nodes to unvisited
		for (int i = 0; i < map.size(); i++)
		{
			map[i].setVisited(false);
		}
		// start from end and go back to start
		int current_node = end;
		while (current_node != start)
		{
			// add the node to the path
			path.push_back(current_node);
			// set the current node to the previous node
			current_node = map[current_node].getParent();
			map[current_node].setValue('+');

		}

		printMap(map);

	}
	void printMap(vector<Node> map) {
		// print the map 
		for (int i = 0; i < map.size(); i++)
		{
			// endline condition at the end of each row
			if (i % 10 == 0)
				cout << endl;
			cout << map[i].getValue() << " ";
		}
	}

};