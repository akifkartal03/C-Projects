#include<stdio.h>
#include<stdlib.h>
int size_str(const char *ptr);
void add_binary(char *b1 , char *b2 ,char * result);
int main(){
	char str1[10]="0011010";
	char str2[10]="1101110";
	char result[10];
	add_binary(str1 , str2 ,result);
	printf("%s + %s = %s\n",str1,str2,result );
	
}
int size_str(const char *ptr){
	int i;
	for (i = 0; ptr[i]!='\0'; ++i);
	return i;
	
}
void add_binary(char *b1 , char *b2 ,char * result){
	int size,arr[10],arr2[10],arr3[10];
	int sum=0,remain=0,flag=0;
	size=size_str(b1);
	
	for (int i = 0; i <size ; ++i)
	{
		if (b1[i]=='1') arr[i]=1;
		else if (b1[i]=='0') arr[i]=0;
		else arr[i]=0;
	}
	size=size_str(b2);
	for (int i = 0; i <size ; ++i)
	{
		if (b2[i]=='1') arr2[i]=1;
		else if (b2[i]=='0') arr2[i]=0;
		else arr2[i]=0;
	}
	for (int i = size-1; i>=0 ; i--)
	{
		sum=arr[i]+arr2[i]+remain;
		remain=0;
		switch(sum){
		case 0:
			flag=0;
			break;
		case 1:
			flag=1;
			break;
		case 2:
			flag=0;
			remain=1;
			break;
		case 3:
			flag=1;
			remain=2;
			break;
		default:
			printf("olmadı\n");
		}
		arr3[i]=flag;
		sum=0;

	}
	printf("%d\n",size );
	for (int i = 0; i <size ; ++i)
	{
		if (arr3[i]==1) result[i]='1';
		else if (arr3[i]==0) result[i]='0';
		else result[i]='0';
	}
	

}

