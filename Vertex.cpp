#include <iostream>
#include "Vertex.h"
using namespace std;

static int order = 1;

Vertex::Vertex() {
	value = "";
	id = 0;
}

Vertex::Vertex(const Vertex& vertex) {
	value = vertex.value;
	id = vertex.id;
}

Vertex::Vertex(string value) {
	this->value = value;
	id = order;
	order++;
}

Vertex::~Vertex() {
	//no dynamic memory to delete
}

void Vertex::setID(int id) {
	this->id = id;
}

int Vertex::getID() {
	return id;
}

void Vertex::setValue(string value) {
	this->value = value;
}

string Vertex::getValue() {
	return value;
}

bool Vertex::operator == (Vertex v) { //compare airport ids
	if (id == v.id)
		return true;
	else
		return false;
}

void Vertex::reset() { //starts ids back from 1
	order = 1;
}