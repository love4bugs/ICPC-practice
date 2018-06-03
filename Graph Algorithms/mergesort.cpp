#include<cstdio>
#include<vector>
#define m 9999
using namespace std;
void mergesort(int lo,int hi,int *a){
if(lo!=hi){
	int mid,i,j,k;
	mid=(hi+lo)/2;
	mergesort(lo,mid,a);
	mergesort(mid+1,hi,a);

	int b[100],c[100];
	for(i=lo,j=0;i<=mid;i++,j++)
		b[j]=a[i];
	b[j]=m;
	for(i=mid+1,j=0;i<=hi;i++,j++)
		c[j]=a[i];
	c[j]=m;
	k=lo;
	i=0;
	j=0;
	while(k!=hi+1){
		if(b[i]<c[j]){
			a[k]=b[i];
			i++;
		}
		else{
			a[k]=c[j];
			j++;
		}
		k++;
		}
}
}

int main(){
	int n,x;
	printf("Enter the No.of Elements :");
	scanf("%d",&n);
    int a[n];

	printf("Enter the Elements");
	for(int t=0;t<n;t++){
		scanf("%d",&x);
		a[t]=x;
	}
	mergesort(0,n-1,a);
	for(int i=0;i<n;i++)
		printf("%d  ",a[i]);
	return 0;
}