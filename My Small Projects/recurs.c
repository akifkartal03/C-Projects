#include<stdio.h>
int min_index(int arr[],int size);
int main(){
	int i,temp;
	int arr[5]={0,5,-5,-1,3};
	int index;
	for (i = 0; i <5; ++i)
	{
		index=min_index(&arr[i],5-i)+i;
		temp=arr[i];
		arr[i]=arr[index];
		arr[index]=temp;
	}
	for (i = 0; i <5; ++i)
	{
		printf("%d\n", arr[i]);
	}
	
	
}
int min_index(int arr[],int size){

	int i,index=1;
	for (i = 0; i < size; ++i)
	{
		if (arr[i]<arr[index])
		{
			index=i;
		}
	}
	return index;


}



