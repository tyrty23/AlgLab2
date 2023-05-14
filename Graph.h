#pragma once
#include "Edge.h"
#include <vector>
#include <algorithm>
#include <set>
#include <chrono>


const int INF = 1e9;

class Graph
{

public:
	int CountV;
	vector<Edge> Edges;

	//vector<vector<int>> AdjMatrix;

	Graph(vector<Edge>,int);

	vector<Edge> Kraskal();
	
	vector<Edge> Prima();

	Edge MinEdge( set<int>);

};

