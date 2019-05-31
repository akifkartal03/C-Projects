#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	int value;
	struct node *nodep;
}node_t;
node_t *getnode();
void printlist(node_t *headp);
int main(){

	node_t *a;
	a=getnode();
	printlist(a);

}
node_t *getnode(){

	node_t *list;
	int data;
	printf("enter a number: ");
	scanf("%d",&data);

	if (data==-1)
	{
		list=NULL;
	}
	else{

		list=(node_t*)malloc(sizeof(node_t));
		list->value=data;
		list->nodep=getnode();
	}
	return list;
}
void printlist(node_t *headp){

	if(headp==NULL){

		return;
	}
	else{

		printf("%d\n",headp->value);
		printlist(headp->nodep);
	}
}