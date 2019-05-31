#include<stdio.h>
#include<string.h>
int numOfOcc(char* str, char key, char limit);
int main(){
	int count;
	char str[35]="a sample string for demonstration";
	char key='w';
	char limit='z';
	count=numOfOcc(str, key, limit);
	printf("%d\n",count );
}
int numOfOcc(char* str, char key, char limit){
	static int count=0;
	if (str[0]==limit)
	{
		return count;
	}
	if (str[0]=='\0')
	{
		return count;
	}
	else{

		if (str[0]==key) count++;
		numOfOcc(&str[1],key,limit);
	}
	return count;

}