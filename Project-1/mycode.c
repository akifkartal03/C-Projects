#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
/*pre-defines*/
#define square 1
#define rectangular 2
#define circular 3
#define red 0
#define yellow 1
#define blue 2
#define black 3
#define white 4
#define PI 3
/*prototypes of the functions*/
double CreateBody (int shape);
int SetColor (int color);
double LoadMoves(int shape, double body_size);
int SetAtackPower(int lower_bound, int upper_bound);
void ShowPokemon(int shape, double body_size, int color, double move_length, int attack_power);

int main(){
	
	int shape, color, attack_power;
	double size_of_body, move_length;
	shape = circular; // Pick one of them
	size_of_body = CreateBody (shape);
	color = 798;
	color = SetColor(color);
	move_length = LoadMoves(shape, size_of_body);
	attack_power = SetAtackPower(0,150);
	ShowPokemon(shape, size_of_body, color, move_length, attack_power);

	return 0;
}
/*functions*/
double CreateBody (int shape){
	
	if(shape==1){ // square
		int edge_of_sqr;
		printf("Please enter lenght of edge : ");
		scanf("%d",&edge_of_sqr);
		return edge_of_sqr*edge_of_sqr;

	}
	else if(shape==2){ // rectengular
		int edge_long,edge_short;
		printf("Please enter lenght of long edge : ");
		scanf("%d",&edge_long);
		printf("Please enter lenght of short edge : ");
		scanf("%d",&edge_short);
		return edge_short*edge_long; 

	}
	else if(shape==3){ // circular
		int radious;
		printf("Please Enter a  radious: ");
		scanf("%d",&radious);
		while(radious<1){
			printf("Please Enter a valid radious: ");
			scanf("%d",&radious);

		}
		return PI*radious*radious;

	}
	else{
		printf("Please enter a value between 1 and 3 ");
		return 0;

	}



}
int SetColor (int color){

	int revised_color;
	if (color>0 && color<1000)
	{
		revised_color = color % 5;
		return revised_color;

	}
	else{

		return 1;
	}

}
double LoadMoves(int shape, double body_size){


	
	if(shape==1){ // square
		double one_edge_sqr,perimeter_of_sqr;
		one_edge_sqr=sqrt(body_size);
		perimeter_of_sqr=(double)4*one_edge_sqr;
		return perimeter_of_sqr;

	}
	else if(shape==2){ // rectangle

		double long_edge_rect,perimeter_of_rect;
		long_edge_rect=body_size/5;
		perimeter_of_rect=2*(5+long_edge_rect); //Assume that the shorter edge is 5 if the shape is rectangular
		return perimeter_of_rect;

	}
	else if(shape==3){ // circular
		double radious,perimeter_of_crc;
		radious=sqrt(body_size/PI);
		perimeter_of_crc= (double)2*PI*radious;
		return perimeter_of_crc;

	}
	
	

}
int SetAtackPower (int lower_bound, int upper_bound){
	srand(time(0));
	int attack_power;
	attack_power =(rand()%(upper_bound - lower_bound + 1)) + lower_bound; // create a random number between given range
	return attack_power;


}
void ShowPokemon(int shape, double body_size, int color, double move_length, int attack_power){

	char clr[15];//string
	switch(color){
		case 0:
			strcpy(clr,"Red");
			break;
		case 1:
			strcpy(clr,"Yellow");
			break;
		case 2:
			strcpy(clr,"Blue");
			break;
		case 3:
			strcpy(clr,"Black");
			break;
		case 4:
			strcpy(clr,"White");
			break;		
		default:
			strcpy(clr,"Unknown Color");
	} 
	if(shape==1){ //square
		double one_edge_sqr;
		one_edge_sqr=sqrt(body_size);
		for (int i = 0; i < one_edge_sqr; ++i)//for row
		{
			for (int i = 0; i < one_edge_sqr; ++i)// for column 
			{
				printf("X");
			}
			printf("\n");
		}
		printf("\n");
		printf("Name : Square pokémon\n");
		printf("Size: %d\n",(int)body_size);//because of being square
		printf("Color: %s\n",clr); //color
		printf("Move: %d\n",(int)move_length);// because of being square
		printf("Attack Power: %d\n", attack_power);
		
	}
	else if(shape==2){ //rectangle

		int long_edge_rect;
		long_edge_rect=body_size/5; //(Assume that the shorter edge is 5 if the shape is rectangular) /*calcute the other edge by using area*/
		for (int i = 0; i < 5; ++i)//for row(5)
		{
			for (int i = 0; i < long_edge_rect; ++i)// for column 
			{
				printf("X");
			}
			printf("\n");
		}
		printf("\n");
		printf("Name : Rectangular pokémon\n");
		printf("Size: %d\n",(int)body_size); // because being ractangle
		printf("Color: %s\n",clr); // color
		printf("Move: %d\n",(int)move_length); //because being ractangle
		printf("Attack Power: %d\n", attack_power);
	}
	else if(shape==3){ //circular 
		int radious;
		radious=sqrt((int)body_size/PI);
		int i,j,c,b=0;
		/*Print Circle*/
		
		if (radious%2==0) /* EVEN RADIOUS*/ 
		{
			c=1; // for space or tab
			b=radious/2; // condition for loop 
			
			for(i = 0; i <b+1; i++) { // half of the circle
				
				if(i==0){
					for(j = 1; j <= b-1; j++){
		      	
		      			printf("\t");
		      			
					}
		        	printf("    ");
					printf("X");
		         	printf("\n");
				}
				else{
					for(j = 1; j <= b-i; j++){
		      	
		      			printf("\t");
					}
					printf("X");
					for(j = 1; j <= c; j++){
		      	
		      			printf("\t");
					}
					c=c+2;
					printf("X");
					printf("\n");
				}
		      
		   }
		   c=c-2; 
		   for(i = b; i >0; i--) { // other half of the circle
		        
				if(i==1){
					for(j = 1; j <= b-1; j++){
		      	
		      			printf("\t");
		      				
					}
					printf("    ");
					printf("X");
		         	printf("\n");
				}
				else{
					for(j = 0; j <= (b-i); j++){
		      	
		      			printf("\t");
					}
					printf("X");
					c=c-2;
					for(j = 1; j <= c; j++){
		      	
		      			printf("\t");
					}
					
					printf("X");
					printf("\n");
				}
		      
		   }
		}

		/* ODD RADIOUS*/
		else{ 
			
			c=2; //tab
			b=radious/2; //condition for loop
	
			for(i = 0; i <b+1; i++) { // half of the circle
				for(j = 1; j <= b-i; j++){
      	
      				printf("\t"); 
				}
        
				if(i==0){
					for(j = 1; j <= 1; j++){
						printf("X");
					}
         			printf("\n");
				}
				else{
					printf("X");
					for(j = 1; j <= c; j++){
      	
      					printf("\t");
					}
					c=c+2;
					printf("X");
					printf("\n");
				}
      
   			}
		    c=c-2;
		    for(i = b; i >0; i--) { // the other half of the circle
		   		
				for(j = 0; j <= (b-i); j++){
		      	
		      		printf("\t");
				}
		        
				if(i==1){
					for(j = 1; j <= 1; j++){
						printf("X");
					}
		         	printf("\n");
				}
				else{
					printf("X");
					c=c-2;
					for(j = 1; j <= c; j++){
		      			printf("\t");
					}
					
					printf("X");
					printf("\n");
				}
		      
		   }
			
		}
		printf("\n");
		printf("Name : Circular pokémon\n");
		printf("Size: %.2f\n", body_size);
		printf("Color: %s\n",clr);
		printf("Move: %.2f\n", move_length);
		printf("Attack Power: %d\n", attack_power);

	}



}
