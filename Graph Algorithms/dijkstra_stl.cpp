
//Dijkstra’s Shortest Path Algorithm using priority_queue of STL
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3
typedef pair<int ,int > ipair;
class graph{
	int v;
	list<pair<int ,int >> *adj;
public:
	graph(int v){
		this->v=v;
		adj= new list<ipair>[v];
	}
	void addEdge(int u,int v,int w);
	void dij(int src);
	};

void graph::addEdge(int u,int v,int w){
	adj[u].push_back(make_pair(v,w));
	adj[v].push_back(make_pair(u,w));

}

void graph::dij(int src){
	priority_queue<ipair,vector<ipair>,greater<ipair>> pq;
	vector<int> dist(v,INF);
	int v_a,w;
	pq.push(make_pair(0,src));
	dist[src]=0;
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		list<pair<int ,int >>::iterator i;
		for(i=adj[u].begin();i!=adj[u].end();++i){
			v_a=(*i).first;
			w=(*i).second;
			if(dist[v_a]>dist[u]+w){
				dist[v_a]=dist[u]+w;
				pq.push(make_pair(dist[v_a],v_a));
			}
		}
	}
	printf("vertex      DistanceFromSource\n");
	for(int j=0;j<v;j++)
		printf("%d          %d\n",j,dist[j]);
}

int main(){
	int n,u,v,w,s;
	printf("Enter the NO.OF vertices :");
	scanf("%d",&n);
	graph g(n);
	printf("Enter the Edges U,V and W, to stop Enter u=-1 :");
	scanf("%d%d%d",&u,&v,&w);
	while(u!=-1){
		g.addEdge(u,v,w);
		scanf("%d%d%d",&u,&v,&w);
	}
    printf("Enter the Source vertex:");
    scanf("%d",&s);
    g.dij(s);
    return 0;
}