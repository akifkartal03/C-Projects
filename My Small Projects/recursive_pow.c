#include<stdio.h>

int recursive_pow(int base,int exponent);
int main(){

	int res;
	res=recursive_pow(5,4);
	printf("%d\n", res);
}
int recursive_pow(int base,int exponent){
	int result;
	if (exponent==0 && base==0)
	{
		return -1;
	}
	if (exponent==0)
	{
		return 1;
	}
	
	else{

		result=base*recursive_pow(base, exponent-1);
	}
	return result;
}