#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct {

	int *ptr;
	int limit;
	int ei;
}arr;
void init(arr *ar);
void insert(arr *r,int index,int input);
int main(){
	arr ar;
	int index,input;
	init(&ar);
	printf("input: ");
	scanf("%d",&input);
	printf("index: ");
	scanf("%d",&index);
	insert(&r,index,input);
}
void init(arr *ar){
	int i;
	ar->limit=5;
	ar->ptr=(int *)calloc(ar->limit,sizeof(int));
	for (i = 0; i < 5; ++i)
	{
		
		ar->ptr[i]=0;
	}
	ar->ei=0;
	printf("Array:[");
	for (i = 0; i < ar->limit; ++i)
	{
		printf("%d,",ar->ptr[i]);
	}
	printf("]");
	printf("  limit: %d", ar->limit);
	printf("  EI: %d\n", ar->ei);
}

void insert(arr *r,int index,int input){
	int i,k=0;
	
	for (int i = 0; i < r->limit-1; ++i)
	{
		if (r->ptr[i]==0)
		{
			r->ei=r->ei+1;
		}
		r->ptr[i]=i+1;
		
	}
	if(index=r->limit){

		r->limit=r->limit+5;
		r->ptr=realloc(r->ptr,r->limit);
	}
	r->ptr[index]=input;
	
	
	/*for (i = 0; i < r->limit; ++i)
	{
		if (r->ptr[i]==0)
		{
			r->ptr[i]=input;
			k=1;
		}
		
	}
	if (k==0)
	{
		r->limit=r->limit+5;
		r->ptr=realloc(r->ptr,r->limit);

	}
	for (i = 0; i < r->limit; ++i)
	{
		if (r->ptr[i]==0)
		{
			r->ptr[i]=input;
			break;
		}
		
	}*/

	
	
}