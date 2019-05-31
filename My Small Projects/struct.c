#include<stdio.h>

typedef struct{

	char name[20];
	double fat;
	double protein;
	double iron;
	double vitamin_B_12;
	int  calories;
	int cholestrol;
}food;
/*prototypes of the functions*/
double safe_to_eat (food current_food);
food getfood(void);
void get_food(food *ptr);
int main(){
	double result;
	food a;
	get_food(&a);
	printf("%s\n",a.name );
	printf("%f\n",a.fat );
	

}
double safe_to_eat (food current_food){

	double result;
	result=(300.0/(double)current_food.cholestrol)*(current_food.fat);	
	return result;
}
food getfood(void){

	food c;
	scanf("%s%lf%lf%lf%lf%d%d",c.name,
								&c.fat,
								&c.protein,
								&c.iron,
								&c.vitamin_B_12,
								&c.cholestrol,
								&c.calories);

	return (c);
}
void get_food(food *ptr){

	scanf("%s%lf%lf%lf%lf%d%d",ptr->name,
								&ptr->fat,
								&ptr->protein,
								&ptr->iron,
								&ptr->vitamin_B_12,
								&ptr->cholestrol,
								&ptr->calories);
}