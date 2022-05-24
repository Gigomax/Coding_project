#include <iostream>
#include <string>
#include "Vertex.h"
#include "Edge.h"
#include "Directed.h"
#include "Undirected.h"
using namespace std;

//prototypes
void addVertex(Graph& g);
void addEdge(Graph& g);
void searchVertex(Graph& g);
void searchEdge(Graph& g);
void vertexPath(Graph& g);

int main()
{
    //array capacity is 100 to have sufficient space
    Directed* d = new Directed(100);
    Undirected* u = new Undirected(100);
    Graph* g = 0;

    int flight;
    string test;
    bool valid = false;
    do {
        do {
            valid = true;
            cout << endl << "Choose the type of flights you want in your map" << endl;
            cout << "Enter [1] for one way flights" << endl;
            cout << "Enter [2] for round trip flights" << endl << "Input: ";
            cin >> test; //take string to avoid program crash when user does not enter number

            for (int i = 0; i < test.size(); i++)
                if (test[i] < '0' || test[i] > '9') //char not a number is not valid
                    valid = false;
        } while (valid == false);

        flight = stoi(test);
    
    } while (flight != 1 && flight != 2); //ensure input is valid

    if (flight == 1) //one-way flights = directed
        g = d;
    else if (flight == 2) //round trip flights = undirected
        g = u;

    //Building default map with 5 airports and 4 flights
    
    //default airports
    string a = "YUL"; //Montreal
    Vertex* v1 = new Vertex(a);
    cout << endl << "Adding airport: " << v1->getValue() << endl;
    g->addVertex(*v1);
    a = "YYZ"; //Toronto
    Vertex* v2 = new Vertex(a);
    cout << endl << "Adding airport: " << v2->getValue() << endl;
    g->addVertex(*v2);
    a = "CDG"; //Paris
    Vertex* v3 = new Vertex(a);
    cout << endl << "Adding airport: " << v3->getValue() << endl;
    g->addVertex(*v3);
    a = "CAI"; //Cairo
    Vertex* v4 = new Vertex(a);
    cout << endl << "Adding airport: " << v4->getValue() << endl;
    g->addVertex(*v4);
    a = "HND"; //Tokyo
    Vertex* v5 = new Vertex(a);
    cout << endl << "Adding airport: " << v5->getValue() << endl;
    g->addVertex(*v5);
    
    //default flights
    Edge* e1 = new Edge(*v1, *v2, 1);
    cout << endl << "Adding flight: " << (e1->getStartVertex()).getValue() << " to " << (e1->getEndVertex()).getValue() << endl;
    g->addEdge(*e1);
    Edge* e2 = new Edge(*v2, *v3, 7);
    cout << endl << "Adding flight: " << (e2->getStartVertex()).getValue() << " to " << (e2->getEndVertex()).getValue() << endl;
    g->addEdge(*e2);
    Edge* e3 = new Edge(*v2, *v4, 10);
    cout << endl << "Adding flight: " << (e3->getStartVertex()).getValue() << " to " << (e3->getEndVertex()).getValue() << endl;
    g->addEdge(*e3);
    Edge* e4 = new Edge(*v3, *v5, 13);
    cout << endl << "Adding flight: " << (e4->getStartVertex()).getValue() << " to " << (e4->getEndVertex()).getValue() << endl;
    g->addEdge(*e4);

    //print default map
    cout << endl << "Here is your starting flight map:" << endl << g << endl;

    cout << endl << "Possible flights are: " << endl << g->allPaths() << endl;

    cout << endl << "Paths from airport " << v2->getID() << " (" << v2->getValue() << ") are:" << endl << g->vertexPath(*v2) << endl;

    cout << endl << "Searching for flight from airport " << (e4->getStartVertex()).getID() << " to " << (e4->getEndVertex()).getID() << endl;
    g->searchEdge(*e4);

    cout << endl << "Searching for airport " << v4->getValue() << endl;
    g->searchVertex(*v4);

    delete v1, v2, v3, v4, v5, e1, e2, e3, e4;

    int choice;
    //flight map menu
    do {
        valid = true;
        cout << endl << "-------------------------------------------" << endl;
        cout << "                 MAIN MENU" << endl;
        cout << "Enter [1] to remove all flights and airports" << endl;
        cout << "Enter [2] to add an aiport" << endl;
        cout << "Enter [3] to add a flight" << endl;
        cout << "Enter [4] to display all airports and flights" << endl;
        cout << "Enter [5] to display all possible flight paths" << endl;
        cout << "Enter [6] to list all flight paths from an airport" << endl;
        cout << "Enter [7] to search for a flight" << endl;
        cout << "Enter [8] to search for an aiport by its code" << endl;
        cout << "Enter [9] to exit" << endl << "Input: ";
        cin >> test; //take string to avoid program crash when user does not enter number
        cout << endl;

        for (int i = 0; i < test.size(); i++)
            if (test[i] < '0' || test[i] > '9') //char not a number is not valid
                valid = false;
    } while (valid == false);

    choice = stoi(test);

    while (choice != 9) {
        switch (choice)
        {
        case 1:
            g->clean();
            break;
        case 2:
            addVertex(*g);
            break;
        case 3:
            addEdge(*g);
            break;
        case 4:
            cout << g << endl; //overloaded cout
            break;
        case 5:
            if (g->allPaths() == "") //check if there are paths
                cout << "There are currently no flights" << endl;
            else
                cout << "Possible flights are: " << endl << g->allPaths() << endl;
            break;
        case 6:
            vertexPath(*g);
            break;
        case 7:
            searchEdge(*g);
            break;
        case 8:
            searchVertex(*g);
        }

        //flight map menu
        do {
            valid = true;
            cout << endl << "-------------------------------------------" << endl;
            cout << "                 MAIN MENU" << endl;
            cout << "Enter [1] to remove all flights and airports" << endl;
            cout << "Enter [2] to add an aiport" << endl;
            cout << "Enter [3] to add a flight" << endl;
            cout << "Enter [4] to display all airports and flights" << endl;
            cout << "Enter [5] to display all possible flight paths" << endl;
            cout << "Enter [6] to list all flight paths from an airport" << endl;
            cout << "Enter [7] to search for a flight" << endl;
            cout << "Enter [8] to search for an aiport by its code" << endl;
            cout << "Enter [9] to exit" << endl << "Input: ";
            cin >> test; //take string to avoid program crash when user does not enter number
            cout << endl;

            for (int i = 0; i < test.size(); i++)
                if (test[i] < '0' || test[i] > '9') //char not a number is not valid
                    valid = false;
        } while (valid == false);

        choice = stoi(test);
    }

    delete g, d, u;

    cout << "THANK YOU! HAVE A NICE DAY :)" << endl; //Final message before exit

    return 0;
}


//Method definitions

void addVertex(Graph& g) {
    string c;
    bool valid = false;
    do {
        valid = true;
        cout << "Enter airport code of airport to add: ";
        cin >> c;
        if (c.size() == 3) { //check if airport code is 3 chars
            for (int i = 0; i < 3; i++) //check if airport code is all caps letters
                if (c[i] < 'A' || c[i] > 'Z')
                    valid = false;
        }
        else
            valid = false;

    } while (valid == false);

    Vertex* v = new Vertex(c);
    g.addVertex(*v);

    delete v;
}

void addEdge(Graph& g) {
    int id, weight;
    Vertex* v1 = new Vertex;
    Vertex* v2 = new Vertex;

    string test; //used to verify input
    bool valid = false;
    do {
        valid = true;
        cout << "Enter id of first airport for the flight: ";
        cin >> test; //take string to avoid program crash when user does not enter number

        for (int i = 0; i < test.size(); i++)
            if (test[i] < '0' || test[i] > '9') //char not a number is not valid
                valid = false;
    } while (valid == false);

    id = stoi(test); //assign the verified number to the integer year

    *v1 = g.getVertexid(id);

    if (v1->getID() != 0) { //checking for valid starting airport
        
        do {
            valid = true;
            cout << "Enter id of second airport for the flight: ";
            cin >> test; //take string to avoid program crash when user does not enter number

            for (int i = 0; i < test.size(); i++)
                if (test[i] < '0' || test[i] > '9') //char not a number is not valid
                    valid = false;
        } while (valid == false);

        id = stoi(test); //assign the verified number to the integer year
        
        *v2 = g.getVertexid(id);

        if (v2->getID() != 0) { //checking for valid ending airport
            if (g.isPath(*v2, *v1) || *v1 == *v2) //checking for loops
                cout << "Airports are connected, cannot add flight!" << endl;
            else {
                
                do {
                    valid = true;
                    cout << "Enter duration of of flight (precise to the hour): ";
                    cin >> test; //take string to avoid program crash when user does not enter number

                    for (int i = 0; i < test.size(); i++)
                        if (test[i] < '0' || test[i] > '9') //char not a number is not valid
                            valid = false;
                } while (valid == false);

                weight = stoi(test); //assign the verified number to the integer year

                Edge* e = new Edge(*v1, *v2, weight);
                Edge* All = g.getAllEdge();

                bool exists = false;
                for (int i = 0; i < g.getTotEdge(); i++)
                    if (All[i] == *e) {
                        exists = true;
                        break;
                    }

                if (exists == true)
                    cout << "Flight already exists" << endl;
                else
                    g.addEdge(*e);
                
                delete e;
            }
        }
        else {
            cout << "Invalid airport id!" << endl;
        }
    }
    else {
        cout << "Invalid airport id!" << endl;
    }

    delete v1, v2;
}

void searchEdge(Graph& g) {
    int id;
    Vertex* v1 = new Vertex;
    Vertex* v2 = new Vertex;

    string test; //used to verify input
    bool valid = false;

    do {
        valid = true;
        cout << "Enter id of first airport for the flight: ";
        cin >> test; //take string to avoid program crash when user does not enter number

        for (int i = 0; i < test.size(); i++)
            if (test[i] < '0' || test[i] > '9') //char not a number is not valid
                valid = false;
    } while (valid == false);

    id = stoi(test); //assign the verified number to the integer year

    *v1 = g.getVertexid(id);

    if (v1->getID() != 0) { //check valid start id
        
        do {
            valid = true;
            cout << "Enter id of second airport for the flight: ";
            cin >> test; //take string to avoid program crash when user does not enter number

            for (int i = 0; i < test.size(); i++)
                if (test[i] < '0' || test[i] > '9') //char not a number is not valid
                    valid = false;
        } while (valid == false);
        

        id = stoi(test); //assign the verified number to the integer year

        *v2 = g.getVertexid(id);

        if (v2->getID() != 0) { //check valid end id
            Edge* e = new Edge(*v1, *v2, 0); //duration is arbitrary as it is not verified when comparing flights
            g.searchEdge(*e);
            delete e;
        }
        else {
            cout << "Invalid airport id!" << endl;
        }
    }
    else {
        cout << "Invalid airport id!" << endl;
    }

    delete v1, v2;
}

void searchVertex(Graph& g) {
    string value;
    Vertex* v = new Vertex;

    bool valid = false;
    do {
        valid = true;
        cout << "Enter airport code to search for the airport: ";
        cin >> value;
        if (value.size() == 3) { //check if airport code is 3 chars
            for (int i = 0; i < 3; i++) //check if airport code is all caps letters
                if (value[i] < 'A' || value[i] > 'Z')
                    valid = false;
        }
        else
            valid = false;
    } while (valid == false);

    *v = g.getVertexvalue(value);
    g.searchVertex(*v);

    delete v;
}

void vertexPath(Graph& g){
    int id;
    string path;
    Vertex* v = new Vertex;

    string test; //used to verify input
    bool valid = false;
    do {
        valid = true;
        cout << "Enter id of airport to see connected flights: ";
        cin >> test; //take string to avoid program crash when user does not enter number

        for (int i = 0; i < test.size(); i++)
            if (test[i] < '0' || test[i] > '9') //char not a number is not valid
                valid = false;
    } while (valid == false);

    id = stoi(test); //assign the verified number to the integer year

    *v = g.getVertexid(id);

    if (v->getID() != 0) {
        path = g.vertexPath(*v);

        if (path == "") //check if there are paths from that airport
            cout << "There are currently no flights from airport " << id << endl;
        else
            cout << "Paths from airport " << id << " are: " << path << endl;
    }
    else {
        cout << "Invalid airport id!" << endl;
    }

    delete v;
}