#include <iostream>
#include "Edge.h"
using namespace std;

Edge::Edge() {
	startvertex;
	endvertex;
	weight = 0;
}

Edge::Edge(const Edge& edge) {
	startvertex = edge.startvertex;
	endvertex = edge.endvertex;
	weight = edge.weight;
}

Edge::Edge(Vertex startvertex, Vertex endvertex, int weight) {
	this->startvertex = startvertex;
	this->endvertex = endvertex;
	this->weight = weight;
}

Edge::~Edge() {
	//no dynamic memory to delete
}

Vertex Edge::getStartVertex() {
	return startvertex;
}

Vertex Edge::getEndVertex() {
	return endvertex;
}

int Edge::getWeight() {
	return weight;
}

void Edge::incWeight() {
	weight++;
}

bool Edge::operator == (Edge& e) { //compare flights by starting and ending airports
	if (startvertex == e.startvertex)
		if (endvertex == e.endvertex)
			return true;
		else
			return false;
	else
		return false;
}

void Edge::operator != (Edge& e) { //create the inverse of a flight with same duration
	startvertex = e.getEndVertex();
	endvertex = e.getStartVertex();
	weight = e.getWeight();
}