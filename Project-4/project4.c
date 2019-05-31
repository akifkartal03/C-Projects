#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define size 10
#define user 4
#define up 8 
#define right 6
#define down 2
#define left 4
typedef enum {quadratic,linear}attack_type;
typedef enum {Charmander,Pikachu,Squirtle,Bulbasaur, Pidgeotto,Ratata,Mug,Caterpie,Zubat,Krabby,defaultt=-2}pokemon;
/*prototypes of the functions*/
void menu(); // my auxiliary function
void fill_all_arrays(int range[], attack_type type[],int attack_power[], int stamina[],pokemon Pokemons[]);// my auxiliary function
int str_comp(char dest[1][11],char source[10][11]); // my auxiliary function
void pokedex(char Pokemon_name[10][11], int range[], attack_type type[],int attack_power[], int stamina[]);
void oaks_laboratory(char Pokemon_name[10][11], pokemon Pokemons[],pokemon *my_Pokemons);
void show_Pokemons(char Pokemon_name[10][11], pokemon Pokemons[],int pokemon_count);
void catch_a_pokemon(char Pokemon_name[10][11], pokemon Pokemons[],pokemon *my_pocket);
void release_a_pokemon(char Pokemon_name[10][11], pokemon Pokemons[],pokemon *my_pocket);
void battle(char Pokemon_name[10][11], int range[], attack_type type[], int attack_power[], int stamina[], pokemon user_Pokemons[]);
void show_area (char Pokemon_name[10][11],int area[8][8],int pokemon_staminas_view[8][8]);
int main(){

	menu();

}
void menu(){
	int i;
	int choice;
	char Pokemon_name[10][11]={"Charmander","Pikachu","Squirtle","Bulbasaur", "Pidgeotto","Ratata","Mug","Caterpie","Zubat","Krabby"};// initialize the array
	int range[size], attack_power[size],stamina[size];
	attack_type type[size];
	pokemon Pokemons[size];
	pokemon my_Pokemons[user];
	pokemon user_Pokemons[user];
	for (i = 0; i < user; ++i) my_Pokemons[i]=defaultt;
	fill_all_arrays(range,type, attack_power,stamina,Pokemons); // fill all arrays
	do{
		printf("\n");
		printf("***** WELCOME -Please select an option to continue- *****\n");
		printf("1) Open Pokedex\n");
		printf("2) Go to Oak’s Laboratory\n");
		printf("3) Enter the tournament\n");
		printf("4) Exit\n");
		printf("Choice: ");
		scanf("%d",&choice);
		while((choice<1) || (choice>4)){
			
			printf("This is an invalid choice. Try again!\n");
			printf("Choice:");
			scanf("%d",&choice);
			 
		}
		switch(choice){
		case 1:
		
			pokedex(Pokemon_name, range,  type,attack_power,  stamina);
			break;

		case 2:
			oaks_laboratory(Pokemon_name, Pokemons,my_Pokemons);
			break;

		case 3:
			battle(Pokemon_name, range,  type,  attack_power,  stamina,Pokemons);
			break;

		case 4:
			// this part is in the while's condition which is below
			break;

		default :

			printf("invalid value\n");
		}


	}while(choice!=4); // if the user entry 4 then the loop is end otherwise it will contiune.	
	


}
void fill_all_arrays( int range[], attack_type type[],int attack_power[], int stamina[],pokemon Pokemons[]){

	/*Fill all array manually*/
	range[0]=1;range[1]=3;range[2]=4;range[3]=3;range[4]=2;range[5]=2;range[6]=1;range[7]=2;range[8]=3;range[9]=2;
	type[0]=quadratic;type[1]=linear;type[2]=linear;type[3]=linear;type[4]=quadratic;type[5]=linear;type[6]=quadratic;type[7]=quadratic;type[8]=linear;type[9]=linear;
	attack_power[0]=500;attack_power[1]=350;attack_power[2]=300;attack_power[3]=400;attack_power[4]=250;attack_power[5]=250;attack_power[6]=350;attack_power[7]=200;attack_power[8]=350;attack_power[9]=300;
	stamina[0]=2200;stamina[1]=1500;stamina[2]=1700;stamina[3]=2500;stamina[4]=1900;stamina[5]=2500;stamina[6]=3000;stamina[7]=1200;stamina[8]=1250;stamina[9]=2600;
	Pokemons[0]=Charmander;Pokemons[1]=Pikachu;Pokemons[2]=Squirtle;Pokemons[3]=Bulbasaur;
	Pokemons[4]=Pidgeotto;Pokemons[5]=Ratata;Pokemons[6]=Mug;Pokemons[7]=Caterpie;Pokemons[8]=Zubat;Pokemons[9]=Krabby;

}
void pokedex(char Pokemon_name[10][11], int range[], attack_type type[],int attack_power[], int stamina[]){
	int i,flag=0;
	char name[1][11]; // in order to keep user's entery
	printf("Please type name of the Pokémon (type exit to close Pokedex): ");
	scanf("%s",name[0]);
	flag=str_comp(name,Pokemon_name);
	if (flag==-1) // if name is not found 
	{
		printf("\n***Pokemon was not found***\n");
	}
	else{ // if find the name 

		printf("Name : %s\n", Pokemon_name[flag]);
		if (type[flag]==linear) printf("A. Type : linear\n"); // check enum type then print
		else printf("A. Type : quadratic\n"); // check enum type then print
		printf("Range : %d\n", range[flag]);
		printf("A. Power : %d\n", attack_power[flag]);
		printf("Stamina : %d\n", stamina[flag]);
	}

}
void oaks_laboratory(char Pokemon_name[10][11], pokemon Pokemons[],pokemon *my_Pokemons){

	int choice;
	int pokemon_count=10;
	do{
		printf("\n");
		printf("***** Welcome to Laboratory of Professor Oak. How can I help you? *****\n");
		printf("1) Show Pokémons\n");
		printf("2) Catch a Pokémon\n");
		printf("3) Release a Pokémon\n");
		printf("4) Show my pocket\n");
		printf("5) Back\n");
		printf("Choice: ");
		scanf("%d",&choice);
		while((choice<1) || (choice>5)){
			
			printf("This is an invalid choice. Try again!\n");
			printf("Choice:");
			scanf("%d",&choice);
			 
		}
		switch(choice){
		case 1:
			pokemon_count=10;
			printf("\n");
			show_Pokemons(Pokemon_name, Pokemons, pokemon_count);
			break;

		case 2:
			
			catch_a_pokemon(Pokemon_name, Pokemons,my_Pokemons);
			break;

		case 3:
			release_a_pokemon(Pokemon_name, Pokemons,my_Pokemons);
			break;

		case 4:
			pokemon_count--;
			printf("\n***Your Pokemons***\n");
			show_Pokemons(Pokemon_name, Pokemons, pokemon_count);
			break;
		case 5:
			// this part is in the while's condition which is below
			break;

		default :

			printf("invalid value\n");
		}


	}while(choice!=5); // if the user entry 5 then the loop is end otherwise it will contiune.	

}
void show_Pokemons(char Pokemon_name[10][11], pokemon Pokemons[],int pokemon_count){
	int i;
	if (pokemon_count==10) // if there are all pokemons
	{
		for (i = 0; i < size; ++i)
		{
			if (Pokemons[i]==defaultt); // don't do anything
			else printf("%d - %s\n",i,Pokemon_name[i]);
				
		}	
	}
	else{

		for (i = 0; i < size; ++i)
		{
			if (Pokemons[i]==defaultt)  printf("%d - %s\n",i,Pokemon_name[i]);
				
		}	

	}
	
}
void catch_a_pokemon(char Pokemon_name[10][11], pokemon Pokemons[],pokemon *my_pocket){
	int i,j,flag=0,flag2=0,pokemon_count=10,choice;
	int numbers2[user]={-1,-1,-1,-1};
	for (i = 0; i < size; ++i)
	{
		if (Pokemons[i]==defaultt) // it means the user did choose that pokemon
		{
			numbers2[flag2]=i;
			flag2++;
		}

	}
	do{
			
		if (flag2==4) // it means there are four element in the pocket
		{
			printf("\n**You can not choice more than four pokemon**\n");
			break;
		}
		else{
			printf("***Pokemons***\n");
			show_Pokemons(Pokemon_name, Pokemons, pokemon_count);
			printf("\nPlease Enter Pokemons which want to Catch\n");
			printf("Choice %d: ",flag+1);
			scanf("%d",&choice);
			for (j= 0; j<4; ++j)
			{
				while((choice==numbers2[j]) || !(choice>=0 && choice<10)) // if the pokemon chosen before or number is invalid
				{
					printf("This is an invalid choice. Try again!\n");
					printf("Choice:");
					scanf("%d",&choice);
				}
							
			}
			numbers2[flag2]=choice;
			*(my_pocket+flag)=Pokemons[choice];
			Pokemons[choice]=defaultt;
			flag2++;
			flag++;
		}
		
	}while(flag2<4); // the user can only select four different Pokémons
}
void release_a_pokemon(char Pokemon_name[10][11], pokemon Pokemons[],pokemon *my_pocket){
	int flag=0,flag2=0,i, pokemon_count=4, choice,numbers[4];
	for (i = 0; i < user; ++i)
	{
		
		if (*(my_pocket+i)==defaultt) flag++;
		else numbers[i]= *(my_pocket+i);

	}
	pokemon_count=pokemon_count-flag;
	if (flag==4) // it means there is no pokemon in the pocket
	{
		printf("\n***Please Catch Pokemons***\n");
	}
	else{
		do{
			printf("***Your Pokemons***\n");
			show_Pokemons(Pokemon_name, Pokemons, pokemon_count);
			printf("\nPlease Enter Pokemons which want to delete also For exit enter -1\n");
			printf("Choice %d: ",flag+1);
			scanf("%d",&choice);
			while(choice!=numbers[0]&&choice!=numbers[1]&&choice!=numbers[2]&&choice!=numbers[3]&&choice!=-1){ //if choice is not a valid number
				
				printf("This is an invalid choice. Try again!\n");
				printf("Choice:");
				scanf("%d",&choice);
				 
			}
			/*in order to delete replace with default*/
			if (choice==0) {
				Pokemons[choice]=Charmander;
				for (i = 0; i < user; ++i) if (*(my_pocket+i)==Charmander) *(my_pocket+i)=defaultt;
				
			}
			else if (choice==1){

				for (i = 0; i < user; ++i) if (*(my_pocket+i)==Pikachu) *(my_pocket+i)=defaultt;
				Pokemons[choice]=Pikachu;
			} 	
			else if (choice==2){

				for (i = 0; i < user; ++i) if (*(my_pocket+i)==Squirtle) *(my_pocket+i)=defaultt;
				Pokemons[choice]=Squirtle;
			}  	
			else if (choice==3){

				for (i = 0; i < user; ++i) if (*(my_pocket+i)==Bulbasaur) *(my_pocket+i)=defaultt;
				Pokemons[choice]= Bulbasaur;
			}  	
			else if (choice==4){

				for (i = 0; i < user; ++i) if (*(my_pocket+i)==Pidgeotto) *(my_pocket+i)=defaultt;
				Pokemons[choice]=Pidgeotto;
			}  
			else if (choice==5){

				for (i = 0; i < user; ++i) if (*(my_pocket+i)==Ratata) *(my_pocket+i)=defaultt;
				Pokemons[choice]=Ratata;
			}  
			else if (choice==6){

				for (i = 0; i < user; ++i) if (*(my_pocket+i)==Mug) *(my_pocket+i)=defaultt;
				Pokemons[choice]=Mug;
			}  	
			else if (choice==7){

				for (i = 0; i < user; ++i) if (*(my_pocket+i)==Caterpie) *(my_pocket+i)=defaultt;
				Pokemons[choice]=Caterpie;
			}  	
			else if (choice==8){

				for (i = 0; i < user; ++i) if (*(my_pocket+i)==Zubat) *(my_pocket+i)=defaultt;
				Pokemons[choice]=Zubat;
			}  	
			else if (choice==9){

				for (i = 0; i < user; ++i) if (*(my_pocket+i)==Krabby) *(my_pocket+i)=defaultt;
				Pokemons[choice]=Krabby;
			}  	
			flag2++;
			if (flag2 > 3) break; // the user can only select four different Pokémons
		}while(choice!=-1); 
		
	}

}
void battle(char Pokemon_name[10][11], int range[], attack_type type[], int attack_power[], int stamina[], pokemon user_Pokemons[]){
	srand(time(0));
	int flag=0,row,column,a=0,k=0,userr=0,choice,distance,attack,winai=0,winuser=0,queue=0;
	int area[8][8],s=0,n=0,m=0,c=1,i,j,l,z,flag2=0,f=1;
	int pokemon_staminas[8][8],oyuncu[user],ai=-1,aii[user];
	pokemon mypok[user];
	
	for (i = 0; i < size; ++i) //specify my pokemons
	{
		if (user_Pokemons[i]==defaultt)
		{
			oyuncu[a]=i;
			a++;
		}
	}
	for (i = 0; i < 8; ++i){ // initiliaze the arrays
		for (j = 0; j <8; ++j){
			area[i][j]=-1;
			pokemon_staminas[i][j]=-1;
		}
	}   
	if (a<4) printf("\n**Please Before Catch four Pokemon**\n"); // in order to start war user should catch four pokemon
	else{

		for (i = 0; i < user; ++i) // locate user's pokemon randomly to the arena
		{
			
			row=(rand()%(1 +1- 0)) + 0;// create a random number between given range(1 and 0) because first row
			column=(rand()%(7 +1- 0)) + 0;  //column
			while(area[row][column]!=-1){ // if there is a pokemon in this place

				row=(rand()%(1 +1- 0)) + 0;   // then again create a number
				column=(rand()%(7 +1- 0)) + 0;
			}
			area[row][column]=oyuncu[i]; //fill this region
			pokemon_staminas[row][column]=stamina[oyuncu[i]]; // fill this stamina
		}
		for (i = 0; i < user; ++i) // choosing AI's pokemons and locate them randomly
		{
			
			aii[i]=(rand()%(9 +1- 0)) + 0; //choose a pokemon
			for (j= 0; j<i; ++j)
			{
				while(aii[i]==aii[j]) // if the pokemon choose before then
				{
					aii[i]=(rand()%(9 +1- 0)) + 0; // again choose
				}
						
			}
			row=(rand()%(7 +1-6)) + 6; //range(6 and 7) because last row
			column=(rand()%(7 +1- 0)) + 0; 
			while(area[row][column]!=-1){ // if there is pokemon in this place

				row=(rand()%(7 +1- 6)) + 6;   // then again create a number
				column=(rand()%(7 +1- 0)) + 0;
			}
			pokemon_staminas[row][column]=stamina[aii[i]]; //stamina
			area[row][column]=aii[i]+20; // fill this region (cause of +20 indicate ai's pokemon than user's pokemon)
			
		}
		printf("\n***Welcome The Battle a Guide for Pokemon Tournament****\n");
		printf("1) Firstly, Pokemons which belongs to either user or AI located in the battle area randomly. \n");
		printf("2) The Pokemons which have '*' character belongs to AI. \n");
		printf("3) In order to locate your Pokemon Enter required numbers correctly.\n");
		printf("4) After The user a move then AI move its pokemon randomly. \n");
		printf("5) You can't leave the game before the game is over. \n");
		printf("\t\t***GOOD LUCK :)****\n");
		while(1){ // start the battle if there is winner then end the battle
			k=0;
			flag2=0;
			if (queue%2==0) // user can move
			{
				printf("***User is locating his/her pokemon...***\n");
				show_area ( Pokemon_name, area,pokemon_staminas);
				printf("In order to choose a pokemon Please Enter it's Row(0-7): " );
				scanf("%d",&row);
				while(!(row>=0 && row<8)){ // if row is invalid number

					printf("Please Enter a valid Row(0-7): " );
					scanf("%d",&row);
				}
				printf("In order to choose a pokemon Please Enter it's Column(0-7): ");
				scanf("%d",&column);
				while(!(column>=0 && column<8)){ // if column is invalid number

					printf("Please Enter a valid Column(0-7): " );
					scanf("%d",&column);
				}
				while(area[row][column]==-1 ){ // if there no pokemon in this place

					printf("There is no pokemon in this place Please Enter again :\n" );
					printf("Please Enter a valid Row(0-7): " );
					scanf("%d",&row);
					printf("Please Enter a valid Column(0-7): " );
					scanf("%d",&column);
				}
				
				while(area[row][column]>9){ // if the pokemon don't belong to user

					printf("This is not your pokemon Please Enter again :\n" );
					printf("Please Enter a valid Row(0-7): " );
					scanf("%d",&row);
					printf("Please Enter a valid Column(0-7): " );
					scanf("%d",&column);
				}
				printf("In order to move your pokemon Please Enter a number(Up:8,Right:6,Down:2,Left:4) : ");
				scanf("%d",&choice);
				while(choice!=2 && choice!=4 && choice!=6 && choice!=8){ //invalid
					printf("Please Enter a valid number(Up:8,Right:6,Down:2,Left:4) : ");
					scanf("%d",&choice);
				}
				printf("Please Enter a Distance (1 or 2) : ");
				scanf("%d",&distance);
				while(distance!=1 && distance!=2){ //invalid
					printf("Please Enter a valid Distance (1 or 2) : ");
					scanf("%d",&distance);
				}
			}
			else{ // ai can move 
				printf("***AI is locating his/her pokemon...***\n");
				ai=(rand()%(9 +1- 0)) + 0; // in order to choose a pokemon create a random number between 0 and 9 
				while((aii[c-1]%20)!=ai){ // if the pokemon which chosen is not equal to one of the ai's pokemon 

					if (c%4==0) // check all ai's pokemon
					{
						ai=(rand()%(9 +1- 0)) + 0; // then create again
						c=0;
					}
					c++;
				}
				for (i = 0; i < 8; ++i)
				{
					for (j = 0; j < 8; ++j)
					{
						if (area[i][j]==ai+20) // find the cohosen pokemon's location
						{
							row=i; // and save them
							column=j;
							break;
						}
					}
				}
				choice=(rand()%(8 +1- 2)) + 2;
				while(choice!=2 && choice!=4 && choice!=6 && choice!=8){ // invalid
					choice=(rand()%(8 +1- 2)) + 2;
				}
				distance=(rand()%(2 +1- 1)) + 1;
				while(distance!=1 && distance!=2){ //invalid
					distance=(rand()%(2 +1- 1)) + 1;
				}
			}
			flag2=0;
			switch(choice){
			case up:
				if (distance==1)
				{
					if (row==0 || area[row-1][column]!=-1){
						printf("You Can not move in this direction\n");
						queue--; // in order to play again
						flag2=1; // in order to keep the status
					}
					else{
						k=area[row][column];
						area[row][column]=-1;
						pokemon_staminas[row][column]=-1;
						row--;
						area[row][column]=k;
						z=k%20; // because we did +20 for ai
						pokemon_staminas[row][column]=stamina[z];
					}
				}
				else if (distance==2)
				{
					if (row==0 || row==1 || area[row-2][column]!=-1) {
						printf("You Can not move in this direction\n");
						queue--;
						flag2=1;
					}
					else{
						k=area[row][column];
						area[row][column]=-1;
						pokemon_staminas[row][column]=-1;
						row=row-2;
						area[row][column]=k;
						z=k%20;
						pokemon_staminas[row][column]=stamina[z];
					}
				}
				else {
					printf("Please Enter a distance  0 and 1\n");
					break;
				}
				break;
			case right:
				if (distance==1)
				{
					if (column==7 || area[row][column+1]!=-1) {
						printf("You Can not move in this direction\n");
						queue--;
						flag2=1;
					}
					else{
						k=area[row][column];
						area[row][column]=-1;
						pokemon_staminas[row][column]=-1;
						column++;
						area[row][column]=k;
						z=k%20;
						pokemon_staminas[row][column]=stamina[z];
					}
				}
				else if (distance==2)
				{
					if (column==6 || column==7 || area[row][column+2]!=-1){
						printf("You Can not move in this direction\n");
						queue--;
						flag2=1;
					}
					else{
						k=area[row][column];
						area[row][column]=-1;
						pokemon_staminas[row][column]=-1;
						column=column+2;
						area[row][column]=k;
						z=k%20;
						pokemon_staminas[row][column]=stamina[z];
					}
				}
				else {
					printf("Please Enter a distance  0 and 1\n");
					break;
				}
				break;
			case down:
				if (distance==1)
				{
					if (row==7 || area[row+1][column]!=-1){
						printf("You Can not move in this direction\n");
						queue--;
						flag2=1;
					}
					else{
						k=area[row][column];
						area[row][column]=-1;
						pokemon_staminas[row][column]=-1;
						row++;
						area[row][column]=k;
						z=k%20;
						pokemon_staminas[row][column]=stamina[z];
					}
				}
				else if (distance==2)
				{
					if (row==6 || row==7 || area[row+2][column]!=-1){
						printf("You Can not move in this direction\n");
						queue--;
						flag2=1;
					} 	
					else{
						k=area[row][column];
						area[row][column]=-1;
						pokemon_staminas[row][column]=-1;
						row=row+2;
						area[row][column]=k;
						z=k%20;
						pokemon_staminas[row][column]=stamina[z];
					}
				}
				else {
					printf("Please Enter a distance  0 and 1\n");
					break;
				}
				break;
			case left:
				if (distance==1)
				{
					if (column==0 || area[row][column-1]!=-1){
						printf("You Can not move in this direction\n");
						queue--;
						flag2=1;
					}
					else{
						k=area[row][column];
						area[row][column]=-1;
						pokemon_staminas[row][column]=-1;
						column--;
						area[row][column]=k;
						z=k%20;
						pokemon_staminas[row][column]=stamina[z];
					}
				}
				else if (distance==2)
				{
					if (column==1 || column==0 || area[row][column-2]!=-1){
						printf("You Can not move in this direction\n");
						queue--;
						flag2=1;
						
					} 
					else{
						k=area[row][column];
						area[row][column]=-1;
						pokemon_staminas[row][column]=-1;
						column=column-2;
						area[row][column]=k;
						z=k%20;
						pokemon_staminas[row][column]=stamina[z];
					}
				}
				else {
					printf("Please Enter a distance  0 and 1\n");
					break;
				}
				break;
			default:
				printf("In order to move your pokemon Please Enter a number(Up:8,Right:6,Down:2,Left:4) : ");
			}
			if(flag2==0){ // if the move is happen
				z=k%20; // because we did +20 for ai
				attack=range[z];// which attack range
				s=0;
				for (i = 1; i <=attack; ++i) // in order to find Pokémon that is the closest to attacker (in attack range)
				{
						
					//south
					if (row+i<8)
					{
						if (queue%2!=0)// if the sequence is artificial intelligence
						{	
							if (area[row+i][column]!=-1 && area[row+i][column]<10 ){ // if the pokemon belong to user
								stamina[area[row+i][column]]=stamina[area[row+i][column]]-attack_power[z];//stamina decrases
								pokemon_staminas[row+i][column]=pokemon_staminas[row+i][column]-attack_power[z]; //stamina decrases
								if (pokemon_staminas[row+i][column]<=0)
								{
									area[row+i][column]=-1;
									pokemon_staminas[row+i][column]=-1;
									oyuncu[n]=-1;
									n++;
								}
								if (type[z]!=quadratic) s++;// in order to attack just the closest pokemon
							}
								
						}
						else{ // if the sequence is user
							if (area[row+i][column]!=-1 && area[row+i][column]>9){
								l= area[row+i][column]%20;
								stamina[l]=stamina[l]-attack_power[z];
								pokemon_staminas[row+i][column]=pokemon_staminas[row+i][column]-attack_power[z];
								if (pokemon_staminas[row+i][column]<=0)
								{
									area[row+i][column]=-1;
									pokemon_staminas[row+i][column]=-1;
									aii[m]=-1;
									m++;
								}
								if (type[z]!=quadratic) s++; 
							}
		
	
						}
					}
					//north
					if (row-i>=0)
					{
						if (queue%2!=0)  // if the sequence is artificial intelligence
						{
							if (area[row-i][column]!=-1 && area[row-i][column]<10){
								stamina[area[row-i][column]]=stamina[area[row-i][column]]-attack_power[z];
								pokemon_staminas[row-i][column]=pokemon_staminas[row-i][column]-attack_power[z];
								if (pokemon_staminas[row-i][column]<=0)
								{
									area[row-i][column]=-1;
									pokemon_staminas[row-i][column]=-1;
									oyuncu[n]=-1;
									n++;
								}
								if (type[z]!=quadratic) s++;
							}
						}
						else{ // if the sequence is user
							if (area[row-i][column]!=-1 && area[row-i][column]>9){ 
								l= area[row-i][column]%20;
								stamina[l]=stamina[l]-attack_power[z];
								pokemon_staminas[row-i][column]=pokemon_staminas[row-i][column]-attack_power[z];
								if (pokemon_staminas[row-i][column]<=0)
								{
									area[row-i][column]=-1;
									pokemon_staminas[row-i][column]=-1;
									aii[m]=-1;
									m++;
								}
								if (type[z]!=quadratic) s++;
							}
								
	
						}
					}
						
					//right
					if (column+i<8)
					{
						if (queue%2!=0) // if the sequence is artificial intelligence
						{
							if (area[row][column+i]!=-1 && area[row][column+i]<10){ 
								stamina[area[row][column+i]]=stamina[area[row][column+i]]-attack_power[z];
								pokemon_staminas[row][column+i]=pokemon_staminas[row][column+i]-attack_power[z];
								if (pokemon_staminas[row][column+i]<=0)
								{
									area[row][column+i]=-1;
									pokemon_staminas[row][column+i]=-1;
									oyuncu[n]=-1;
									n++;
								}
								if (type[z]!=quadratic) s++;
							}
								
						}
						else{ // if the sequence is user
							if (area[row][column+i]!=-1 && area[row][column+i]>9){ 
								l= area[row][column+i]%20;
								stamina[l]=stamina[l]-attack_power[z];
								pokemon_staminas[row][column+i]=pokemon_staminas[row][column+i]-attack_power[z];
								if (pokemon_staminas[row][column+i]<=0)
								{
									area[row][column+i]=-1;
									pokemon_staminas[row][column+i]=-1;
									aii[m]=-1;
									m++;
								}
								if (type[z]!=quadratic) s++;
							}
						}
					}
						
					//left
					if (column-i>=0)
					{
						if (queue%2!=0)
						{
							if (area[row][column-i]!=-1 && area[row][column-i]<10){ 
								stamina[area[row][column-i]]=stamina[area[row][column-i]]-attack_power[z];
								pokemon_staminas[row][column-i]=pokemon_staminas[row][column-i]-attack_power[z];
								if (pokemon_staminas[row][column-i]<=0)
								{
									area[row][column-i]=-1;
									pokemon_staminas[row][column-i]=-1;
									oyuncu[n]=-1;
									n++;
								}
								if (type[z]!=quadratic) s++;
							}
								
						}
						else{ // if the sequence is user
							if (area[row][column-i]!=-1 && area[row][column-i]>9){ 
								l= area[row][column-i]%20;
								stamina[l]=stamina[l]-attack_power[z];
								pokemon_staminas[row][column-i]=pokemon_staminas[row][column-i]-attack_power[z];
								if (pokemon_staminas[row][column-i]<=0)
								{
									area[row][column-i]=-1;
									pokemon_staminas[row][column-i]=-1;
									aii[m]=-1;
									m++;
								}
								if (type[z]!=quadratic) s++;
							}						
	
						}
					}
						
					if (s>0 && type[z]==linear) break; //if there is a Pokémon that is the closest to attacker then finish(break)
					if (type[z]==quadratic)
					{
						// these are in order to check diagonal
						//southeast
						if (row+i<8 && column+i<8) 
						{
							if (queue%2!=0 ) // if the sequence is artificial intelligence
							{
								if (area[row+i][column+i]!=-1 && area[row+i][column+i]<10){ 
									stamina[area[row+i][column+i]]=stamina[area[row+i][column+i]]-attack_power[z];
									pokemon_staminas[row+i][column+i]=pokemon_staminas[row+i][column+i]-attack_power[z];
									if (pokemon_staminas[row+i][column+i]<=0)
									{
										area[row+i][column+i]=-1;
										pokemon_staminas[row+i][column+i]=-1;
										oyuncu[n]=-1;
										n++;
									}
								}
								
							}
							else{ // if the sequence is user
								if (area[row+i][column+i]!=-1 && area[row+i][column+i]>9){ 
									l= area[row+i][column+i]%20;
									stamina[l]=stamina[l]-attack_power[z];
									pokemon_staminas[row+i][column+i]=pokemon_staminas[row+i][column+i]-attack_power[z];
									if (pokemon_staminas[row+i][column+i]<=0)
									{
										area[row+i][column+i]=-1;
										pokemon_staminas[row+i][column+i]=-1;
										aii[m]=-1;
										m++;
									}
								}
								
							}
						}
						//southwest
						if (row+i<8 && column-i>=0)
						{
							
							if ( queue%2!=0) // if the sequence is artificial intelligence
							{
								if (area[row+i][column-i]!=-1 && area[row+i][column-i]<10){ 
									stamina[area[row+i][column-i]]=stamina[area[row+i][column-i]]-attack_power[z];	
									pokemon_staminas[row+i][column-i]=pokemon_staminas[row+i][column-i]-attack_power[z];
									if (pokemon_staminas[row+i][column-i]<=0)
									{
										area[row+i][column-i]=-1;
										pokemon_staminas[row+i][column-i]=-1;
										oyuncu[n]=-1;
										n++;
									}
								}
				
							}
							else{ // if the sequence is user
								if (area[row+i][column-i]!=-1 && area[row+i][column-i]>9){ 
								l= area[row+i][column-i]%20;
								stamina[l]=stamina[l]-attack_power[z];
								pokemon_staminas[row+i][column-i]=pokemon_staminas[row+i][column-i]-attack_power[z];
									if (pokemon_staminas[row+i][column-i]<=0)
									{
										area[row+i][column-i]=-1;
										pokemon_staminas[row+i][column-i]=-1;
										aii[m]=-1;
										m++;
									}
								}
								
							}
						}
						//northwest
						if (row-i>=0 && column-i>=0 )
						{
							if (queue%2!=0 ) // if the sequence is artificial intelligence
							{
								if (area[row-i][column-i]!=-1 && area[row-i][column-i]<10){ 
									stamina[area[row-i][column-i]]=stamina[area[row-i][column-i]]-attack_power[z];
									pokemon_staminas[row-i][column-i]=pokemon_staminas[row-i][column-i]-attack_power[z];
									if (pokemon_staminas[row-i][column-i]<=0)
									{
										area[row-i][column-i]=-1;
										pokemon_staminas[row-i][column-i]=-1;
										oyuncu[n]=-1;
										n++;
									}
								}
								
										
							}
							else{ // if the sequence is user
								if (area[row-i][column-i]!=-1 && area[row-i][column-i]>9){ 
									l= area[row-i][column-i]%20;
									stamina[l]=stamina[l]-attack_power[z];
									pokemon_staminas[row-i][column-i]=pokemon_staminas[row-i][column-i]-attack_power[z];
									if (pokemon_staminas[row-i][column-i]<=0)
									{
										area[row-i][column-i]=-1;
										pokemon_staminas[row-i][column-i]=-1;
										aii[m]=-1;
										m++;
									}
								}
								
							}
						}
						//northeast	
						if (row-i>=0 && column+i<8)
						{
							
							if (queue%2!=0) // if the sequence is artificial intelligence
							{
								if (area[row-i][column+i]!=-1 && area[row-i][column+i]<10){ 
									stamina[area[row-i][column+i]]=stamina[area[row-i][column+i]]-attack_power[z];
									pokemon_staminas[row-i][column+i]=pokemon_staminas[row-i][column+i]-attack_power[z];
									if (pokemon_staminas[row-i][column+i]<=0)
									{
										area[row-i][column+i]=-1;
										pokemon_staminas[row-i][column+i]=-1;
										oyuncu[n]=-1;
										n++;
									}
								}
	
								
										
							}
							else { // if the sequence is user
								if (area[row-i][column+i]!=-1 && area[row-i][column+i]>9){ 
									l= area[row-i][column+i]%20;
									stamina[l]=stamina[l]-attack_power[z];
									pokemon_staminas[row-i][column+i]=pokemon_staminas[row-i][column+i]-attack_power[z];
									if (pokemon_staminas[row-i][column+i]<=0)
									{
										area[row-i][column+i]=-1;
										pokemon_staminas[row-i][column+i]=-1;
										aii[m]=-1;
										m++;
									}
								}
								
							}			
						}		
	
					}
				}
		
			}
			queue++;
			winai=0;
			winuser=0;
			for (i = 0; i < user; ++i)
			{
				if (aii[i]==-1)
				{
					winuser++;
				}
				if (oyuncu[i]==-1)
				{
					winai++;
				}
			}
			
			if (winuser==4)
			{
				printf("\n***User win the game***\n");
				break; //end the game
			}
			if (winai==4)
			{
				printf("\n***AI win the game***\n");
				break; // end the game
			}
			

		}

	}
	
}
void show_area (char Pokemon_name[10][11],int area[8][8],int pokemon_staminas_view[8][8]){
	int r,c,flag=0,a=0,b=0;
 	for (r=0;r<8;r++) {
 		printf("---------------------------------------------------------\n");
		for (c=0;c<8;c++) {
			if (area[r][c]==-1) //there is no pokemon
			{
				printf("|      ");
			}
			else{
				if(area[r][c]>9){ // if the pokemons belongs to AI print with '*'
					a=area[r][c]-20;
					printf("| *%c%c  ",Pokemon_name[a][0],Pokemon_name[a][1]);
				}
				else{
					a=area[r][c]; //if the pokemons belongs to user
					printf("|  %c%c  ",Pokemon_name[a][0],Pokemon_name[a][1]);
				}
				
			}
			
		}
		printf("|\n");
		for (c=0;c<8;c++) {
			if (pokemon_staminas_view[r][c]==-1) //there is no pokemon
			{
				printf("|      ");
			}
			else{
				/*these are in order to print the shape correctly*/
				if (pokemon_staminas_view[r][c]>=1000) printf("|(%d)",pokemon_staminas_view[r][c]);
				else if (pokemon_staminas_view[r][c]>=100 && pokemon_staminas_view[r][c]<1000) printf("|(%d) ",pokemon_staminas_view[r][c]);
				else if (pokemon_staminas_view[r][c]>=10 && pokemon_staminas_view[r][c]<100) printf(" |(%d) ",pokemon_staminas_view[r][c]);
				if (pokemon_staminas_view[r][c]<10) printf("| (%d)  ",pokemon_staminas_view[r][c]);
				
			}
			
		}
		
		printf("|\n");
	}
	printf("---------------------------------------------------------\n");
}
int str_comp(char dest[1][11],char source[10][11]){ // my string_compare function
	int i,j,flag=1;
	for(i=0;i<10;i++){
		flag=1;
		for(j=0;source[i][j]!='\0';j++){
			
			
			if(dest[0][j]!=source[i][j])
			{
				flag=-1;
			}
			
		}
		if(flag!=-1){ // if the words match 
			flag=i;
			break;
		}
	}
	return flag;	
}
