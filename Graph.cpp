//#include<iostream>
//#include<unordered_map>
//#include<list>
//#include<queue>
#include<bits/stdc++.h>
using namespace std;

//template<typename T>

class Graph {
	public:
		unordered_map<int,list<int>>  adjList;
		void addEdge(int u, int v, bool direction) {
			if(direction == 1) {
				adjList[u].push_back(v);
			} else {
				adjList[u].push_back(v);
				adjList[v].push_back(u);
			}
//			cout<<endl<<"Printing adjList"<<endl;
//			printAdjList();
//			cout<<endl;
		}
		void printAdjList() {
			for(auto i:adjList) {
				cout<<i.first<<"-> {";
				for(auto neighbour:i.second) {
					cout<<neighbour<<", ";
				}
				cout<<"}"<<endl;
			}
		}
		bool checkCycleUndirectedBFS(int src) {
			queue<int> q;
			unordered_map<int,bool> visited;
			unordered_map<int,bool> parent;
			q.push(src);
			visited[src] = true;
			parent[src] = -1;
			
			while(!q.empty()) {
				int frontNode = q.front();
				q.pop();
				for(auto nbr:adjList[frontNode]) {
					if(!visited[nbr]) {
						q.push(nbr);
						visited[nbr] = true;
						parent[nbr] = frontNode;
					}
					else if(visited[nbr]==true && nbr!=parent[frontNode]) {
						return true;
					}
 				}
			}
			return false;
		}
};

//class Graph {
//	public:
//		unordered_map<T,list<pair<T,int>> > adjList;
//		
//		void addEdge(T u,T v,int  wt,bool direction) {
//			if(direction == 1) {
//				adjList[u].push_back({v,wt});
//			} else {
//				adjList[u].push_back({v,wt});
//				adjList[v].push_back({u,wt});
//			}
//		}
//		
//		void printAdjList() {
//			for(auto i:adjList) {
//				cout<<i.first<<": { ";
//				for(pair<T,int> p: i.second) {
//					cout<<"{"<<p.first<<", "<<p.second<<"}, ";
//				}
//				cout<<"}"<<endl;
//			}
//		}
//		
////		void bfsTraversal(T src) {
//		void bfsTraversal(T src, unordered_map<T,bool>& visited) {
////			unordered_map<T,bool> visited;
//			queue<T> q;
//			q.push(src);
//			visited[src] = true;
//			while(!q.empty()) {
//				T frontNode = q.front();
//				cout<<frontNode<<" ";
//				q.pop();
//				for(auto neighbour: adjList[frontNode]) {
//					T nbrData = neighbour.first;
//					if(!visited[nbrData]) {
//						q.push(nbrData);
//						visited[nbrData] = true;
//					}
//				}
//			}
//		}
//		
//		void dfs(T src, unordered_map<T,bool> &visited) {
//			visited[src] = true;
//			cout<<src<<" ";
//			for(auto nbr: adjList[src]) {
//				T nbrData = nbr.first;
//				if(!visited[nbrData]) {
//					dfs(nbrData,visited);
//				}
//			}
//		}
//};



int main() {
	
	Graph g;
	g.addEdge(0,1,0);
	g.addEdge(1,2,0);
	g.addEdge(1,3,0);
	g.addEdge(2,4,0);
	g.addEdge(3,4,0);
	g.addEdge(2,5,0);
	g.printAdjList();
	
	int src = 0;
	bool isCyclic = g.checkCycleUndirectedBFS(src);
	if(isCyclic) cout<<"Cycle Present!!"<<endl;
	else cout<<"Cycle not present!!"<<endl; 

//	Graph<int> g;
//	g.addEdge(0,1,5,0);
//	g.addEdge(1,2,10,0);
//	g.addEdge(1,3,20,0);
//	g.addEdge(2,3,50,0);
//	g.printAdjList();

//	Graph<char> g;
//	g.addEdge('a','b',5,0);
//	g.addEdge('a','c',10,0);
//	g.addEdge('b','c',20,0);
//	g.addEdge('c','d',50,0);
//	g.addEdge('c','e',50,0);
//	g.addEdge('e','f',50,0);
//	g.printAdjList();
//	
//	cout<<endl<<"BFS Traversal of given graph is: ";
//	g.bfsTraversal('a');

	
//	Graph<char> g;
//	cout<<"For Disconnected Graph--> "<<endl;
//	g.addEdge('a','b',5,0);
//	g.addEdge('b','c',10,0);
//	g.addEdge('d','e',20,0);
//	g.addEdge('f','f',50,0);
//	
//	cout<<endl<<"BFS Traversal of given graph is: ";
//	unordered_map<char,bool> visited;
//	for(char node='a';node<='f';node++) {
//		if(!visited[node]) {
//			g.bfsTraversal(node,visited);
//		}
//	}
	
//	cout<<endl<<"DFS Traversal of given graph is: ";
//	
//	Graph<char> gh;
//	gh.addEdge('a','b',5,0);
////	gh.addEdge('a','c',10,0);
//	gh.addEdge('c','d',20,0);
//	gh.addEdge('c','e',50,0);
//	gh.addEdge('d','e',20,0);
//	gh.addEdge('e','f',50,0);
//	unordered_map<char,bool> visited;
//	for(char node='a';node<='f';node++) {
//		if(!visited[node]) {
//			gh.dfs(node,visited);
//		}
//	}
//	gh.dfs('a',visited);
	
	return 0;
}