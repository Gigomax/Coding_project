#include <iostream>
#include <vector>
#ifndef VERTEX_H
#define VERTEX_H
using namespace std;

class Vertex
{
private:
	string value;
	int id;
public:
	Vertex();
	Vertex(const Vertex& vertex);
	Vertex(string value);
	~Vertex();
	void setID(int id);
	int getID();
	void setValue(string value);
	string getValue();
	bool operator == (Vertex v);
	void reset();
};
#endif