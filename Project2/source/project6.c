#include<stdio.h>
#define MAX_SIZE 100
/*prototypes of the functions*/
void non_recursive_menu(); //my menu function
int part1(int number1,int number2,int fact); // for common
void part2(int list[],int left,int right); //for sorting(recursively)
void merge(int list[], int left, int middle, int right); // helper funtion of part2
void recursive_copy(int list[],int arr[],int point,int size,int counter);// helper funtion of part2
void print_sorted_array(int arr[], int size);// helper funtion of part2
void part3(int number); // for calculate the formula
void part4(int number,int digit,int result,int tempnumber);//for fit number
int recursive_power(int base,int exponent);// helper funtion of part4
int recursive_number_of_digit(int number);// helper funtion of part4
void part5(char str[]); // for capital letter

int main(){

	non_recursive_menu(); // call menu function
	
}
void non_recursive_menu(){
	/*I wanted to do a recursive menu but in this case memory will using by this function very badly and 
	I may get a segmentation fault error so I didn't it instead of I used do-while loop */
	int choice,status,i,result_common=0,number1,number2,fact=2,lenght,number,digit=0;
	char str[30];
	int list[MAX_SIZE];
	do{
		printf("***** WELCOME TO WORLD OF RECURSIVE *****\n");
		printf("1. Find Common two numbers\n");
		printf("2. Sort your list by using merge sort\n");
		printf("3. Calculate the piecewise function for a number\n");
		printf("4. Calculate the number by using power and digits\n");
		printf("5. Find the uppercase letter\n");
		printf("6. Exit\n");
		printf("Choice: ");
		/*this is in order to check user's entery number or a character
		(I did this only for choice in order to write short code. other part of the code I didn't it)*/
		for(status=scanf("%d",&choice);status==0;status=scanf("%d",&choice)){ 
			//if the user enter a character instead of a number
			printf("Please Enter a Number between 1 and 6: ");
			getchar();//in order to prevent to entry infinite loop
		}
		while((choice<1) || (choice>6)){ //check the number
				
			printf("This is an invalid choice. Try again!\n");
			printf("Choice:");
			scanf("%d",&choice);	 
		}
		switch(choice){
		case 1:
			printf("Please Enter Number 1: ");
			scanf("%d",&number1);
			while(number1<2){ //check the number
			
				printf("Please Enter grater than 1: ");
				scanf("%d",&number1);	 
			}
			printf("Please Enter Number 2: ");
			scanf("%d",&number2);
			while(number2<2){ //check the number
			
				printf("Please Enter grater than 1: ");
				scanf("%d",&number2);	 
			}
			if (number1<number2) fact=number1;
			else fact=number2; //send to function smaller number as a parameter
			result_common=part1(number1,number2,fact);
			if(result_common==0) printf("There is no common number between these two numbers\n\n");
			else printf("Common : %d\n",result_common);
			break;

		case 2:
			printf("Enter a lenght number: ");
			scanf("%d",&lenght);
			while(lenght<=0){ //check the number
			
				printf("Please Enter greater than 0: ");
				scanf("%d",&lenght);	 
			}
			printf("Enter the elements of list: ");
			for (i = 0; i < lenght; i++)
			{
				scanf("%d",&list[i]); //get values from user
			}
			printf("Sorting the array ... ");
			part2(list,0,lenght-1); //call the function
			print_sorted_array(list, lenght); //print values
			break;
		case 3:
			printf("Enter a number: ");
			scanf("%d",&number);
			while(number<1){ //check the number
			
				printf("Please Enter grater than 0: ");
				scanf("%d",&number);	 
			}
			part3(number);
			break;
		case 4:
			printf("Please enter a number : ");
			scanf("%d",&number);
			digit=recursive_number_of_digit(number);// calculate the digit
			part4(number,digit,0,number);
			break;
		case 5:
			printf("Please enter a string : ");
			scanf("%s",str);
			part5(str);
			break;
		case 6:
			// this part is in the while's condition which is below
			break;

		default :

			printf("invalid value\n");
		}
	}while(choice!=6);
}
int part1(int number1,int number2,int fact){
	/*in here I send the smaller number as a parameter(fact) while decrasing it I checked is it common or not?*/
	if (fact==1) return 0; // there is no common number
	else{
		if (number1%fact==0 && number2%fact==0) return fact; //Is it common or not?
		else part1(number1,number2,fact-1);
	}

}
void part2(int list[],int left,int right){
	/*in here I am sorting an array by using merge sort algorithm*/
	int middle;
	if (left < right) 
    { 
       /*Function has to divide the list into two lists recursively until it can no more be divided*/
		middle = left+(right-left)/2;  
        part2(list, left, middle); 
        part2(list, middle+1, right); 
        /*After that it combines all elements with increasing order*/
        merge(list, left, middle, right);//call merge functions 
    } 

}
void merge(int list[], int left, int middle, int right){ 

    int l1 = middle - left + 1; //left side 
    int r1 =  right - middle; // right side
  
    /* create temp arrays */
    int Left[l1], Right[r1]; 
  	/*in here I didn't use for loop instead of I made a recursive_copy function
    /* copy data recursively to arrays Left[] and Right[] by using recursive_copy function that I wrote. */
    recursive_copy(list,Left, left,l1, 0); // left side of array
    recursive_copy(list,Right,middle+1,r1, 0); // right side of array
    /* merge the temp arrays*/
    // i, j, k: initial index of first, second, merged subarray respectively 
    int i = 0, j = 0, k = left; 
    /*until reach end of either left or right, pick smaller element and place them in the correct position at list[]*/
    for(; i < l1 && j < r1; k++)
    { 
        if (Left[i] <= Right[j]) //pick
        { 
            list[k] = Left[i++]; //place
        } 
        else
        { 
            list[k] = Right[j++]; //place 
        } 
    } 
    /* then copy the remaining elements of Left[], if there are any */
    for (; i < l1; k++, i++) 
    { 
        list[k] = Left[i];//copy 
    } 
  
    /* copy the remaining elements of Right[], if there are any */
    for (; j < r1; k++, j++) 
    { 
        list[k] = Right[j]; // copy
    } 
} 
// in here I want use recorsive even I know it is not good for memory.
void recursive_copy(int list[],int arr[],int point,int size,int counter){
	//counter=0(at the beginning)
	if (counter>=size)
	{
		return;//stop;
	}
	else{

		arr[counter]=list[point+counter];//copy
		counter=counter+1;
		recursive_copy(list, arr,point,size,counter);
	}

}
void print_sorted_array(int arr[], int size){
	//print array  
    int i; 
    printf("\nSorted array is : ");
    for (i=0; i < size; i++){
    	printf("%d ", arr[i]);
    }   
    printf("\n"); 
}
void part3(int number){

	if (number==1)//base case
	{
		printf("%d\n",number);
	}
	else{
		printf("%d  ",number );
		if (number%2==0) // if it is even
		{
			part3(number/2);
		}
		else{ //odd
			part3((3*number)+1);
		}
		
	}
}
void part4(int number,int digit,int result,int tempnumber){
	/*in here since I am playing with number I send a parameter temp number in order to use number's real value
	also I send digit and result(for keep result)*/
	if (number==0)
	{	
		
		if (result==tempnumber) printf("Equal\n");
		else printf("Not Equal\n");
	}
	else{

		result=result+recursive_power(number%10,digit);
		part4(number/10,digit,result,tempnumber);
		
	}

}
int recursive_power(int base,int exponent){
	/*in here I am calculating the power recursively*/
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

		result=base*recursive_power(base, exponent-1);
	}
	return result;
}
int recursive_number_of_digit(int number){
	/*in here I am calculating the number of digit recursively*/
	int digit;
	if (number==0)
	{
		return 0;
	}
	else{
		//increment the digit and call again
		digit=1+recursive_number_of_digit(number/10); 
	}
	return digit;
	
}
void part5(char str[]){
	int d;//in order to keep ascii code of character
	if (str[0]=='\0')
	{	
		printf("There is no Capital letter in the string.\n"); //print the letter
		return;//stop
	}
	else{
		d=str[0];//get ascii code
		/*if the letter capital*/
		if (d>=65 && d<=90)
		{
			printf("%c\n", str[0]); //print the letter
			return;
		}
		else part5(&str[1]);// call again
	}
}