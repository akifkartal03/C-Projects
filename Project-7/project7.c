#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
typedef enum {noone, cap, car}player_type;
typedef enum{start, property, tax, punish}block_type;
typedef struct {
	player_type type;//Holds type of the player.
	int current_block_id; //: Holds player location as block id.
	int owned_block_ids[12]; //Holds property block ids that are owned by the user.(11)
	int account; //Holds amount of the current money of the player.
	int turn_to_wait; //Holds number of turns to wait if the player got a punishment.
	char * name; //Holds the name of the player.
}player;
typedef struct{
	int block_id;//: Holds id of the block.
	char * name;//: Holds text of the block that is shown on the top of the block.
	int price;//: If the block is property, holds the price of property.
	int rent; //: Holds the default rent of a property (no house).
	int rent_1; //: Holds the rent of a property with one house.
	int rent_2;//: Holds the rent of a property with two houses.
	int rent_3; //: Holds the rent of a property with three houses.
	int house_price;//: Holds price of building a house on the block.
	int house_count; // Holds the number of the houses on the block that are already built.
	player owner ;// Holds the owner of the block.
	block_type type; // Holds type of the block.
}block;
/*prototypes of functions*/
void init_the_board(block board[20]);
void show_board(block board[20],player player_one,player player_two);
void show_properties(block board[20]);
void buy_property(block* current_block, player* current_player);
void sell_property(block board[20],player* current_player);
void gameplay(block board[20], player player_one,player player_two);
/*my helper functions*/
void init_the_players(player* a_player,player_type type);
void buy_house(block* current_block,player* current_player,int count);
int roll_dice();
int show_my_properties(block board[20],player current_player,int flag);
player current_playerr(player player_one, player player_two,player current_player); 
int find_digit(int number);

int main(){
	block board[20];
	player player_one,player_two;
	gameplay(board,player_one,player_two);// call the game play
	return 0;
}
void init_the_board(block board[20]){
	/*initilaze the board(filling it)*/
	int i;
	for (i = 0; i < 20; ++i)
	{
		board[i].block_id=i;
		board[i].house_count=0;
		board[i].owner.type=noone;
	}
	board[0].name="Start";board[1].name="Esenyurt";board[2].name="Car Park";board[3].name="Tuzla";board[4].name="Arnavutkoy";
	board[5].name="Wait";board[6].name="Catalca";board[7].name="Beykoz";board[8].name="Car Fix";board[9].name="Maltepe";
	board[10].name="Bills";board[11].name="Sisli";board[12].name="Oil";board[13].name="Atasehir";board[14].name="Sariyer";
	board[15].name="Wait";board[16].name="Kadikoy";board[17].name="Besiktas";board[18].name="Vocation";board[19].name="Bebek";
	board[0].price=0;board[1].price=16000;board[2].price=0;board[3].price=16500;board[4].price=17000;board[5].price=0;
	board[6].price=20000;board[7].price=23000;board[8].price=0;board[9].price=30000;board[10].price=0;board[11].price=33000;
	board[12].price=0;board[13].price=35000;board[14].price=40000;board[15].price=0;board[16].price=43000;board[17].price=60000;
	board[18].price=0;board[19].price=70000;board[0].rent=0;board[1].rent=800;board[2].rent=1500;board[3].rent=850;board[4].rent=875;
	board[5].rent=2;board[6].rent=1000;board[7].rent=1100;board[8].rent=1750;board[9].rent=1350;board[10].rent=2000;board[11].rent=1500;
	board[12].rent=2250;board[13].rent=1600;board[14].rent=1750;board[15].rent=1;board[16].rent=1900;board[17].rent=2500;board[18].rent=5000;
	board[19].rent=3500;board[0].rent_1=0;board[1].rent_1=4000;board[2].rent_1=0;board[3].rent_1=4250;board[4].rent_1=4500;board[5].rent_1=0;
	board[6].rent_1=5000;board[7].rent_1=5500;board[8].rent_1=0;board[9].rent_1=7000;board[10].rent_1=0;board[11].rent_1=8000;board[12].rent_1=0;
	board[13].rent_1=8500;board[14].rent_1=9500;board[15].rent_1=0;board[16].rent_1=11000;board[17].rent_1=15000;board[18].rent_1=0;
	board[19].rent_1=20000;board[0].rent_2=0;board[1].rent_2=9000;board[2].rent_2=0;board[3].rent_2=9500;board[4].rent_2=10000;board[5].rent_2=0;
	board[6].rent_2=12000;board[7].rent_2=12500;board[8].rent_2=0;board[9].rent_2=15000;board[10].rent_2=0;board[11].rent_2=16000;board[12].rent_2=0;
	board[13].rent_2=17000;board[14].rent_2=19000;board[15].rent_2=0;board[16].rent_2=21500;board[17].rent_2=28000;board[18].rent_2=0;board[19].rent_2=35500;
	board[0].rent_3=0;board[1].rent_3=25000;board[2].rent_3=0;board[3].rent_3=26000;board[4].rent_3=28000;board[5].rent_3=0;board[6].rent_3=30000;
	board[7].rent_3=33000;board[8].rent_3=0;board[9].rent_3=40000;board[10].rent_3=0;board[11].rent_3=42000;board[12].rent_3=0;board[13].rent_3=45000;
	board[14].rent_3=48000;board[15].rent_3=0;board[16].rent_3=55000;board[17].rent_3=60000;board[18].rent_3=0;board[19].rent_3=65000;board[0].house_price=0;
	board[1].house_price=10000;board[2].house_price=0;board[3].house_price=12000;board[4].house_price=12000;board[5].house_price=0;board[6].house_price=13000;
	board[7].house_price=13000;board[8].house_price=0;board[9].house_price=15000;board[10].house_price=0;board[11].house_price=16000;board[12].house_price=0;
	board[13].house_price=17000;board[14].house_price=19000;board[15].house_price=0;board[16].house_price=23000;board[17].house_price=30000;
	board[18].house_price=0;board[19].house_price=35000;board[0].type=start;board[1].type=property;board[2].type=tax;board[3].type=property;
	board[4].type=property;board[5].type=punish;board[6].type=property;board[7].type=property;board[8].type=tax;board[9].type=property;board[10].type=tax;
	board[11].type=property;board[12].type=tax;board[13].type=property;board[14].type=property;board[15].type=punish;board[16].type=property;
	board[17].type=property;board[18].type=tax;board[19].type=property;
}
void show_board(block board[20],player player_one,player player_two){
	char space[10][10]={""," ", "  ", "   ", "    ","     ","      ","       ","        ","         "};// in order to fix spaces
	int r,c,flag=0,a=0,b=0,initial,final,i;
	int k=21;// my all space in one line
	int arr[6]; //in order keep values
	for( i = 0; i < 6*(k+1)+1; i++) printf("-");
	printf("\n");
 	for (r=0;r<6;r++) {
 		
 		if (r==0) //first row
 		{
 			for (i = 0; i < 6; ++i) arr[i]=i;
 			final=6; //number of all members in this row
 		}
 		if (r==1) //second row
 		{
 			for( i = 0; i < 6*(k+1)+1; i++) printf("-");
			printf("\n");
 			arr[0]=19; //one member
 			arr[1]=6; //another member
 			final=2; //number of all members in this row
 		}
 		if (r==2) //third row
 		{
 			for( i = 0; i < k+2; i++) printf("-");
 			for (i = 0; i < (4*k)+3; ++i)
 			{
 				printf(" "); // this row contains some space 
 			}
			for( i = 0; i < k+2; i++) printf("-");
 			printf("\n");
 			arr[0]=18;
 			arr[1]=7;
 			final=2;
 		}
 		if (r==3) //forth row
 		{
 			for( i = 0; i < k+2; i++) printf("-");
 			for (i = 0; i < (4*k)+3; ++i)
 			{
 				printf(" "); // this row contains some space
 			}
			for( i = 0; i < k+2; i++) printf("-");
 			printf("\n");
 			arr[0]=17;
 			arr[1]=8;
 			final=2;
 		}
 		if (r==4) //fifth row
 		{
 			for( i = 0; i < k+2; i++) printf("-");
 			for (i = 0; i < (4*k)+3; ++i)
 			{
 				printf(" "); // this row contains some space
 			}
			for( i = 0; i < k+2; i++) printf("-");
 			printf("\n");
 			arr[0]=16;
 			arr[1]=9;
 			final=2;
 		}
 		if (r==5) //sixth row(last row)
 		{
 			for( i = 0; i < 6*(k+1)+1; i++) printf("-");
			printf("\n");
 			for (i = 0; i < 6; ++i) arr[i]=15-i;
 			final=6; //number of all members in this row
 		}
		for (c=0;c<final;c++) { //this is for first line(name of block)
			if (final==2 && c==1) //if there are just two element in this row it means there should be some spaces
			{
				printf("|");
				for (i = 0; i < (4*k)+3; ++i)
	 			{
	 				printf(" "); //add space
	 			}
			}
			if (board[arr[c]].type==punish){
				b=k-strlen("Wait   turn");
				if (b%2==0) printf("|%sWait %d turn%s",space[b/2],board[arr[c]].rent,space[b/2]); //balance the space
				else printf("|%sWait %d turn%s",space[b/2],board[arr[c]].rent,space[(b/2)+1]);
				
			} 
			if (board[arr[c]].type!=punish){
				b=k-strlen(board[arr[c]].name);//subtract lenght of word from all space in one line 
				if (b%2==0) printf("|%s%s%s",space[b/2],board[arr[c]].name,space[b/2]); //balance the space
				else printf("|%s%s%s",space[b/2],board[arr[c]].name,space[(b/2)+1]);
			}
		}
		printf("|\n");
		for (c=0;c<final;c++) { //this is for second line(price of the block)
			if (final==2 && c==1)
			{	
				printf("|");
				for (i = 0; i < (4*k)+3; ++i)
	 			{
	 				printf(" ");
	 			}
			}
			if (board[arr[c]].type==property)
			{
				b=k-(find_digit(board[arr[c]].price)+1); //price have ... digit and $
				if (b%2==0) printf("|%s%d$%s",space[b/2],board[arr[c]].price,space[b/2]);
				else printf("|%s%d$%s",space[b/2],board[arr[c]].price,space[(b/2)+1]);
			}
			else if(board[arr[c]].type==tax){
				
				b=k-(find_digit(board[arr[c]].rent)+1); // rent have ... digit and $
				if (b%2==0) printf("|%s%d$%s",space[b/2],board[arr[c]].rent,space[b/2]);
				else printf("|%s%d$%s",space[b/2],board[arr[c]].rent,space[(b/2)+1]);
			}
			else{ // no price
				printf("|");
				for( i = 0; i < k; i++) printf(" ");
			} 
				
		}
		printf("|\n");
		for (c=0;c<final;c++) { //this is for last line(users that are on the block)
			if (final==2 && c==1)
			{
				printf("|");
				for (i = 0; i < (4*k)+3; ++i)
	 			{
	 				printf(" ");
	 			}
			}
			if (board[arr[c]].block_id==player_one.current_block_id  && board[arr[c]].block_id==player_two.current_block_id)
			{
			
				b=k-9;// 9 means strlen(car---cap)
				printf("|%s%s---%s%s",space[b/2],player_one.name,player_two.name,space[b/2]);
			}
			else if (board[arr[c]].block_id==player_one.current_block_id)
			{
				
				b=k-3;//car
				printf("|%s%s%s",space[b/2],player_one.name,space[b/2]);
			}
			else if (board[arr[c]].block_id==player_two.current_block_id)
			{
				
				b=k-3;//cap
				printf("|%s%s%s",space[b/2],player_two.name,space[b/2]);
			}
			else{ //no gamer
				printf("|");
				for( i = 0; i < k; i++) printf(" ");
			} 
		}
		printf("|\n");
	}
	for( i = 0; i < 6*(k+1)+1; i++) printf("-");
	printf("\n");
 	
}
void show_properties(block board[20]){
	int i,choice,k=33,b;
	char space[10][10]={""," ", "  ", "   ", "    ","     ","      ","       ","        ","         "};//for balance space
	do{
		printf("Please select a property to see details:\n");//list the properties
		for (i=0; i < 19; ++i)
		{
			if (board[i].type==property)
			{
				printf("%d-\t%s\n", board[i].block_id,board[i].name);
			}
		}
		printf("0-\tExit\n");
		printf("Choice: ");
		scanf("%d",&choice);
		while(board[choice].type==tax || !(choice>=0 && choice<20)){ //check the number

			printf("Please a Valid number: ");
			scanf("%d",&choice);
		}
		if(choice!=0){ 
			//this is for name(print name)
			for( i = 0; i < k; i++) printf("-");
 			printf("\n");
			b=k-(strlen(board[choice].name)+16);
			if (b%2==0) printf("|\t%s%s%s\t|\n",space[b/2],board[choice].name,space[b/2]);
			else printf("|\t%s%s%s\t|\n",space[b/2],board[choice].name,space[(b/2)+1]);
			for( i = 0; i < k; i++) printf("-");
 			printf("\n");
			//this is for rent(print rent)
			b=k-(strlen("Rent    ")+18+find_digit(board[choice].rent));
			printf("|\t%s\t%d$%s|\n","Rent    ",board[choice].rent,space[b]);
			//this is for Rent 1 H (print Rent 1 H)
			b=k-(strlen("Rent 1 H")+18+find_digit(board[choice].rent_1));
			printf("|\t%s\t%d$%s|\n","Rent 1 H",board[choice].rent_1,space[b]);
			//this is for Rent 2 H (print Rent 2 H)
			b=k-(strlen("Rent 2 H")+18+find_digit(board[choice].rent_2));
			printf("|\t%s\t%d$%s|\n","Rent 2 H",board[choice].rent_2,space[b]);
			//this is for Rent 3 H (print Rent 3 H)
			b=k-(strlen("Rent 3 H")+18+find_digit(board[choice].rent_3));
			printf("|\t%s\t%d$%s|\n","Rent 3 H",board[choice].rent_3,space[b]);
			for( i = 0; i < k; i++) printf("-");
 			printf("\n");
			//this is for House Price (print House price)
			b=k-(strlen("House Price")+15+find_digit(board[choice].house_price));
			printf("|\t%s\t%d$%s|\n","House Price",board[choice].house_price,space[b]);
			for( i = 0; i < k; i++) printf("-");
 			printf("\n");
		}
		
	}while(choice!=0); //unless enter 0
	
	
}
void buy_property(block* current_block, player* current_player){
	int answer;
	int i;
	/*Check all cases*/
	if (current_block->type!=property) printf("\e[10;31;47m***Here is not a property, therefore you can not buy this field!***\e[0m\n");
	else if (current_block->owner.type==current_player->type) printf("\e[10;31;47m***You have already this property!***\e[0m\n");
	else if (current_block->owner.type!=noone) printf("\e[10;31;47m***This block bought already other gamer!***\e[0m\n");
	else{
		if (current_player->account < current_block->price) //check money
		{
			printf("\e[10;31;47m***Your money is not enough!***\e[0m\n");	
		}
		else{
			/*update the values*/
			for (i = 0; current_player->owned_block_ids[i]!=-1; ++i);
			current_player->owned_block_ids[i]=current_block->block_id; 
			current_block->owner.type=current_player->type;
			current_player->account=current_player->account-current_block->price;
			printf("***You bought this property***\n");
			/*ask for house*/
			if (current_player->account>=current_block->house_price) { //check money for house
				do{
					printf("***** Gamer %s *****\n",current_player->name);
					printf("-Do you want to buy house ?\n");
					printf("1-Yes\n");
					printf("0-No(Pass to Turn)\n");
					printf("Please Select an Option to continue: ");
					scanf("%d",&answer);
				}while(answer!=0 && answer!=1);//check answer
				if (answer==1)
				{
					buy_house(current_block,current_player,3);//call buy house function with max 3 house
				}
			}
			else{
				printf("\e[10;31;47m***Your money is not enough for buy a house!***\e[0m\n");
			}
		}
	}

}
void buy_house(block* current_block,player* current_player,int count){
	int house_count,answer;
	/*check all cases*/
	if (current_block->type!=property) printf("\e[10;31;47m***Here is not a property, therefore you can not buy a house!***\e[0m\n");
	else if (current_block->owner.type!=current_player->type && current_block->owner.type!=noone) printf("\e[10;31;47m***This property belongs other gamer you can not buy a house!***\e[0m\n");
	else if (current_block->owner.type==noone) printf("\e[10;31;47m***This property doesn't belongs to you!***\e[0m\n");
	else if(current_block->owner.type!=noone && current_block->owner.type==current_player->type )
	{
		house_count=current_player->account/current_block->house_price; //indicate how many houses can he/she take
		if (house_count<=0) // if 0
		{
			printf("\e[10;31;47m***Your money is not enough!***\e[0m\n");	
		}
		else 
		{
			if (count==3) //max 3 house
			{
				if (house_count>3) house_count=3;
				printf("***You can buy %d houses***\n",house_count); //ask
				printf("How many do you want to buy: ");
				scanf("%d",&answer);
				while(answer<1 || answer>house_count){ // check answer
					printf("Please enter between 1 and %d : ",house_count);
					scanf("%d",&answer); 
				}
			}
			else answer=1; //if count==1 then he/she can buy just 1 house
			/*update values*/
			current_block->house_count=current_block->house_count+answer; 
			current_player->account=current_player->account-current_block->house_price*answer;
			printf("***You bought %d houses***\n",answer);
		}
	}
	
}
void sell_property(block board[20],player* current_player){
	int flag,i,answer=0,condt=0,exite=0,indis,id,house_count;
	double half_price,sum,half_house;
	flag=show_my_properties(board,*current_player,0); //show the properties that his/her own
	while(answer!=-2 && flag!=0){ // not exit and there is a properties
		printf("Enter ID of property which want to sell for exit -2: ");
		scanf("%d",&answer);
		condt=0;
		do{
			for (i = 0; i<12; ++i){
				if (current_player->owned_block_ids[i]==answer)
				{
					condt=1;
					indis=current_player->owned_block_ids[i];
					id=i;
				}
				
			}
			if (condt==0 && answer!=-2) //check the answer
			{
				printf("Please Enter correctly!: ");
				scanf("%d",&answer);
			}

		}while(condt==0 && answer!=-2);  
		if (answer!=-2)
		{
			/*update values and give the price(half) to user*/
			half_price=(double)board[indis].price/2.0;
			sum=board[indis].house_count*board[indis].house_price;
			half_house=sum/2.0;
			current_player->account=current_player->account+half_price+half_house;
			current_player->owned_block_ids[id]=-1;
			board[indis].type=noone;
			flag=show_my_properties(board,*current_player,0);
		}

	}
		
}
void gameplay(block board[20], player player_one, player player_two){
	int win=0,choice,dice,i,indis,order=2,result,rent,check=0,penalty=0,answer;
	player current_player;//temp player
	block current_block; // temp block
	init_the_players(&player_one,car);
	init_the_players(&player_two,cap);
	init_the_board(board);
	current_block=board[0]; //initialize the current block
	show_board(board,player_one,player_two);
	current_player=player_one;//initialize the current player
	do{
		
		printf("***** Gamer %s *****\n",current_player.name);
		printf("1-Roll the Dice\n");
		printf("2-Show my Account\n");
		printf("3-Show my Properties\n");
		printf("4-Show property deeds\n");
		printf("5-Buy Property\n");
		printf("6-Buy House\n");
		printf("7-Sell Property\n");
		printf("Please Select an Option to continue: ");
		scanf("%d",&choice);
		while((choice<1) || (choice>7)){ //check the choice
				
			printf("This is an invalid choice. Try again!\n");
			printf("Please Select an Option to continue: ");
			scanf("%d",&choice);
		}
		if (choice==1) //if roll the dice 
		{
			
			dice=roll_dice(); //roll the dice
			current_player.current_block_id=current_player.current_block_id+dice;// move the current player
			if (current_player.current_block_id>19) // if current player pass the start block
			{
				/*update the values*/
				current_player.current_block_id=current_player.current_block_id%20;
				current_player.account=current_player.account+10000;// add 10000$
				printf("\e[10;31;47m***%s got 1000$***\e[0m\n",current_player.name);
			}
			current_block=board[current_player.current_block_id];//indicate the current block
			/*show the board according to current player*/
			if (current_player.type==player_one.type) show_board(board,current_player,player_two);
			else show_board(board,player_one,current_player);
			if (current_block.type==punish && current_player.turn_to_wait <= 0) //if player comes punish block
			{
				current_player.turn_to_wait=current_block.rent+1; // update the turn the wait
				check=1;//change the check
				printf("\e[10;31;47m***%s got punished...***\e[0m\n",current_player.name);
			}
			else if (current_block.type==tax)//tax
			{
				while(current_player.account<current_block.rent && win==0){ // gamer don't have enough money for tax
					printf("\e[10;31;47m***%s don't have enough money for tax!***\e[0m\n",current_player.name);
					printf("\e[10;31;47m***You should sell something!***\e[0m\n");
					result=show_my_properties(board,current_player,1);
					if (result==0) //gamer have no any properties
					{
						printf("\e[10;31;47m***Sorry you gets bankrupt and lose the game***\e[0m\n\n");
						win=1;

					}
					else{
						sell_property(board,&current_player);
					}
				}
				current_player.account=current_player.account-current_block.rent;
				printf("\e[10;31;47m***%s gave the tax to the bank***\e[0m\n",current_player.name);
				
				
			}
			else if (current_block.type==property) //property
			{
				if (current_block.owner.type==noone)//unowned property
				{
					if (current_player.account>=current_block.price)//gamer have enough money
					{
						do{
						
							printf("***** Gamer %s *****\n",current_player.name);
							printf("-Do you want to buy this Property ?\n");
							printf("1-Yes\n");
							printf("0-No(Pass to Turn)\n");
							printf("Please Select an Option to continue: ");
							scanf("%d",&answer);
						}while(answer!=0 && answer!=1);//check answer
						if (answer==1)
						{
							buy_property(&current_block,&current_player);//call the buy function
						}	
					}
					else{
						printf("\e[10;31;47m***%s your money is not enough for buy this property!***\e[0m\n",current_player.name);
					}
					
				}
				else if (current_block.owner.type!=current_player.type) // property belongs to other gamer
				{
					/*indicate the rent for property*/
					if (current_block.house_count==0) rent=current_block.rent;
					else if (current_block.house_count==1) rent=current_block.rent_1;
					else if (current_block.house_count==2) rent=current_block.rent_2;
					else if (current_block.house_count>=3) rent=current_block.rent_3;
					while(current_player.account<rent && win==0){ //gamer have no enough money for rent
						printf("\e[10;31;47m***%s don't have enough money for rent!***\e[0m\n",current_player.name);
						printf("\e[10;31;47m***You should sell something!***\e[0m\n");
						result=show_my_properties(board,current_player,1);
						if (result==0) // gamer have no any properties
						{
							printf("\e[10;31;47m***Sorry you gets bankrupt and lose the game***\e[0m\n\n");
							win=1;

						}
						else{ //gamer have property
							sell_property(board,&current_player); // call the sell function
						}
					}
					current_player.account=current_player.account-rent; //take the rent
					printf("\e[10;31;47m***%s gave the rent to the other gamer***\e[0m\n",current_player.name);
					
				}
				else{ //property belongs to current_player
					if (current_player.account>=current_block.house_price){ //gamer have enough money for buy a house
						do{
							printf("***** Gamer %s *****\n",current_player.name);
							printf("-Do you want to buy a house ?\n");
							printf("1-Yes\n");
							printf("0-No(Pass to Turn)\n");
							printf("Please Select an Option to continue: ");
							scanf("%d",&answer);
						}while(answer!=0 && answer!=1); //check the answer
						if (answer==1)
						{
							buy_house(&current_block,&current_player,1); //call the buy fuction
						}
					}
					
				}
				
			}
			else{//start block

				printf("\e[10;31;47m***%s are in the start block...***\e[0m\n",current_player.name);
			}
			if (check==0 && penalty>0)
			{
				
				penalty=penalty-1; // decrease the temp turn_to_wait
				
			}
		}
		
		else{
			if (win==0)
			{
				switch(choice){
				case 2: //show account of gamer
					printf("\e[10;31;47m***%s your Account***\e[0m\n",current_player.name);
					printf("%d$\n",current_player.account);
					break;
				case 3:
					show_my_properties(board,current_player,0);
					break;
				case 4:
					show_properties(board);
					break;
				case 5:
					buy_property(&current_block,&current_player);
					break;
				case 6:
					buy_house(&current_block,&current_player,1);
					break;
				case 7:
					sell_property(board,&current_player);
					break;
				default :
					printf("Invalid value\n");
				}
			}
		}
		/*Update the orijinal gamers*/
		if (current_player.type==player_one.type)
		{
			player_one=current_player;
		}
		else{
			player_two=current_player;
		}
		/*update the board*/
		board[current_block.block_id]=current_block;
		if (choice==1) {
			/*Change the gamers according to punish*/
			if (current_player.turn_to_wait>0 && check==1) //if current player enter punish block
			{
				penalty=current_player.turn_to_wait;//temp turn_to_wait
				current_player = current_playerr(player_one, player_two,current_player);//change the player
				check=0;//update the check
						
			}
			else if (penalty<=0) //if turn_to wait==0
			{
				current_player = current_playerr(player_one, player_two,current_player);//change players
				current_player.turn_to_wait=0; //update orijinal turn to wait
			}
		}
		current_block=board[current_player.current_block_id];
		
		
	}while(win==0);
	/*if loop is end then give a message for winner*/
	printf("\e[10;31;47m***Gamer %s win the game****\e[0m\n\n", current_player.name);
	
}
int roll_dice(){
	srand(time(0));
	int dice;
	dice=(rand()%(6 +1- 1)) + 1; // create a random number
	return dice;
}
void init_the_players(player *a_player,player_type type){
	/*initiliaze the players*/
	int i;
	a_player->current_block_id=0;
	a_player->type=type;
	for (i = 0; i < 12; ++i)
	{
		a_player->owned_block_ids[i]=-1;
	}
	a_player->account=100000; //at the start
	a_player->turn_to_wait=0;
	if (type==cap) a_player->name="Cap";
	else if (type==car) a_player->name="Car";
}
int show_my_properties(block board[20],player current_player,int flag){
	int i,k=0,id;
	for (i = 0; i < 12; ++i) //how many have the current player
	{
		if (current_player.owned_block_ids[i]!=-1){
			k++;
		}
	}
	if (flag==1){ //just return don't give any message.
		return k;
	}
	else{ // give message
		if (k==0)
		{

			printf("\e[10;31;47m***%s don't have any Properties***!\e[0m\n",current_player.name);
		}
		else{
			printf("\e[10;31;47m***%s your Properties***\e[0m\n",current_player.name);
			for (i = 0; i<12; ++i)
			{
				if (current_player.owned_block_ids[i]!=-1)
				{
					id=current_player.owned_block_ids[i];
					printf("%d- %s\n",current_player.owned_block_ids[i],board[id].name);
					if (board[current_player.owned_block_ids[i]].house_count>0)
					{
						
						printf(" -There are %d houses on %s\n",board[current_player.owned_block_ids[i]].house_count,board[id].name);
					}
					
				}
						
			}
		}
		return k;
	}
	
	
}
player current_playerr(player player_one, player player_two,player current_player){
	/*indicate the current player*/
	if(current_player.type==player_one.type){

		return player_two;
	}
	else return player_one;
}
int find_digit(int number){
	int i=0;
	while(number!=0){

		number=number/10;
		i++;
	}
	return i;
}




