#include <iostream>
#include "Graph.h"
using namespace std;

ostream& operator << (ostream& output, Graph* G) { //global function overloading cout
	int totVertex, totEdge;
	totVertex = G->getTotVertex();
	totEdge = G->getTotEdge();
	Vertex* allVertex;
	Edge* allEdge;
	allVertex = G->getAllVertex();
	allEdge = G->getAllEdge();
	
	if (totVertex < 1) //check if there are airports
		output << "The flight map contains no airports" << endl;
	else {
		output << "Airports (id:code) are: "; //output airports
		for (int i = 0; i < totVertex; i++) {
			output << "(" << allVertex[i].getID();
			output << ":" << allVertex[i].getValue() << ")";
			if (i < totVertex - 1)
				output << " / ";
		}
		if (totEdge < 1) //check if there are flights
			output << endl << "The flight map contains no flights" << endl;
		else {
			output << endl << "Connected airports are: "; //output flights
			for (int i = 0; i < totEdge; i++) {
				output << (allEdge[i].getStartVertex()).getID();
				cout << "-->";
				output << (allEdge[i].getEndVertex()).getID();
				if (i < totEdge - 1)
					output << " / ";
			}
		}

	}

	return output;
}

Graph::Graph() {
	//nothing to initialize
}

Graph::~Graph() {
	//no dynamic memory to delete
}