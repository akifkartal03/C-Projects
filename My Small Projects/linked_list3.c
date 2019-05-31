#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	int num;
	struct node * next;
}node_t;
node_t *getlist();
int summ(node_t *list);
void printlist(node_t *list);
int main(){
	int sum=0;
	node_t *list;
	list =getlist();
	printlist(list);
	sum=summ(list);
	printf("\nsum :%d\n",sum);

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
		list->num=number;
		list->next=getlist();
	}
	return list;
}
int summ(node_t *list){
	int sum=0;
	while(list!=NULL){

		sum=sum+list->num;
		list=list->next;
	}
	return sum;
}
void printlist(node_t *list){
	printf("İnput numbers: ");
	while(list!=NULL){

		printf("%d ",list->num);
		list=list->next;
	}
}