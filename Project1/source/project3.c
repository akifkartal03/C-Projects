#include<stdio.h>
#define hw_lab 10
#define exam 2

/*prototypes of the functions*/
void menu(); // my auxiliary function
void manage_operation(); // my auxiliary function 
int add(int number1, int number2);
int sub(int number1, int number2);
int mult(int number1, int number2);
int divi(int number1, int number2);
int power(int number1, int number2);
int modulo(int number1, int number2);
int doit (int operator(), int first_number, int second_number);
int take_grades(int hw_or_lab[] );
int take_exam_grades(int exams[]);
double calculate_homework(int hw[]);
double calculate_lab(int lab[]);
double calculate_all(int hw,int exams[],int lab);
void print_shape(int height); // my auxiliary function

int main(){

	
	menu();
	return 0;
	

}
void menu(){
	int height,choice;
	int avarage_of_hw , avarage_of_labs;
	double avarage_all;
	int homeworks[hw_lab],labs[hw_lab], exams[exam];
	do{

		printf("\n***** MENU *****\n");
		printf("1. Calculator Program\n");
		printf("2. Calculate Grades\n");
		printf("3. Draw the Shape\n");
		printf("4. Exit\n");
		printf("Choice: ");
		scanf("%d",&choice);
		while((choice<1) || (choice>4)){
			
			printf("This is an invalid choice. Try again!\n");
			printf("Choice:");
			scanf("%d",&choice);
			 
		}
		switch(choice){
		case 1:
			manage_operation();
			break;

		case 2:
			printf("**Please Enter Homework Grades**\n\n");
			take_grades(homeworks);
			printf("\n");
			printf("**Please Enter Lab Grades**\n\n");
			take_grades(labs);
			printf("\n");
			printf("**Please Enter Exam Grades(Middterm and Final)**\n\n");
			take_exam_grades(exams);
			avarage_of_hw=calculate_homework(homeworks);
			avarage_of_labs=calculate_lab(labs);
			avarage_all=calculate_all(avarage_of_hw,exams,avarage_of_labs);
			printf("\nAverage: %.2f\n\n", avarage_all);
			break;

		case 3:
			
			printf("Please enter a Height: ");
			scanf("%d",&height);
			while((height<1)){

				printf("Please enter a Valid(grater then zero) Height: ");
				scanf("%d",&height);
			}
			print_shape(height);
			break;

		case 4:
			// this part is in the while's condition which is below
			break;

		default :

			printf("invalid value\n");
		}


	}while(choice!=4); // if the user entry 4 then the loop is end otherwise it will contiune.

}
void manage_operation(){

	char line[50]; // in order to keep one line
	char operator[2]; // in order to keep operator symbol
	int number1,number2,flag=0,result=1,ascii;
	char c;
	printf("\n**WELCOME THE CALCULATOR**\n");
	printf("For Addition Enter '+'\n");
	printf("For subtraction Enter '-'\n");
	printf("For Multiplication Enter '*'\n");
	printf("For Division Enter '/'\n");
	printf("For Power Enter '**'\n");
	printf("For Modulo Enter 'o/o'\n");
	printf("For Exit 'e'\n");
	printf("-Please Enter Values in a Line Carefully e.g. (+ 10 2):\n");
	while(1){
		number1=0;
		number2=0;
		do{ // in order to check values enter corrrectly
			for (int i = 0; i < 50; ++i) // this is in order to clear in the array 
			{
				
				line[i]='\0';

			}
			for (int i = 0; i < 50; ++i) // get a line from user
			{
				c=getchar();
				if (c==10) // if user click the enter button  then stop
				{
					break; // stop
				}
				line[i]=c; // otherwise save them

			}
			
		}while(line[1]!=' ' && line[0]!='e'); //check values enter corrrectly
		sscanf( line, "%s %d %d", operator,  &number1, &number2 ); // split the line from the space and save them.
		ascii=operator[0]; // ascii code of operator(because switch case just accept int values)
		if (ascii==101) // if it is "e" then exit 
		{
			break; // exit
		}
		if (number2!=0) //If the operator has more than one argument
		{
			if (operator[1]!='\0') // it means user entry "**"
			{
				result=doit (power, number1, number2);
				printf("%d\n",result);
					
			}
			else{
				switch(ascii){
				case 43://+
					result=doit(add, number1, number2);
					printf("%d\n",result);
					break;
				case 45://-
					result=doit (sub, number1, number2);
					printf("%d\n",result);
					break;
				case 42://*
					result=doit (mult, number1, number2);
					printf("%d\n",result);
					break;
				case 47:// /
					result=doit (divi, number1, number2);
					printf("%d\n",result);
					break;
				case 37:// %
					result=doit (modulo, number1, number2);
					printf("%d\n",result);
					break;
				default:
					printf("-Please Enter Values in a Line Carefully e.g. (+ 10 2):\n");

				}
			}
			
		}
		else{ //If the operator has only one argument
			if (result==1) // If there is no previous operation (e.g., at the very beginning)
			{
				if (operator[1]!='\0') // it means user entry **
				{
					result=doit (power, number1, 0);
					printf("%d\n",result);
						
				}
				else{

					switch(ascii){
					case 43: // +
						result=doit(add, number1, 0);
						printf("%d\n",result);
						break;
					case 45: // -
						result=doit(sub, number1, 0);
						printf("%d\n",result);
						break;
					case 42: // *
						result=doit(mult, number1, 0);
						printf("%d\n",result);
						break;
					case 47: // /
						result=doit(divi, number1, 0);
						printf("%d\n",result);
						break;
					case 37: // %
						result=doit(modulo, number1, 0);
						printf("%d\n",result);
						break;
					default:
						printf("-Please Enter Values in a Line Carefully e.g. (+ 10 2):\n");

					}
				}
				
			}
			else{ //If there is a previous operation

				if (operator[1]!='\0') // it means user entry **
				{
					result=doit (power, result, number1);
					printf("%d\n",result);
						
				}
				else{
					switch(ascii){
					case 43: //+
						result=doit(add, result, number1);
						printf("%d\n",result);
						break;
					case 45://-
						result=doit (sub, result, number1);
						printf("%d\n",result);
						break;
					case 42: // *
						result=doit (mult, result, number1);
						printf("%d\n",result);
						break;
					case 47: // /
						result=doit (divi, result, number1);
						printf("%d\n",result);
						break;
					case 37: //%
						result=doit (modulo, result, number1);
						printf("%d\n",result);
						break;
					default:
						printf("-Please Enter Values in a Line Carefully e.g. (+ 10 2):\n");

					}
				}
				

			}
			
		}
	}	

}
int add(int number1, int number2){
	return number1+number2;

}
int sub(int number1, int number2){
	return number1-number2;

}
int mult(int number1, int number2){
	return number1*number2;
}
int divi(int number1, int number2){
	return number1 / number2;
}
int power(int number1, int number2){
	int result=1;
	for (int i = 0; i < number2; ++i)
	{
		result=result*number1;
	}
	return result;
}
int modulo(int number1, int number2){
	int result;
	result=number1%number2;
	return result;
}
int doit (int operator(), int first_number, int second_number){
	int result;
	result=operator(first_number,second_number);
	return result;
}
int take_grades(int hw_or_lab[]){

	for (int i = 1; i <= hw_lab; ++i)
	{
		printf("Please Enter %d. Grades: ",i);
		scanf("%d",&hw_or_lab[i-1]);
		while(hw_or_lab[i-1]<0 || hw_or_lab[i-1]>100 ){
			
			printf("This is an invalid entry. Try again!\n");
			printf("Please Enter %d. Grades Again: ",i);
			scanf("%d",&hw_or_lab[i-1]);
			 
		}
	}

	return 0;
}
int take_exam_grades(int exams[]){

	for (int i = 1; i <= exam; ++i)
	{
		printf("Please Enter %d. Grades: ",i);
		scanf("%d",&exams[i-1]);
		while(exams[i-1]<0 || exams[i-1]>100){
			
			printf("This is an invalid entry. Try again!\n");
			printf("Please Enter %d. Grades Again: ",i);
			scanf("%d",&exams[i-1]);
			 
		}
	}
	return 0;

}
double calculate_homework(int hw[]){
	
	double sum=0,result=0;
	for (int i = 0; i <hw_lab; ++i)
	{
		sum=sum+hw[i];
	}
	result=sum/hw_lab;
	return result;


}
double calculate_lab(int lab[]){
	double sum=0,result=0;
	for (int i = 0; i <hw_lab; ++i)
	{
		sum=sum+lab[i];
	}
	result=sum/hw_lab;
	return result;

}
double calculate_all(int hw,int exams[],int lab){
	double sum=0;
	sum= (hw*0.1)+(lab*0.2)+(exams[0]*0.3)+(exams[1]*0.4); //calculate
	return sum;

}
void print_shape(int height){

	int space,flag=1,star=2;;
	space=height-1;
	printf("\n");
	if (height==1) // there is no star.
	{
		printf("/\\\n");
		printf("\\/\n\n");
	}
	else{

		for (int i = 0; i < height*2; i=i+1) // How many line contain the whole shape
		{
			
			if (height-i > 0) // before the middle of the shape(upside)
			{
				for (int k = 0; k < space; ++k)
				{
					printf(" ");
				}
				if (flag==1){ // at the first step and last step there is no star

					printf("/");
					printf("\\\n");
				} 
				else{

					printf("/");
					for (int k = 0; k < star; ++k)
					{
						printf("*");
					}
					printf("\\\n");
					if (star!=(height-1)*2) //(x-1)2
					{
						star=star+2;
					}
					
				} 
				space--;
				flag++;
					
			}
			else{ //after the middle of the shape(under part) 
				
				space=space+1;
				for (int k = 0; k < space; ++k)
				{
					printf(" ");
				}
				printf("\\");
				for (int j =0; j<star ; ++j)
				{
					printf("*");
				}
				printf("/\n");
				star=star-2;
			
			}
			
		}
		printf("\n");
	}
	

}
