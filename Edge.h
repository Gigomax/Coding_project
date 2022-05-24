#include <iostream>
#include "Vertex.h"
#ifndef EDGE_H
#define EDGE_H
using namespace std;

class Edge
{
private:
	Vertex startvertex, endvertex;
	int weight;
public:
	Edge();
	Edge(const Edge& edge);
	Edge(Vertex startvertex, Vertex endvertex, int weight);
	~Edge();
	Vertex getStartVertex();
	Vertex getEndVertex();
	int getWeight();
	void incWeight();
	bool operator == (Edge& e);
	void operator != (Edge& e);
};
#endif