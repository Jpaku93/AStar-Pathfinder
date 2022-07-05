#pragma once

// create the maze cell Node class
class Node
{
	// the node contains the char value of the maze cell
	char value;			// visual aesthetic
	bool visited;		// has the node been visited?
	int x;				// x coordinate
	int y;				// y coordinate
	int heuristic;		// Distance to goal so far
	int cost;			// Distance to goal if we took the alternative route
	int total;
	int parent;


public:
	// constructor
	Node(char value, int x, int y)
	{
		this->value = value;
		this->x = x;
		this->y = y;
		this->visited = false;
		this->heuristic = 0;
		this->cost = 0;
		this->total = 0;
		this->parent = 0;
		//parent
	}

	// get the value of the maze cell
	char getValue()
	{
		return value;
	}
	// get the x coordinate of the maze cell
	int getX()
	{
		return x;
	}
	// get the y coordinate of the maze cell
	int getY()
	{
		return y;
	}
	// set the value of the maze cell
	void setValue(char value)
	{
		this->value = value;
	}
	// set the x coordinate of the maze cell
	void setX(int x)
	{
		this->x = x;
	}
	// set the y coordinate of the maze cell
	void setY(int y)
	{
		this->y = y;
	}
	// set the visited flag of the maze cell
	void setVisited(bool visited)
	{
		this->visited = visited;
	}
	// get the visited flag of the maze cell
	bool getVisited()
	{
		return visited;
	}
	// set the heuristic of the maze cell
	void setHeuristic(int heuristic)
	{
		this->heuristic = heuristic;
	}
	// get the heuristic of the maze cell
	int getHeuristic()
	{
		return heuristic;
	}
	// set the cost of the maze cell
	void setCost(int cost)
	{
		this->cost = cost;
	}
	// get the cost of the maze cell
	int getCost()
	{
		return cost;
	}
	// set the total of the maze cell	
	void setTotal(int total)
	{
		this->total = total;
	}
	// get the total of the maze cell
	int getTotal()
	{
		return heuristic + cost;
	}
	// set the parent of the maze cell
	void setParent(int parent)
	{
		this->parent = parent;
	}
	// get the parent of the maze cell
	int getParent()
	{
		return parent;
	}
};