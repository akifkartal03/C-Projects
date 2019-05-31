#include<stdio.h>
int size=0;
int rec(int x, int y);
void print_str(char names[10][15],int size);
int main(){

	/*int result;
	result = rec(3,4);
	printf("%d\n", result);*/
	char names[10][15]= { "Ali Veli","Ahmet Selvi","Melike Selen","Mehmet Yigit","Selen Karayel"};
	print_str(names,5);
}
int rec(int x, int y){


	if (!(x >0 && y>0))
	{
		return 0;
	}
	else{

		return rec(x, y - 1) + rec(x - 1, y) + x + y;
	}
}
void print_str(char names[10][15],int size){
	
	if (size==0) return;
	
	printf("%s\n", names[0]);
	print_str(&names[1], size-1);
	
}