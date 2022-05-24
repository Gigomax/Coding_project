#include <iostream>
#include <string>
#include "Directed.h"
using namespace std;

Directed::Directed() {
	allVertex = nullptr;
	allEdge = nullptr;
	linked = nullptr;
	capacityVertex = 0;
	capacityEdge = 0;
	totVertex = 0;
	totEdge = 0;
	path = "";
}

Directed::Directed(int capacityVertex) {
	this->capacityVertex = capacityVertex;
	capacityEdge = 0;
	totVertex = 0;
	totEdge = 0;
	path = "";

	linked = new bool*[capacityVertex]; //array of linked airports
	for (int i = 0; i < capacityVertex; i++)
		linked[i] = new bool[capacityVertex];

	for (int i = 0; i < capacityVertex; i++)
		for (int j = 0; j < capacityVertex; j++)
			linked[i][j] = 0;

	for (int i = capacityVertex - 1; i > 0; i--)
		capacityEdge += i; //number of possible flights

	Vertex vd;
	allVertex = new Vertex[capacityVertex]; //airport array
	for (int i = 0; i < capacityVertex; i++) {
		allVertex[i] = vd;
	}

	Edge ed;
	allEdge = new Edge[capacityEdge]; //flight array
	for (int i = 0; i < capacityEdge; i++) {
		allEdge[i] = ed;
	}
}


Directed::~Directed() { //deleting dynamic memory
	delete[] allVertex;
	delete[] allEdge;

	for (int i = 0; i < capacityVertex; i++)
		delete[] linked[i];
	delete[] linked;
}

Vertex Directed::getVertexid(int id) { //seach airports by id
	bool found = false;
	Vertex def;
	int i = 0;
	for (; i < totVertex; i++) {
		if (allVertex[i].getID() == id) {
			found = true;
			break;
		}
	}
	if (found == true)
		return allVertex[i]; //return airport if found
	else
		return def; //else not found return empty airport
}

Vertex Directed::getVertexvalue(string value) { //seach airports by code
	bool found = false;
	Vertex def;
	int i = 0;
	for (; i < totVertex; i++) {
		if (allVertex[i].getValue() == value) {
			found = true;
			break;
		}
	}
	if (found == true)
		return allVertex[i]; //return airport if found
	else
		return def; //else not found return empty airport
}

bool Directed::addVertex(Vertex& v) {
	if (totVertex < capacityVertex) { //check for available space
		allVertex[totVertex] = v;
		totVertex++;
		cout << "Airport added successfully!" << endl;
		return true;
	}
	else {
		cout << "No space to add an airport!" << endl;
		return false;
	}
}

bool Directed::removeVertex(Vertex& v) {
	bool valid = false;
	Vertex* def = new Vertex;

	for (int i = 0; i < totVertex; i++) {
		if (allVertex[i] == v) { //check if airport exists
			for (int j = i; j < totVertex - 1; j++)
				allVertex[j] = allVertex[j + 1];
			allVertex[totVertex - 1] = *def; //shift down airports and remove last
			delete def;
			totVertex--; //decrement airport count

			//remove linked flights
			int k = 0;
			while (k < totEdge) {
				if (allEdge[k].getStartVertex() == v || allEdge[k].getEndVertex() == v) {
					cout << "Linked ";
					removeEdge(allEdge[k]);
					continue;
				}
				k++;
			}

			cout << "Airport successfully removed!" << endl;
			valid = true;
			break;
		}
	}
	if (valid == false) {
		cout << "Airport does not exist!" << endl;
	}
	return valid;
}

bool Directed::addEdge(Edge& e) {
	int startid, endid;
	startid = (e.getStartVertex()).getID();
	endid = (e.getEndVertex()).getID();

	if (totEdge < capacityEdge) { //check for available space
		allEdge[totEdge] = e;
		totEdge++; //increment flight count
		linked[startid-1][endid-1] = 1; //link airports

		cout << "Flight added successfully!" << endl;
		return true;
	}
	else {
		cout << "Cannot add flight!" << endl;
		return false;
	}
}

bool Directed::removeEdge(Edge& e) {
	bool valid = false;
	Edge* def = new Edge;

	int startid, endid;
	startid = (e.getStartVertex()).getID();
	endid = (e.getEndVertex()).getID();

	for (int i = 0; i < totEdge; i++) {
		if (allEdge[i] == e) { //check if flight exists
			linked[startid-1][endid-1] = 0; //remove link between airports

			for (int j = i; j < totEdge - 1; j++)
				allEdge[j] = allEdge[j + 1];
			allEdge[totEdge - 1] = *def;
			delete def;
			totEdge--; //decrement flight count
			cout << "Flight successfully removed!" << endl;
			valid = true;
			break;
		}
	}
	if (valid == false) {
		cout << "Flight does not exist!" << endl;
	}
	return valid;
}

bool Directed::searchVertex(Vertex& v) {
	bool found = false;
	int id;
	string value;
	for (int i = 0; i < totVertex; i++)
		if (allVertex[i] == v) { //check if airport exists
			id = (allVertex[i]).getID();
			value = (allVertex[i]).getValue();
			cout << "ID " << id << " corresponds to " << value << " airport" << endl;
			found = true;
			break;
		}
	if (found == false) {
		cout << "Airport was not found!" << endl;
	}
	return found;
}

bool Directed::searchEdge(Edge& e) {
	bool found = false;
	int startid, endid, weight;
	for (int i = 0; i < totEdge; i++)
		if (allEdge[i] == e) { //check if flight exists
			startid = ((allEdge[i]).getStartVertex()).getID();
			endid = ((allEdge[i]).getEndVertex()).getID();
			weight = (allEdge[i]).getWeight();
			cout << "Flight between airports " << startid << " & " << endid <<
				" lasts " << weight << " hours" << endl;
			found = true;
			break;
		}
	if (found == false) {
		cout << "Flight was not found!" << endl;
	}
	return found;
}

string Directed::allPaths() {
	path = "";
	subpath.clear();
	bool* include = new bool[capacityVertex]; //dynamic array to check if airports are in subpath
	int* idlist = new int[capacityVertex]; //stores all the ids that form the subpath
	int index = 0;

	for (int i = 0; i < capacityVertex; i++)
		include[i] = false; //initialize with no airports in subpath

	for (int i = 0; i < totVertex; i++)
		for (int j = 0; j < totVertex; j++)
			createpath(i, j, include, idlist, index); //check for subpaths between each pair of airports

	for (size_t i = 0; i < subpath.size(); i++) { //add all subpaths to the final path
		if (i == 0) {
			path.append("Paths from ");
			string start = "";
			start += subpath[i][0];
			path.append(start);
			path.append(": ");
		}
		else {
			char current = subpath[i][0];
			char last = subpath[i - 1][0];
			if (current != last) {
				path.append("\n");
				path.append("Paths from ");
				string start = "";
				start += subpath[i][0];
				path.append(start);
				path.append(": ");
			}
			else
				path.append(" / ");
		}
		path.append(subpath[i]);
	}

	delete[] include;
	delete[] idlist;
	
	return path;
}

string Directed::vertexPath(Vertex& v) {
	path = "";
	subpath.clear();
	bool* include = new bool[capacityVertex]; //dynamic array to check if vertices are in subpath
	int* idlist = new int[capacityVertex]; //stores the list of id that form a subpath
	int index = 0;

	for (int i = 0; i < capacityVertex; i++)
		include[i] = false; //initialize with no airports in subpath

	int start = v.getID() - 1;

	for (int i = 0; i < totVertex; i++)
		createpath(start, i, include, idlist, index); //check for all subpaths starting from given airport

	//erase repeated subpaths in bigger paths
	for (size_t i = 0; i < subpath.size(); i++) {
		string compare = subpath[i];
		for (size_t j = 0; j < subpath.size(); j++)
			if (compare.find(subpath[j]) != string::npos && compare != subpath[j]) {
				subpath.erase(subpath.begin() + j);
				j--;
			}
	}

	for (size_t i = 0; i < subpath.size(); i++) { //add all remaining subpaths to final path
		path.append(subpath[i]);
		if (i < subpath.size() - 1)
			path.append(" / ");
	}

	delete[] include;
	delete[] idlist;

	return path;
}

bool Directed::isPath(Vertex& v1, Vertex& v2) {
	path = "";
	subpath.clear();
	bool* include = new bool[capacityVertex]; //dynamic array to check if vertices are in subpath
	int* idlist = new int[capacityVertex]; //stores the list of id that form a subpath
	int index = 0;

	for (int i = 0; i < capacityVertex; i++)
		include[i] = false; //initialize with no airports in subpath

	for (int i = 0; i < totVertex; i++)
		for (int j = 0; j < totVertex; j++)
			createpath(i, j, include, idlist, index); //check for subpaths between each pair of airports

	string temp = to_string(v1.getID());
	char id1 = temp[0];
	temp = to_string(v2.getID());
	char id2 = temp[0];

	//checking if connection between airports exists
	bool linked = false;
	for (size_t i = 0; i < subpath.size(); i++) {
		if (subpath[i][0] == id1) {
			for (size_t j = 0; j < subpath[i].size(); j++) {
				if (subpath[i][j] == id2) {
					cout << subpath[i][j] << endl;
					linked = true;
					break;
				}
			}
		}
		if (linked == true)
			break;
	}

	delete[] include;
	delete[] idlist;

	return linked;
}

void Directed::createpath(int start, int end, bool include[], int idlist[], int& index) { //called recursively to build paths
	string add = "";
	include[start] = true;
	idlist[index] = start + 1;
	index++;
	vector <int> weight;
	int total = 0;
	
	if (start == end) { //reach end of a subpath store string in subpath vector
		if (index > 1) {
			for (int i = 0; i < index; i++) {
				add.append(to_string(idlist[i]));
				if (i < index - 1) { //print flight arrow if not last airport of subpath
					Vertex* v1 = new Vertex;
					Vertex* v2 = new Vertex;
					v1->setID(idlist[i]);
					v2->setID(idlist[i + 1]);
					Edge* e = new Edge(*v1, *v2, 0);

					for (int i = 0; i < totEdge; i++)
						if (allEdge[i] == *e) {
							total += allEdge[i].getWeight();
							weight.push_back(allEdge[i].getWeight());
							break;
						}

					add.append("-->");

					delete v1, v2, e;
				}
			}

			//adding duration of flights
			add.append(" : ");
			if (weight.size() > 1) {
				for (size_t i = 0; i < weight.size(); i++) {
					add.append(to_string(weight[i]));
					if (i < weight.size() - 1)
						add.append(" + ");
					else
						add.append(" = ");
				}
			}
			add.append(to_string(total));
			add.append(" hours");
			subpath.push_back(add);
		}
	}
	else { //keep moving forward in the subpath
		for (int i = 0; i < capacityVertex; i++) {
			if (linked[start][i])
				if (!include[i])
					createpath(i, end, include, idlist, index); //call method recursively
		}
	}

	index--;
	include[start] = false;
}

Vertex* Directed::getAllVertex() const {
	return allVertex;
}

Edge* Directed::getAllEdge() const {
	return allEdge;
}

int Directed::getTotVertex() const {
	return totVertex;
}

int Directed::getTotEdge() const {
	return totEdge;
}

int Directed::getCapacityVertex() const {
	return capacityVertex;
}

int Directed::getCapacityEdge() const {
	return capacityEdge;
}

bool Directed::clean() { //empty all airports and flights
	allVertex[0].reset(); //call reset from any airport
	while (totVertex > 0)
		removeVertex(allVertex[0]);

	cout << "All airports and flights cleared!" << endl;
	return true;
}