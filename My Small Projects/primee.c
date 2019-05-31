#include<stdio.h>
int is_primee(int number);
void print_primes();
int main(){

	 print_primes();

}
void print_primes(){

	int i,flag=0,flag2=0;
	for ( i = 2; i < 1000; ++i)
	{
		flag=is_primee(i);
		flag2=is_primee(i+2);
		if (i%100==0)
		{
			printf("\n");
		}
		if (flag==1 && flag2==1)
		{
			printf("(%d - %d),", i,i+2);
		}
	}
}
int is_primee(int number){

	int i,kalan=0;
	for (i = 2; i <=number; ++i)
	{
		if (number%i==0)
		{
			kalan++;
		}
	}
	if (kalan>1)
		return 0;
	else
		return 1;

}