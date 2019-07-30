#include <iostream>
#include <list>
#include <map>

using namespace std;

template <typename T>
class Graph{
	map<T, list<T> > adjList;

public:
	void addEdge(T u,T v, bool bidir = true){
		adjList[u].push_back(v);

		if(bidir){
			adjList[v].push_back(u);
		}
	}

	void display(){
		for(auto vertex:adjList){
			cout<<vertex.first<<" -> ";

			for(auto neighbour:vertex.second){
				cout<<neighbour<<",";
			}
			cout<<endl;
		}
	}
};

int main(){

	Graph<int> g;

	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(1,5);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);

	g.display();

	return 0;
}