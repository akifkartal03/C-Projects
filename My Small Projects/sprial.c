#include<stdio.h>
void print_sprial(int arr[][9]);
int main(){

	int arr[9][9];
	print_sprial(arr);

}
void print_sprial(int arr[][9]){
	int i,j,k=0;
	
	for (i = 0; i <9; ++i)
	{	printf("----------------------------\n");
		
		if (i==0 && j==0)
		{
			for (j=0;j<9;j++)
			{
				printf("|%d ",++k );
			}
			printf("|\n");
		}
		else if(i==0 && j==9){
			for (j=0;j<9;j++)
			{
				printf("|%d ",++k );
			}
			printf("|\n");
		}	
		
	}
	printf("----------------------------\n");
}