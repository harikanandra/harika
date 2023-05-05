#include<stdio.h>
#define min(a,b) a<b ?a:b
void merge(int *arr,int L,int M,int R){
	int res[R-L+1];
	int i=L,j=M+1,k=0,z;
	while(i<=M && j<=R){
		if(arr[i]<=arr[j]){
			res[k++]=arr[i++];
		}
		else
		res[k++]=arr[j++];
	}
	while(i<=M)
	res[k++]=arr[i++];
	while(j<=R)
	res[k++]=arr[j++];
	k=0;
	for(z=L;z<=R;z++){
		arr[z]=res[k++];
	}
}
void merge_sort(int *arr,int n)
{
	int L,R,M,p,i;
	for(p=1;p<n;p*=2)
	{
		for(i=0;i<n;i+=2*p)
		{
			L=i;
			R=min(L+2*p-1,n-1);
			M=min(L+p-1,n-1);
			merge(arr,L,M,R);
		}
	}
}
int main()
{
	int L=0,i,M,n;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	merge_sort(arr,n);
	for(i=0;i<n;i++)
	printf("%d\t",arr[i]);
}
