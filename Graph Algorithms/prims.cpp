//Prim’s Minimum Spanning Tree (MST) Minium spanning tree;
#include<bits/stdc++.h>
using namespace std;
typedef pair<int ,int > ipair;
class graph{
	int n;
	list<pair<int ,int >> *adj;
public:
	graph(int n){
		this->n=n;
		adj=new list<ipair>[n];
	}
	void addEdge(int u,int v,int w){
		adj[u].push_back(make_pair(v,w));
		adj[v].push_back(make_pair(u,w));
	}
	void prim(int s);
};

void graph::prim(int s){
	int parent[n];
	vector<int> dist(n,99999999);
	int v,w,u,j=1;
	priority_queue<ipair,vector<ipair>,greater<ipair>> pq;
	pq.push(make_pair(0,s));
	dist[s]=0;
	while(!pq.empty()){
		u=pq.top().second;
		pq.pop();
		list<pair<int ,int >>::iterator i;
		for(i=adj[u].begin();i!=adj[u].end();++i){
			v=(*i).first;
			w=(*i).second;
			if(w && dist[v]>w){
				dist[v]=w;
				pq.push(make_pair(dist[v],v));
				parent[v]=u;
			}
		}
	}
	printf("Edge      Weight\n");
	for(int i=1;i<n;i++)
		printf("%d - %d     %d\n",parent[i],i,dist[i]);
}

int main(){
	graph g(5);
	
   g.addEdge(0,0,0);
   g.addEdge(0,1,2);
   g.addEdge(0,2,0);
   g.addEdge(0,3,6);
   g.addEdge(0,4,0);
   g.addEdge(1,1,0);
   g.addEdge(1,2,3);
   g.addEdge(1,3,8);
   g.addEdge(1,4,5);
   g.addEdge(2,2,0);
   g.addEdge(2,3,0);
   g.addEdge(2,4,7);
   g.addEdge(3,3,0);
   g.addEdge(3,4,9);
   g.addEdge(4,4,0);


 
    // Print the solution
    g.prim(0);
 
    return 0;
}