#include<cstdio>
#include<list>
#include<stack>
using namespace std;
class graph{
	int v;
	list<int> *adj;
public:
	graph(int v){
		this->v=v;
		adj=new list<int>[v];
	}
	void addEdge(int u,int v){
		adj[u].push_back(v);
	}
	void Tutil(int v,bool visit[],stack<int> &s){
		visit[v]=true;
		list<int>::iterator i;
		for(i=adj[v].begin();i!=adj[v].end();++i)
		if(!visit[(*i)])
			Tutil(*i,visit,s);
		s.push(v);
	}
	void tsort(){
		bool visit[v];
		stack<int> s;
		for(int i=0;i<v;i++)
			visit[i]=false;
		for(int i=0;i<v;i++)
			if(!visit[i])
				Tutil(i,visit,s);
		while(!s.empty()){
			printf("%d  ",s.top());
			s.pop();
		}
	}
};

int main(){
	int n,v,w,s,x;
	printf("Enter the No.of Vertices of Graph :");
	scanf("%d",&n);
	graph g(n);
	printf("Enter the edge v,w :");
	scanf("%d%d",&v,&w);
	while(v!=-1){
		g.addEdge(v,w);
		printf("Enter the edge v,w :");
		scanf("%d%d",&v,&w);
	}
	g.tsort();
	return 0;
}