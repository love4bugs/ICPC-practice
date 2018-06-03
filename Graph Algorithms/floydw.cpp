#include<cstdio>
using namespace std;
#define v 4
#define INF 999999
void floyw(int graph[][4]){
int dist[v][v],i,j,k;
for(i=0;i<v;i++)
	for(j=0;j<v;j++)
		dist[i][j]=graph[i][j];

for(k=0;k<v;k++)
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			if(dist[i][j]>(dist[i][k]+dist[k][j]))
				dist[i][j]=dist[i][k]+dist[k][j];

printf("--------------The Shortest Distance Matrix---------------\n");
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			if(dist[i][j]==INF)
				printf("%5s","INF");
			else
		    printf("%3d  ",dist[i][j]);
	}
		printf("\n");
	}

}

int main(){
	int graph[4][4] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
    floyw(graph);
    return 0;
}
