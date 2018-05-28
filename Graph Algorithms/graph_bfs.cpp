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
	void BFS(int s);
};

void graph::add_edge(int v, int w){
adj[v].push_back(w);	
}

void graph::BFS(int s){
bool *visit= new bool[v];
for(int i=0;i<v;i++)
visit[i]=false;
list<int> queue;
queue.push_back(s);
visit[s]=true;
list<int>::iterator i;
while(!queue.empty()){
	s=queue.front();
	queue.pop_front();
	printf("%d  ",s);
    for(i=adj[s].begin();i!=adj[s].end();++i)
    	if(!visit[*i]){
    		queue.push_back(*i);
    		visit[*i]=true;
    	}
}
printf("\n");
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
	g.BFS(s);
	return 0;
}