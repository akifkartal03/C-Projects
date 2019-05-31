#include<stdio.h>
#include<stdlib.h>
int size_of_str(char *str);
char *f(char str[],int chr);
void reverse_str(char str[],int size);
int main(){
	char str[10]="abcdapk";
	int chr=97,size;
	char *ptr;
	size=size_of_str(str);
	reverse_str(str,size);
	//printf("%s\n", str);
	ptr=&str[2];
	printf("%d\n",ptr );
	ptr=f(str,chr);
	printf("%d\n",ptr );
	
}
int size_of_str(char *str){
	int i;
	for (i = 0; str[i]!='\0'; ++i);
	return i;
}
void reverse_str(char str[],int size){

	int i;
	char temp;
	for (i = 0; i < size/2; ++i)
	{
		temp=str[i];
		str[i]=str[size-i-1];
		str[size-1-i]=temp;
	}
}
char *f(char str[],int chr){
	char c;
	char *p;
	c=(char)chr;
	if (str[0]=='\0')
	{
		return p;
	}
	else{

		if (str[0]==c)
		{
			p=&str[0];
			
		}
		if (p==&str[0])
		{
			return p;
		}
		else f(&str[1],chr);
		
	}
	return p;
}
