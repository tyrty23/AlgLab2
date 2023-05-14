#pragma once
#include <iostream>

using namespace std;

class Edge
{
public:
	int weight;
	int V1;
	int V2;
	Edge(int, int, float);
	Edge();
};

