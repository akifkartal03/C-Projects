#include<stdio.h>
typedef struct{
	int rent;
	int bill;
	int food;


}COST;
int main(){
	int people,sum;
	double result;
	COST a;
	printf("Enter the cost of rent,bill and food: ");
	scanf("%d%d%d", &a.rent , &a.bill , &a.food);
	printf("Enter number of people : ");
	scanf("%d",&people);
	sum= a.rent + a.bill + a.food;
	result=(double)sum/(double)people;
	printf("Total cost: %d\n",sum );
	printf("Cost per student: %.2f\n",result );

}