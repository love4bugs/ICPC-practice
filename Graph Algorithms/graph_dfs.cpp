#include<list>
#include<cstdio>
using namespace std;
class graph{
public:
	int v;
	list<int> *adj;
	graph(int v){
		this->v=v;
		adj=new list<int>[v];
	}
	void add_edge(int v,int w);
	void DFS(int s);
	void DFSutil(int v,bool visit[]);
};

void graph::add_edge(int v, int w){
adj[v].push_back(w);	
}

void graph::DFSutil(int v,bool visit[]){

visit[v]=true;
printf("%d  ",v);
list<int>::iterator i;
for(i=adj[v].begin();i!=adj[v].end();++i)
    	if(!visit[*i]){
    		DFSutil(*i,visit);
    	}
}

void graph::DFS(int s){
bool *visit= new bool[v];
for(int i=0;i<v;i++)
visit[i]=false;
DFSutil(s,visit);
}

int main(){
	int n,v,w,s,x;
	printf("Enter the No.of Vertices of Graph :");
	scanf("%d",&n);
	graph g(v);
	printf("Enter the edge v,w :");
	scanf("%d%d",&v,&w);
	while(v!=-1){
		g.add_edge(v,w);
		printf("Enter the edge v,w :");
		scanf("%d%d",&v,&w);
	}
	printf("Enter the source Node :");
	scanf("%d",&s);
	g.DFS(s);
	return 0;
}