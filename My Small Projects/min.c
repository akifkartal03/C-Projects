#include<stdio.h>
void place_smallest(int arr[],int size,int *index);
int main(){
	int arr[10]={1,-1100,3,-2,-7,80,911};
	int index=1;
	place_smallest(arr,7,&index);
	printf("%d\n",index );

}
void place_smallest(int arr[],int size,int *index){

	if (size==0)
	{
		return;
	}
	else{
		if (arr[size-1]<arr[*index])
		{
			*index=size-1;
		}
		 place_smallest(arr,size-1,index);
	}
}