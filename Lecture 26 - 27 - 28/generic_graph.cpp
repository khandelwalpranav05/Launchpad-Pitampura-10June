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

	void topologicalSortHelperDFS(T node,map<T,bool> &visited,list<T> &order){
		visited[node] = true;

		for(auto neighbour:adjList[node]){
			if(!visited[neighbour]){
				topologicalSortHelperDFS(neighbour,visited,order);

				
			}
		}

		//push_front
		order.push_front(node);

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

	void topologicalSortDFS(){

		map<T,bool> visited;
		list<T> order;

		for(auto i:adjList){
			if (!visited[i.first]){
				topologicalSortHelperDFS(i.first,visited,order)	;
			}
		}

		for(auto var:order){
			cout<<var<<" -> ";
		}
		cout<<endl;

	}

	void topologicalSortBFS(){
		queue<T> q;
		map<T,int> indegree;

		for(auto vertex:adjList){
			indegree[vertex.first] = 0;
		}

		for(auto vertex:adjList){
			for(auto neighbour:vertex.second){
				indegree[neighbour]++;
			}
		}

		for(auto vertex:adjList){
			if(indegree[vertex.first]==0){
				q.push(vertex.first);
			}
		}

		while(!q.empty()){
			T node = q.front();
			q.pop();

			cout<<node<<" -> ";

			for(auto neighbour:adjList[node]){
				indegree[neighbour]--;

				if(indegree[neighbour]==0){
					q.push(neighbour);
				}
			}
		}

	}

	int snake_and_ladder(T src,T dest){
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

		// for(auto vertex:adjList){
		// 	cout<<"Distance of "<<vertex.first<<" from "<<src<<" is "<<dist[vertex.first]<<endl;
		// }

		return dist[dest];
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

	// Graph<int> g;

	// g.addEdge(1,2);
	// g.addEdge(1,3);
	// g.addEdge(1,4);
	// g.addEdge(2,3);
	// g.addEdge(3,5);
	// g.addEdge(4,5);
	// g.addEdge(5,6);

	// cout<<g.isCyclicBFS(1)<<endl;

	// g.display();
	// g.bfs_shortestPath(1);

	// g.dfs(1);


	// Graph<string> g;

	// g.addEdge("Maths","Programming",false);
	// g.addEdge("Programming","Java",false);
	// g.addEdge("Java","JS",false);
	// g.addEdge("Programming","Python",false);
	// g.addEdge("Python","Web",false);
	// g.addEdge("JS","Web",false);

	// cout<<"DFS"<<endl;
	// g.topologicalSortDFS();
	// cout<<"BFS"<<endl;
	// g.topologicalSortBFS();

	Graph<int> g;

	int board[50] = {0};

	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = -10;
	board[32] = -2;
	board[34] = -22;

	for(int i=0;i<=36;i++){
		for(int dice = 1;dice<=6;dice++){
			int u = i;
			int v = u + dice + board[u + dice];

			g.addEdge(u,v,false);
		}
	}

	cout<<g.snake_and_ladder(0,36)<<endl;

	// x + dice + board[x+dice]


	return 0;
}



