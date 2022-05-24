#include <iostream>
#include "Graph.h"
#ifndef UNDIRECTED_H
#define UNDIRECTED_H
using namespace std;

class Undirected : public Graph //Derived class inherits from Graph
{
private:
	Vertex* allVertex;
	Edge* allEdge;
	int capacityVertex, capacityEdge;
	int totVertex, totEdge;
	bool** linked; //1 if linked / 0 if not linked
	string path; //final path string
	vector <string> subpath; //stores all subpaths before choosing what will be stored in the final path
public:
	Undirected();
	Undirected(int capacityVertex);
	virtual ~Undirected();

	virtual Vertex getVertexid(int id);
	virtual Vertex getVertexvalue(string value);
	void createpath(int start, int end, bool include[], int idlist[], int& index);
	virtual Vertex* getAllVertex() const;
	virtual Edge* getAllEdge() const;
	virtual int getTotVertex() const;
	virtual int getTotEdge() const;
	virtual int getCapacityVertex() const;
	virtual int getCapacityEdge() const;

	virtual bool addVertex(Vertex& v);
	bool removeVertex(Vertex& v);
	virtual bool addEdge(Edge& e);
	bool removeEdge(Edge& e);
	virtual bool searchVertex(Vertex& v);
	virtual bool searchEdge(Edge& e);
	virtual string allPaths();
	virtual string vertexPath(Vertex& v);
	virtual bool isPath(Vertex& v1, Vertex& v2);
	virtual bool clean();
};
#endif