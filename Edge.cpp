#include "Edge.h"

Edge::Edge(int v1, int v2, float w)
{
	this->V1 = v1;
	this->V2 = v2;
	this->weight = w;
}

Edge::Edge()
{
	this->V1 = -1;
	this->V2 = -1;
	this->weight = 1023;
}
