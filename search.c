#include<stdio.h>
int binary_search(int *arr,int n,int se)
{
	int low=0,high=n-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(se==arr[mid]) return mid;
		else if(se>arr[mid]) low=mid+1;
		else high=mid-1;
	}
	return -1;
}
int main()
{
	int n,i,pos,mid,se;
	printf("enter n");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&se);
	pos=binary_search(arr,n,se);
	if(pos==-1)
	printf("element not found");
	else
	printf("element found at %d",pos);
	return 0;	
}
