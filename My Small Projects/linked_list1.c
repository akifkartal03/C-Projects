#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	int digit;
	struct node *next;
}binarylist;
void bin2int_io(binarylist *head);
int bin2int(binarylist *bn);
int main(){

	int i,digit,result;
	binarylist *head;
	bin2int_io(head);
	result =bin2int(head);
	printf("Decimal : %d\n",result );

}
void bin2int_io(binarylist *head){

	int i,digit,result;
	binarylist *bn=(binarylist*)malloc(sizeof(binarylist));
	head = bn;
	for (i = 0; i < 8; ++i)
	{
		printf("Enter a digit: ");
		scanf("%d",&digit);
		bn->digit=digit;
		bn->next = (binarylist*)malloc(sizeof(binarylist));
		bn = bn->next;
	}
	

}
int bin2int(binarylist *bn){

	int sum=0,k=128;
	while(bn!=NULL){

		sum=sum+((bn->digit)*k);
		k=k/2;
		bn=bn->next;
	}
	return sum;

}

