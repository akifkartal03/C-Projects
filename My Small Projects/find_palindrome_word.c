#include<stdio.h>

int palindrome(char * str,int size,int iter);
int size_str(char * str);
int main(){
	char str[10]="kavak";
	int size,res,a;
	size=size_str(str);
	a=palindrome(str,size,size/2);
	printf("%d\n", a);
}
int palindrome(char * str,int size,int iter){
	static int result=1;
	if (str[0]=='\0')
	{
		return result;
	}
	if (size==iter)
	{
		return result;
	}
	else{
		if (str[0]!=str[size-1])
		{
			result=0;
		}
		else{
			size--;
			palindrome(&str[1],size-1,iter);
		}
		
	}
	return result;
}
int size_str(char * str){

	int i;
	for ( i = 0; str[i]!='\0'; ++i);
	return i;
}