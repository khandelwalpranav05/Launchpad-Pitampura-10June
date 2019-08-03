#include <iostream>
#include <map>
#include <set>
#include <list>
#include <climits>

using namespace std;

template<typename T>
class Graph{
	map<T,list<pair<T,int> > > adjList;
public:
	void addEdge(T u,T v,int weight,bool bidir = true){
		adjList[u].push_back(make_pair(v,weight));

		if(bidir){
			adjList[v].push_back(make_pair(u,weight));
		}
	}

	void display(){
		for(auto vertex:adjList){
			T node = vertex.first;

			cout<<node<<" -> ";

			for(auto ed:vertex.second){
				cout<<"("<<ed.first<<","<<ed.second<<")";
			}
			cout<<endl;
		}
	}

	void dijkstra(T src){
		map<T,int> dist;
		set<pair<int,T> > manage;

		for(auto vertex:adjList){
			dist[vertex.first] = INT_MAX;
		}

		dist[src] = 0;

		manage.insert(make_pair(0,src));

		while(!manage.empty()){

			auto val = *(manage.begin());

			T node = val.second;

			int nodeDist = val.first;

			manage.erase(manage.begin());

			for(auto neighbour:adjList[node]){
				if(nodeDist + neighbour.second < dist[neighbour.first]){
					T destination = neighbour.first;

					auto locate = manage.find(make_pair(dist[destination],destination));

					if(locate!=manage.end()){
						manage.erase(locate);
					}

					dist[destination] = nodeDist + neighbour.second;

					manage.insert(make_pair(dist[destination],destination));
				}
			}
		}

		for(auto val:dist){
			cout<<"Distance of "<<val.first<<" from src is "<<val.second<<endl;
		}
	}
};

int main(){

	// Graph<char> g;

	// g.addEdge('x','y',7);
	// g.addEdge('x','z',8);
	// g.addEdge('y','z',2);
	// g.addEdge('z','w',4);

	Graph<int> g;

	g.addEdge(1,2,1);
	g.addEdge(1,3,5);
	g.addEdge(1,4,8);
	g.addEdge(2,3,1);
	g.addEdge(3,4,3);

	g.display();

	g.dijkstra(1);

	return 0;
}