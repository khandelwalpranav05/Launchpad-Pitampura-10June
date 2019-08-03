#include <iostream>
#include <list>

using namespace std;


class Graph{

	int v;
	list<int> *l; // int *arr
public:
	Graph(int vertex){
		this->v = vertex;
		l = new list<int>[v+1];
	}

	void addEdge(int u,int v,bool bidir = true){
		l[u].push_back(v);
		if(bidir){
			l[v].push_back(u);
		}
	}

	void display(){
		for(int i=1;i<=v;i++){
			cout<<i<<" -> ";

			for(int neighbour:l[i]){
				cout<<neighbour<<",";
			}
			cout<<endl;

		}
	}
};

int main(){

	Graph g(5);

	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(1,5);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,5);

	g.display();
	

	return 0;
}