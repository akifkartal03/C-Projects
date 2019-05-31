#include<stdio.h>
typedef enum{FALSE, TRUE}bool;
int is_element(char str[][15],char c);
int size(char a[15]);
int main(){
	char str[10][15]={"abc", "sbc", "dsds"};
	char c='t';
	int result;
	result=is_element(str,c);
	printf("%d\n",result );
}
int is_element(char str[][15],char c){

	int i,j,result=0;
	for (i = 0; str[i][0]!='\0'; ++i)
	{
		for (j = 0; j < size(str[i]); ++j)
		{
			if (str[i][j]==c)
			{
				result=1;
			}
		}
	}
	return result;
}
int size(char a[15]){
	int i;
	for (i = 0; a[i]!='\0' ; ++i);
	return i;
}
