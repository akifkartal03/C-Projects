#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	int digit;
	struct node *next;
}node_t;
node_t *getlist();
void reverse_nodes_between_n_to_m(node_t * list ,int n, int m);
int main(){

	node_t *list;
	int n,m;
	list =getlist();
	printf("enter n: ");
	scanf("%d",&n);
	printf("enter m: ");
	scanf("%d",&m);
	reverse_nodes_between_n_to_m(list ,n, m);

}
void reverse_nodes_between_n_to_m(node_t * list ,int n, int m){
	int i,temp,j,temp2;
	node_t * iter=list;
	node_t * iter2=list;
	int c=0;

	for (i =0; i <=(m-n)/2; ++i)
	{
		for (j=0 ; j <n+c; ++j)
		{
			iter=iter->next;

		}
		
		for (j=0 ; j <m-c; ++j)
		{
			iter2=iter2->next;

		}
		temp=iter2->digit;
		iter2->digit=iter->digit;
		iter->digit=temp;
		c++;
		iter=list;
		iter2=list;
	}
	printf("Reversed: ");
	while(list!=NULL){

		printf("%d ",list->digit);
		list=list->next;
	}
	

}
node_t *getlist(){

	node_t *list;
	int number;
	printf("Enter a number :");
	scanf("%d",&number);
	if (number==-1)
	{
		list=NULL;
	}
	else{

		list=(node_t*)malloc(sizeof(node_t));
		list->digit=number;
		list->next=getlist();
	}
	return list;
}