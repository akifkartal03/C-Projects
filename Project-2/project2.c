#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
/*prototypes of the functions*/
void menu();
int make_a_guess (int trial, int min, int max);
void print_distance(int *player,int *computer); // my auxiliary function
void show_scores(int score_human, int score_program);
void draw_hourglass (int height);
void draw_mountain_road (int length, int max_radius);
int main(){


	srand(time(0));
	menu();


}
void menu(){
	int choice;
	int height,N,max_radius;
	int player=0, computer=0;
	do{

		printf("***** MENU *****\n");
		printf("1. Play Lucky Number\n");
		printf("2. Draw Hourglass\n");
		printf("3. Draw Mountain Road\n");
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
		
			print_distance(&player,&computer);
			break;

		case 2:
			printf("Please enter a Height: ");
			scanf("%d",&height);
			while((height%2==0) || (height<1)){

				printf("Please enter a Valid(odd and grater then zero) Height: ");
				scanf("%d",&height);
			}
			draw_hourglass (height);

			break;

		case 3:
			printf("Please enter a length for Road: ");
			scanf("%d",&N);
			while(N<1){

				printf("Please enter a Valid Lenght: ");
				scanf("%d",&N);
			}
			printf("Please enter Radius: ");
			scanf("%d",&max_radius);
			while(max_radius<1){

				printf("Please enter a Valid Radius: ");
				scanf("%d",&max_radius);
			}
			draw_mountain_road (N, max_radius);

			break;

		case 4:
			// this part is in the while's condition which is below
			break;

		default :

			printf("invalid value\n");
		}


	}while(choice!=4); // if the user entry 4 then the loop is end otherwise it will contiune.	
	
}
int make_a_guess (int trial, int min, int max){
	int guess;
	printf("(Trial: %d) Make a guess between %d and %d: ", trial,min,max );
	scanf("%d",&guess);
	while(!( (guess>0) && (guess<=1024) )){

		printf("Please Enter a guess between 1 and 1024: ");
		scanf("%d",&guess);
	} 
	return guess;
}
void print_distance(int *player, int *computer){
	int trial=1,range,min=1,max=1024,guess;
	int LN=(rand()%(1024 - 1 + 1)) + 1; // create a random number between given range(1-1024)
	guess=make_a_guess (trial,  min,  max);
	while(1){
		range=abs(guess-LN);
		if (range==0) // it means that if(guess==LN)
		{	
			*player=*player+1;
			printf("***you win! the game***.\n");
			show_scores(*player, *computer);
			break;

		}
		if (trial>=10) // I did choose trial 10 if you want you can change
		{
			*computer=*computer+1;
			printf("Your Trial is END! You lost the Game :(\n");
			show_scores(*player, *computer);
			break;
			
		}
		else if (range>511 && range<1024) 
			printf("Distance is 10.\n");
		else if (range>255 && range<512)
			printf("Distance is 9.\n");
		else if (range>127 && range<256)
			printf("Distance is 8.\n");
		else if (range>63 && range<128)
			printf("Distance is 7.\n");
		else if (range>31 && range<64)
			printf("Distance is 6.\n");
		else if (range>15 && range<32)
			printf("Distance is 5.\n");
		else if (range>7 && range<16)
			printf("Distance is 4.\n");
		else if (range>3 && range<8)
			printf("Distance is 3.\n");
		else if (range>1 && range<4)
			printf("Distance is 2.\n");
		else if (range==1)
			printf("Distance is 1.\n");
		else{

			printf("Unknown Error Happened!.\n");

		}
		/*Update borders*/
		if (guess<LN)
		{
			if(guess>min){
				min=guess; // update min;
			}
			trial++; // update trial
			guess=make_a_guess (trial,  min,  max); // call the function again
		}
		else if(guess>LN){

			if(guess<max){
					
				max=guess; // update max
			}
			trial++; // update trial
			guess=make_a_guess(trial,  min,  max); // call the function again 
		}
				
	}
	
}
void show_scores(int score_human, int score_program){ 
	printf("Your Score: %d Program Score: %d\n\n", score_human,score_program );

}
void draw_hourglass (int height){
	int space=-1,c=0;
	printf("\n");
	for (int i = 0; i < height*2; i=i+2) // How many line contain the shape(I use this in order to determine how many star print)
	{
		
		if (height-i < 1) // after the middle of the shape(under part)
		{
			c=abs(height-i)+2;
			space=space-1;
			for (int k = 0; k < space; ++k)
			{
				printf(" ");
			}
			for (int j =0; j <c ; ++j)
			{
				printf("*");
			}
			printf("\n");
			
		}
		else{ // before the middler of the shape(upside)
			space++;
			for (int k = 0; k < space; ++k)
			{
				printf(" ");
			}
			for (int j = 0; j < height-i; ++j)
			{
				printf("*");
			}
			printf("\n");
			
		}
		
	}
	printf("\n");
	
}
void draw_mountain_road (int length, int max_radius){
	int radius;
	int space=0,flag=0;
	printf("\n");
	space=max_radius; // I did chose it.
	for (int i = 0; i < length; ++i) // create a series of radiues
	{

		radius= (rand()%((max_radius+1) - 0 + 0)) + 0; // create a random number between given range(0 - max_radius)
		flag++;
		
		if (flag%2!=0)  // in order to control the shape(if odd print another shape)
		{
				
			for (int j = 0; j < radius*2+1; ++j) // How many line contain the shape
			{
				if (j>radius) // after the middle of the shape
				{
					space++;
					for (int k = 0; k < space; ++k)
					{
						printf(" ");
					}
					printf("\\");
					printf("\n");
				}
				else if (j==radius) // at the middle of the shape
				{
						
					for (int k = 0; k < space; ++k)
					{
						printf(" ");
					}
					printf("|");
					printf("\n");
						
				}
				else{ // j<radius (before the middle of the shape)
						
					for (int k=0; k <space ; ++k)
					{
						printf(" ");
							
					}
					space--;
					printf("/");
					printf("\n");
						
				}
					
			}
		}
		else{ //(if flag is even then print another shape)

			for (int j = 0; j < radius*2+1; ++j) // How many line contain the shape
			{
				if (j>radius)// after the middle of the shape
				{
					space--;
					for (int k = 0; k < space; ++k)
					{
						printf(" ");
					}
					printf("/");
					printf("\n");
				}
				else if (j==radius)  // at the middle of the shape
				{
					space++;
					for (int k = 0; k < space; ++k)
					{
						printf(" ");
					}
					printf("|");
					printf("\n");
						
				}
				else{ // j<radius (// before the middle of the shape)
					space++;
					for (int k =0; k<space ; ++k)
					{
						printf(" ");
							
					}
					printf("\\");
					printf("\n");
						
				}
					
			}
			space--;			

		}	

			
	}
	
	printf("\n");

}
