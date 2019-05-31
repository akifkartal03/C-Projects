#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct {

	int *ptr;
	int limit;
	int ei;
}arr;
void init(arr *ar);
void insert(arr *r,int input,int index);
void show(arr *ar);
int main(){
	arr ar;
	int index,input,i;
	init(&ar);
	show(&ar);
	
	for (i = 0; i < ar.limit-1; ++i)
	{
		if (ar.ptr[i]==0)
		{
			ar.ei=ar.ei+1;
		}
		ar.ptr[i]=i+1;
		
	}
	ar.ei=ar.ei-1;
	do{

		printf("input: ");
		scanf("%d",&input);
		printf("index: ");
		scanf("%d",&index);
		insert(&ar,input,index);
		show(&ar);
	}while(input!=-2);
	
	/*printf("input: ");
	scanf("%d",&input);
	printf("index: ");
	scanf("%d",&index);
	insert(&ar,index,input);
	show(&ar);*/
}
void init(arr *ar){
	int i;
	ar->limit=5;
	ar->ptr=(int *)calloc(ar->limit,sizeof(int));
	for (i = 0; i < ar->limit; ++i)
	{
		ar->ptr[i]=0;
	}
	for (i = 0; i < ar->limit; ++i)
	{
		if (ar->ptr[i]==0)
		{
			ar->ei=i;
			break;
		}
		
	}
	
}
void show(arr *ar){
	int i;
	printf("Array:[");
	for (i = 0; i < ar->limit; ++i)
	{
		if (i==ar->limit-1)
		{
			printf("%d",ar->ptr[i]);
		}
		else{
			printf("%d,",ar->ptr[i]);
		}
		
	}
	printf("]");
	printf("  limit: %d", ar->limit);
	printf("  EI: %d\n", ar->ei);
}
void insert(arr *r,int input,int index){
	int i,k=0,temp,temp2;
	//arr temp;
	if (index!=-1)
	{
		if(index==r->limit){

			r->limit=r->limit+5;
			r->ptr=realloc(r->ptr,sizeof(int)*r->limit);
		}
		if (r->ptr[index]!=0)
		{
			if (index>=r->limit-2)
			{
				r->limit=r->limit+5;
				r->ptr=realloc(r->ptr,sizeof(int)*r->limit);
				r->ptr[index]=input;
			}
			else{
				temp=r->ptr[index];
				r->ptr[index]=input;
				r->ptr[index+1]=temp;
			}
			//temp=r->ptr[index];
			r->ei=r->ei+1;

		}
		else{

			
			r->ei=r->ei+1;
		}
	}
	else{
		r->ptr[index]=0;

	}

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
		for (i = 5; i < r->limit; ++i)
		{
			r->ptr[i]=0;
		}
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
