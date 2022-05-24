#include <iostream>
#include <list>
#include "Vertex.h"
#include "Edge.h"
#ifndef GRAPH_H
#define GRAPH_H
using namespace std;

class Graph //abstract base class
{
	friend ostream& operator << (ostream& output, Graph* G); //overloading << for cout as a global friend function

public:
	Graph();
	virtual ~Graph();

	//all pure virtual functions implement in derived classes Directed and Undirected
	virtual Vertex getVertexid(int id) = 0;
	virtual Vertex getVertexvalue(string value) = 0;
	virtual Vertex* getAllVertex() const = 0;
	virtual Edge* getAllEdge() const = 0;
	virtual int getTotVertex() const = 0;
	virtual int getTotEdge() const = 0;
	virtual int getCapacityVertex() const = 0;
	virtual int getCapacityEdge() const = 0;

	virtual bool addVertex(Vertex& v) = 0;
	virtual bool addEdge(Edge& e) = 0;
	virtual bool searchVertex(Vertex& v) = 0;
	virtual bool searchEdge(Edge& e) = 0;
	virtual string allPaths() = 0;
	virtual string vertexPath(Vertex& v) = 0;
	virtual bool isPath(Vertex& v1, Vertex& v2) = 0;
	virtual bool clean() = 0;

};
#endif