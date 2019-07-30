#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <climits>

using namespace std;

template <typename T>
class Graph{
	map<T, list<T> > adjList;

	void dfsHelper(T node,map<T,bool> &visited){
		cout<<node<<" ";

		visited[node] = true;

		for(auto neighbour:adjList[node]){
			if(!visited[neighbour]){
				dfsHelper(neighbour,visited);
			}
		}
	}

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

	void bfs(T src){
		queue<T> q;
		map<T,bool> visited;

		q.push(src);
		visited[src] = true;

		while(!q.empty()){
			T temp = q.front();

			cout<<temp<<" ";

			q.pop();

			for(auto neighbour:adjList[temp]){
				if(!visited[neighbour]){
					q.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}

		cout<<endl;
	}

	void bfs_shortestPath(T src){
		queue<T> q;
		map<T,int> dist;

		for(auto vertex:adjList){
			dist[vertex.first] = INT_MAX;
		}

		dist[src] = 0;
		q.push(src);

		while(!q.empty()){

			T temp = q.front();
			q.pop();

			for(auto neighbour:adjList[temp]){
				if(dist[neighbour]==INT_MAX){
					dist[neighbour] = dist[temp] + 1;
					q.push(neighbour);
				}
			}
		}

		for(auto vertex:adjList){
			cout<<"Distance of "<<vertex.first<<" from "<<src<<" is "<<dist[vertex.first]<<endl;
		}

	}

	void dfs(T src){
		map<T,bool> visited;

		dfsHelper(src,visited);
		cout<<endl;
	}

	bool isCyclicBFS(T src){
		queue<T> q;
		map<T,bool> visited;

		map<T,T> parent;

		q.push(src);
		visited[src] = true;
		parent[src] = src;

		while(!q.empty()){
			T temp = q.front();

			q.pop();

			for(auto neighbour:adjList[temp]){
				if(visited[neighbour] and parent[temp] != neighbour){
					return true;
				}else if(!visited[neighbour]){
					q.push(neighbour);
					visited[neighbour] = true;
					parent[neighbour] = temp; 
				}
			}
		}

		return false;
	}
};

int main(){

	// Graph<int> g;

	// g.addEdge(1,2);
	// g.addEdge(1,3);
	// g.addEdge(1,5);
	// g.addEdge(2,3);
	// g.addEdge(3,4);
	// g.addEdge(4,5);

	// g.display();
	// g.bfs(1);

	Graph<int> g;

	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(4,5);
	g.addEdge(5,6);

	cout<<g.isCyclicBFS(1)<<endl;

	// g.display();
	// g.bfs_shortestPath(1);

	// g.dfs(1);

	return 0;
}

