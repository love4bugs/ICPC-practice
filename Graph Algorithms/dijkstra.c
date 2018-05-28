
//using simple arrays
#include<stdio.h>
#include<limits.h>
int V=9;

int minDist(int dist[],bool sptSet[]){
	int min=INT_MAX,minIndex;
	for(int i=0;i<V;i++)
		if(sptSet[i]==false && dist[i]<=min){
			min=dist[i];
			minIndex=i;
		}
 	return minIndex;
}

void dijkstra(int src,int graph[][9]){
	bool sptSet[V];
	int dist[V];
	for(int i=0;i<V;i++){
		dist[i]=INT_MAX;
		sptSet[i]=false;
	}

	dist[src]=0;

	for(int v=0;v<V-1;v++){
		int s=minDist(dist,sptSet);
		sptSet[s]=true;
		for(int adj=0;adj<V;adj++)
			if(!sptSet[adj] && graph[s][adj] && dist[s]!=INT_MAX && dist[s]+graph[s][adj]<dist[adj])
				dist[adj]=dist[s]+graph[s][adj];
	}
	printf("vertex   DistanceFromSource\n");
	for(int i=0;i<V;i++)
		printf("%d 			%d\n",i,dist[i]);
}

int main(){
	int graph[9][9]={{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
	dijkstra(0,graph);
}