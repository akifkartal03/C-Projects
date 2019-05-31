#include<stdio.h>
int max_in(int *arr,int size,int iter);
int main(){

	int arr[10]={-6,-5,-3,-100,-25,-50,-2,-85,-78,-92};
	int size=10,max=0;
	max=max_in(arr,size,0);
	printf("%d\n",arr[max] );
	return 0;
}
int max_in(int *arr,int size,int iter){

	int max=0;
	if (iter==size-1)
	{
		return size - 1;

	}
	else{
		max=max_in(arr,size,iter+1);
		if (arr[max]>arr[iter])
		{
			return max;
		}
		else return iter;
		
	}
}