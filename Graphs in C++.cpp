/* Graph representation, using edge list, where list is replaced by vector

A vector template is a data structure representing a dynamic array (allowing its size to be modified).
The data is always stored in memory continuously, so copying data to and from the container is always safe.
This container should be used whenever the priority is to have fast access to any element of the container.
The vector template allows adding and removing elements to the end of an array in constant time - O(1).
Adding and removing elements from the beginning or the middle of the container can be done in linear time - O(n),
where n is the number of elements in the container. The vector container reallocates memory when any method of the template 
needs to increase the size of the container array and at the same time there is no free memory space in the container for newly added elements.
*/

#include <iostream>
#include <vector>
using namespace std;

void Edges_directed(int a,vector<int> *b)
{
	cout<<"\n\n The directed edges of a given graph are: \n";
	for(int i=1; i<=a; i++)     // List the edges of the directed graph one by one using pointers
	{
		for(vector<int>::iterator j = b[i].begin(); j != b[i].end(); ++j)
		{
			cout <<endl<<i<<" --> ";
			cout << *j << ", ";}
		}
	/* 
	In the loop we successively: assign to iterator j the beginning of the created edge, 
	then we check if the end of the edge belongs to this edge (to this iterator), and increment iterator j by 1. 
	If the end of the edge belongs to this edge, we print the edges found for vertex no.: i, at the end we increase the iterator by 1. 
	*/
}

void Neighbours(int a,vector<int> *b)
{
	for(int i=1; i<=a; i++)     // Wypisujemy po kolei sasiadow wszystkich wierzcholkow graf za pomoca wskaznikow w petli, gdzie "i" oznacza nr krawedzi grafu.
	{
		cout << endl << "For vertex No." << i << " neighbours are: ";
		for(vector<int>::iterator j = b[i].begin(); j != b[i].end(); ++j)
			{
				cout << *j << ", ";

			}
		/* 
		In the loop we successively: assign to iterator j the beginning of the created edge, 
		then we check if the end of the edge belongs to this edge (to this iterator), and increment iterator j by 1.
		If the end of the edge belongs to this edge, we print the found neighbour of vertex i, and at the end we increment the iterator by 1.
		*/
		}
 }

void Indegree(int a,vector<int> *b)
{
	for(int w=1; w<=a; w++)
		// In a loop for each vertex, we save it and then check its neighbors .
	{
		int In =0;
		for(int i=1; i<=a; i++)
			{
				for(vector<int>::iterator j = b[i].begin(); j != b[i].end(); ++j)
					{
						if(w==*j)
						{
							In++; // If the given vertex is someone else's neighbour, 
								// it has an incoming edge from him, so we add 1 to the "In" value.
						}
					}
			}
		cout << endl << "For vertex No." << w << " indegree is: "<< In;
	}
}

void Outdegree(int a,vector<int> *b)
{
	int x;
	for(int i=1; i<=a; i++)     // We list the neighbours of all vertices of the graph one by one using the pointers in the loop, 
								// where "i" is the edge number of the graph.
	{
		x=0;
		for(vector<int>::iterator j = b[i].end(); j != b[i].begin(); --j)
			{
				x++;
			}
		cout << endl << "For vertex No." << i << " outdegree is: "<<x;
	}
}

void Loops(int a,vector<int> *b)
{
	cout << endl<< endl << "Loops exist in vertices: ";
	for(int i=1; i<=a; i++)
	{
		// We check if a vertex is adjacent to itself, if so it is a loop, we write them out.
		for(vector<int>::iterator j = b[i].begin(); j != b[i].end(); ++j)
			{
				if(i==*j)
				{
					cout << *j << ", ";
				}
			}
	}
}

void Vertices_Insulated(int a,vector<int> *b)
{
	cout<<endl<<"Izolowane wierzcholki to: ";
	// For a vertex the incoming degree and outgoing degree are checked, if both are equal to zero then the vertex is isolated.
	for(int i=1; i<=a; i++)
	{
		int x=0;
		int In=0;
		for(vector<int>::iterator j = b[i].end(); j != b[i].begin(); --j)
			{
				x++;
			}
		if(x==0)
		{
            for(int w=1; w<=a; w++)
            {
				for(vector<int>::iterator z = b[w].begin(); z != b[w].end(); ++z)
				{
					if(i==*z)
					{
						In++;
					}
				}
            }
            if(In==0)cout<<i<<", ";
		}
	}
}

void Bidirectional_Edges(int a,vector<int> *b)
{
	cout<<endl<<"Bidirectional edges exist between vertices: "; 
	/* Outgoingand incoming edges are compared if a vertex repeats in both situations,
	then there is a bidirectional edge between these vertices. */
	for(int i=1; i<=a; i++)
	{
		int In=0;
		for(vector<int>::iterator j = b[i].begin(); j != b[i].end(); ++j)
		{
			for(vector<int>::iterator z = b[*j].begin(); z != b[*j].end(); ++z)
            {
                if(i==*z)
                {
                     if(i<*j)cout<<i<<" <--> "<<*j<<", ";
                }
            }
		}
	}
}

int main()
{
	int n=9;
	vector<int> * GRAPH = new vector<int>[n+1]; // Graph adjacency list
	// For a vertex the incoming degree and outgoing degree are checked, if both are zero then the vertex is isolated.
	
	// Sample graph
	GRAPH[1].push_back(2); // We add new edges (start vertex and end vertex of the edge) to the end of the 'vector'.
	GRAPH[2].push_back(1);
	GRAPH[1].push_back(1);
	GRAPH[3].push_back(3);
	GRAPH[2].push_back(6);
	GRAPH[6].push_back(2);
	GRAPH[5].push_back(7);
	GRAPH[6].push_back(3);
	GRAPH[7].push_back(1);
	GRAPH[2].push_back(3);
	GRAPH[2].push_back(5);
	GRAPH[2].push_back(4);
	GRAPH[4].push_back(1);
	GRAPH[7].push_back(3);
	GRAPH[4].push_back(7);
	GRAPH[5].push_back(6);

	Edges_directed(n, GRAPH);      // We refer to the subfunction listing all directed edges of the given graph.
	cout << endl;
	Neighbours(n, GRAPH);                // We refer to the subfunction listing all neighbours for each vertex of the given graph.
	cout << endl;
	Indegree(n, GRAPH);       // We refer to the subfunction listing the incoming degrees of each vertex of the given graph.
	cout << endl;
	Outdegree(n, GRAPH);       // We refer to the subfunction listing the outgoing degrees of each vertex of the given graph.
	cout << endl;
	Loops(n, GRAPH);                   // We refer to the subfunction listing all loops in the given graph.
	cout << endl;
	Vertices_Insulated(n, GRAPH);    // We refer to the subfunction listing all isolated vertices in the given graph.
	cout << endl;
	Bidirectional_Edges(n, GRAPH); // We refer to the subfunction listing all bidirectional edges in the given graph.

	delete []GRAPH;     // At the end of the program we release the dynamic array memory.
	return 0;
}

