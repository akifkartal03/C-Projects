#include<stdio.h>
#include<math.h>

int recursive_ceil(int n);
int main(){

	int res;
	res=recursive_ceil(4);
	printf("%d\n", res);
}
int recursive_ceil(int n){
	static int result=1;
	if (n<=1)
	{
		return 1;
	}
	else{

		result=2*recursive_ceil(floor(n/2))+1;
	}
	return result;
}