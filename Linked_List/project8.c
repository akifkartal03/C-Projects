#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
/*This is my code not the solition*/
typedef enum {noone, cap, car}player_type;
typedef enum{start, property, tax, punish,fortune}block_type;
typedef enum{user,computer,fortune_c}check_type;
typedef struct{
	player_type type;//Holds type of the player.
	int current_block_id; //: Holds player location as block id.
	int owned_block_ids[12]; //Holds property block ids that are owned by the user.(11)
	int account; //Holds amount of the current money of the player.
	int turn_to_wait; //Holds number of turns to wait if the player got a punishment.
	char * name;//Holds the name of the player.
	//struct node_p *prev;  
}player;
typedef struct node_b{
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
	block_type type;// Holds type of the block.
	struct node_b *next; //linked list node
	 
}block;
typedef struct{
	int no; //Holds id of card.
	char * name;//Holds the name of the card.
	int current_block; //holds current block id
}fortune_card;
/*prototypes of functions*/
void init_the_board(block *board);
void show_board(block *board,player player_one,player player_two);
void show_properties(block *board);
void buy_property(block* current_block, player* current_player);
void sell_property(block *board,player* current_player);
void gameplay(block *board, player player_one,player player_two);
/*my helper functions*/
void init_the_players(player* a_player,player_type type);
void buy_house(block* current_block,player* current_player,int count);
int roll_dice(int flag);
int show_my_properties(block *board,player current_player,int flag);
player current_playerr(player player_one, player player_two,player current_player); 
int find_digit(int number);
void init_the_cards(fortune_card *card,int no);
int checking_blocks(block *board,block *current_block,player *current_player,int *check,int *penalty,player *player_one,player *player_two,int *win,check_type type);
void indicate_fortune(block *board,block *current_block,player *current_player,player *player_one,player *player_two,int *check,int *penalty,int *win);

int main(){
	player player_one,player_two;
	int i;
	block *head;
	block *iter;
	iter=(block*)malloc(sizeof(block));
	head=iter;
	/*create an empty linked list*/
	for( i = 0; i < 24; i++)
	{
		if (i!=23)
		{
			iter->next=(block*)malloc(sizeof(block));
			iter=iter->next;
		}
		else
		{
			iter->next=NULL;
		}
	}
	init_the_board(head);//initialize the linked list(fill it)
	gameplay(head,player_one,player_two); //call the function
	return 0;
}
void init_the_board(block *board){
	/*initilaze the board(filling it)*/
	int i;
	block *iter2;
	iter2=board;
	/*fill the linked list*/
	for(i = 0; i < 24; i++)
	{
		iter2->house_count=0;
		iter2->owner.type=noone;
		switch (i)
		{
		case 0:
			iter2->block_id=0;
			iter2->name="Start";
			iter2->price=0;
			iter2->rent=0;
			iter2->rent_1=0;
			iter2->rent_2=0;
			iter2->rent_3=0;
			iter2->house_price=0;
			iter2->type=start;	
			break;
		case 1:
			iter2->type=property;
			iter2->block_id=1;
			iter2->name="Esenyurt";
			iter2->price=16000;
			iter2->rent=800;
			iter2->rent_1=4000;
			iter2->rent_2=9000;
			iter2->rent_3=25000;
			iter2->house_price=10000;
			break;
		case 2:
			iter2->type=tax;
			iter2->name="Car park";
			iter2->block_id=2;
			iter2->price=0;
			iter2->rent=1500;
			iter2->rent_1=0;
			iter2->rent_2=0;
			iter2->rent_3=0;
			iter2->house_price=0;	
			break;
		case 3:
			iter2->type=fortune;
			iter2->name="Fortune Card";
			iter2->block_id=3;
			iter2->price=0;
			iter2->rent=0;
			iter2->rent_1=0;
			iter2->rent_2=0;
			iter2->rent_3=0;
			iter2->house_price=0;		
			break;
		case 4:
			iter2->type=property;
			iter2->block_id=4;
			iter2->name="Tuzla";
			iter2->price=16500;
			iter2->rent=850;
			iter2->rent_1=4250;
			iter2->rent_2=9500;
			iter2->rent_3=26000;
			iter2->house_price=12000;	
			break;
		case 5:
			iter2->type=property;
			iter2->block_id=5;
			iter2->name="Arnavutkoy";
			iter2->price=17000;
			iter2->rent=850;
			iter2->rent_1=4500;
			iter2->rent_2=10000;
			iter2->rent_3=28000;
			iter2->house_price=12000;
			break;
		case 6:
			//name will come later according to rent
			iter2->type=punish;
			iter2->price=0;
			iter2->block_id=6;
			iter2->rent=2;
			iter2->rent_1=0;
			iter2->rent_2=0;
			iter2->rent_3=0;
			iter2->house_price=0;	
			break;
		case 7:
			iter2->type=property;
			iter2->block_id=7;
			iter2->name="Catalca";
			iter2->price=20000;
			iter2->rent=1000;
			iter2->rent_1=5000;
			iter2->rent_2=12000;
			iter2->rent_3=30000;
			iter2->house_price=13000;
			break;
		case 8:
			iter2->type=property;
			iter2->block_id=8;
			iter2->name="Beykoz";
			iter2->price=23000;
			iter2->rent=1100;
			iter2->rent_1=5500;
			iter2->rent_2=12500;
			iter2->rent_3=33000;
			iter2->house_price=13000;
			break;
		case 9:
			iter2->type=fortune;
			iter2->name="Fortune Card";
			iter2->block_id=9;
			iter2->price=0;
			iter2->rent=0;
			iter2->rent_1=0;
			iter2->rent_2=0;
			iter2->rent_3=0;
			iter2->house_price=0;	
			break;
		case 10:
			iter2->name="Car fix";
			iter2->block_id=10;
			iter2->price=0;
			iter2->rent=1750;
			iter2->rent_1=0;
			iter2->rent_2=0;
			iter2->rent_3=0;
			iter2->house_price=0;
			iter2->type=tax;	
			break;
		case 11:
			iter2->type=property;
			iter2->block_id=11;
			iter2->name="Maltepe";
			iter2->price=30000;
			iter2->rent=1350;
			iter2->rent_1=7000;
			iter2->rent_2=15000;
			iter2->rent_3=40000;
			iter2->house_price=15000;	
			break;
		case 12:
			iter2->name="Bills";
			iter2->block_id=12;
			iter2->price=0;
			iter2->rent=2000;
			iter2->rent_1=0;
			iter2->rent_2=0;
			iter2->rent_3=0;
			iter2->house_price=0;
			iter2->type=tax;	
			break;
		case 13:
			iter2->type=property;
			iter2->block_id=13;
			iter2->name="Sisli";
			iter2->price=33000;
			iter2->rent=1500;
			iter2->rent_1=8000;
			iter2->rent_2=16000;
			iter2->rent_3=42000;
			iter2->house_price=16000;	
			break;
		case 14:
			iter2->name="Oil";
			iter2->block_id=14;
			iter2->price=0;
			iter2->rent=2250;
			iter2->rent_1=0;
			iter2->rent_2=0;
			iter2->rent_3=0;
			iter2->house_price=0;
			iter2->type=tax;	
			break;
		case 15:
			iter2->type=fortune;
			iter2->name="Fortune Card";
			iter2->block_id=15;
			iter2->price=0;
			iter2->rent=0;
			iter2->rent_1=0;
			iter2->rent_2=0;
			iter2->rent_3=0;
			iter2->house_price=0;	
			break;
		case 16:
			iter2->type=property;
			iter2->block_id=16;
			iter2->name="Atasehir";
			iter2->price=35000;
			iter2->rent=1600;
			iter2->rent_1=8500;
			iter2->rent_2=17000;
			iter2->rent_3=45000;
			iter2->house_price=17000;	
			break;
		case 17:
			iter2->type=property;
			iter2->block_id=17;
			iter2->name="Sariyer";
			iter2->price=40000;
			iter2->rent=1750;
			iter2->rent_1=9500;
			iter2->rent_2=19000;
			iter2->rent_3=48000;
			iter2->house_price=19000;
			break;
		case 18:
			//name will come later according to rent
			iter2->type=punish;
			iter2->price=0;
			iter2->block_id=18;
			iter2->rent=1;
			iter2->rent_1=0;
			iter2->rent_2=0;
			iter2->rent_3=0;
			iter2->house_price=0;	
			break;
		case 19:
			iter2->type=property;
			iter2->block_id=19;
			iter2->name="Kadikoy";
			iter2->price=43000;
			iter2->rent=1900;
			iter2->rent_1=11000;
			iter2->rent_2=21500;
			iter2->rent_3=55000;
			iter2->house_price=23000;	
			break;
		case 20:
			iter2->type=property;
			iter2->block_id=20;
			iter2->name="Besiktas";
			iter2->price=60000;
			iter2->rent=2500;
			iter2->rent_1=15000;
			iter2->rent_2=28000;
			iter2->rent_3=60000;
			iter2->house_price=30000;	
			break;
		case 21:
			iter2->type=fortune;
			iter2->name="Fortune Card";
			iter2->block_id=21;
			iter2->price=0;
			iter2->rent=0;
			iter2->rent_1=0;
			iter2->rent_2=0;
			iter2->rent_3=0;
			iter2->house_price=0;	
			break;
		case 22:
			iter2->name="Vocation";
			iter2->block_id=22;
			iter2->price=0;	
			iter2->rent=5000;
			iter2->rent_1=0;
			iter2->rent_2=0;
			iter2->rent_3=0;
			iter2->house_price=0;
			iter2->type=tax;
			break;
		case 23:
			iter2->type=property;
			iter2->block_id=23;
			iter2->name="Bebek";
			iter2->price=70000;
			iter2->rent=3500;
			iter2->rent_1=20000;
			iter2->rent_2=35500;
			iter2->rent_3=65000;
			iter2->house_price=35000;
			break;
		
		default:
			printf("Unknown error happened!");
		}
		iter2=iter2->next;
	}
	
	
}
void show_board(block *board,player player_one,player player_two){
	char space[10][10]={""," ", "  ", "   ", "    ","     ","      ","       ","        ","         "};// in order to fix spaces
	int r,c,flag=0,a=0,b=0,initial,final,i,m=18;
	int k=17;// my all space in one line
	block *temp1,*temp2,*temp3,*temp4,*temp5,*temp6;
	block  *iter,*iter2;
	iter=board;
	iter2=board;
	for( i = 0; i < 7*(k+1)+1; i++) printf("-");
	printf("\n");
 	for (r=0;r<7;r++) {
 		
 		if (r==0) //first row
 		{
 			final=7; //number of all members in this row
 		}
 		if (r==1) //second row
 		{
 			for( i = 0; i < 7*(k+1)+1; i++) printf("-");
			printf("\n");
			temp6=iter;
			iter2=board;
			for (i = 0; i < 23; ++i){
				iter2=iter2->next;
				switch (i)
				{
				case 18:
					temp1=iter2; //keep the 19th member	
					break;
				case 19:
					temp2=iter2; //keep the 20th member	
					break;
				case 20:
					temp3=iter2; //keep the 21th member	
					break;
				case 21:
					temp4=iter2; //keep the 22th member	
					break;
				case 22:
					temp5=iter2; //keep the 23th member	
					break;
				default:
					break;
				}
			}
			iter=temp5; // initialize the iter 23th member
 			final=2; //number of all members in this row(23 and 7)
 		}
 		if (r==2) //third row
 		{
 			for( i = 0; i < k+2; i++) printf("-");
 			for (i = 0; i < (5*k)+4; ++i)
 			{
 				printf(" "); // this row contains some space 
 			}
			for( i = 0; i < k+2; i++) printf("-");
 			printf("\n");
			iter=temp4; // initialize the iter 22th member
			temp6=temp6->next; // initialize the temp6 8th member
 			final=2;
 		}
 		if (r==3) //forth row
 		{
 			for( i = 0; i < k+2; i++) printf("-");
 			for (i = 0; i < (5*k)+4; ++i)
 			{
 				printf(" "); // this row contains some space
 			}
			for( i = 0; i < k+2; i++) printf("-");
 			printf("\n");
			iter=temp3; // initialize the iter 21th member
			temp6=temp6->next; // initialize the temp6 9th member
 			final=2;
 		}
 		if (r==4) //fifth row
 		{
 			for( i = 0; i < k+2; i++) printf("-");
 			for (i = 0; i < (5*k)+4; ++i)
 			{
 				printf(" "); // this row contains some space
 			}
			for( i = 0; i < k+2; i++) printf("-");
 			printf("\n");
			iter=temp2; // initialize the iter 20th member
			temp6=temp6->next; // initialize the temp6 10th member
 			final=2;
 		}
		if (r==5) //sixth row
 		{
 			for( i = 0; i < k+2; i++) printf("-");
 			for (i = 0; i < (5*k)+4; ++i)
 			{
 				printf(" "); // this row contains some space
 			}
			for( i = 0; i < k+2; i++) printf("-");
 			printf("\n");
			iter=temp1; // initialize the iter 19th member
			temp6=temp6->next; // initialize the temp6 11th member
 			final=2;
 		}
		if (r==6) //seventh row
 		{
 			for( i = 0; i < 7*(k+1)+1; i++) printf("-");
			printf("\n");
 			final=7; //number of all members in this row
			iter2=board; //// initialize the iter2 firsr member(0)
			
 		}
		for (c=0;c<final;c++) { //this is for first line(name of block)
			if (final==7 && r==6) {
				iter=board;
				for( i = 0; i <m-c; i++) iter=iter->next;
			}
			if (final==2 && c==1) //if there are just two element in this row it means there should be some spaces
			{
				printf("|");
				for (i = 0; i < (5*k)+4; ++i)
	 			{
	 				printf(" "); //add space
	 			}
			}
			if (iter->type==punish){
				b=k-strlen("Wait   turn"); //indicate the space(k means all space in a line)
				if (b%2==0) printf("|%sWait %d turn%s",space[b/2],iter->rent,space[b/2]); //balance the space
				else printf("|%sWait %d turn%s",space[b/2],iter->rent,space[(b/2)+1]);
				
			} 
			if (iter->type!=punish){
				b=k-strlen(iter->name);//subtract lenght of word from all space in one line 
				if (b%2==0) printf("|%s%s%s",space[b/2],iter->name,space[b/2]); //balance the space
				else printf("|%s%s%s",space[b/2],iter->name,space[(b/2)+1]);
			}
			/*update the item of linked list*/
			if (final==7 && r==0) {
				iter2=iter2->next;
				iter=iter2;
			}
			if (final==2 && c==0) {
				iter2=iter;
				iter=temp6;
			}
				
		}
		/*update the item of linked list*/
		if (final==7 && r==0) {
			iter2=board;
			iter=board;	
		}
		if (final==2) {
			iter=iter2;
		}
		printf("|\n");
		for (c=0;c<final;c++) { //this is for second line(price of the block)
			if (final==7 && r==6) {
				iter=board;
				for( i = 0; i <m-c; i++) iter=iter->next; // update the item according to situation
			}
			if (final==2 && c==1)
			{	
				printf("|");
				for (i = 0; i < (5*k)+4; ++i)
	 			{
	 				printf(" "); // add space
	 			}
			}
			if (iter->type==property)
			{
				b=k-(find_digit(iter->price)+1); //price have ... digit and $
				if (b%2==0) printf("|%s%d$%s",space[b/2],iter->price,space[b/2]); //balance the space
				else printf("|%s%d$%s",space[b/2],iter->price,space[(b/2)+1]);
			}
			else if(iter->type==tax){
				
				b=k-(find_digit(iter->rent)+1); // rent have ... digit and $
				if (b%2==0) printf("|%s%d$%s",space[b/2],iter->rent,space[b/2]); // balance the space
				else printf("|%s%d$%s",space[b/2],iter->rent,space[(b/2)+1]);
			}
			else{ // no price
				printf("|");
				for( i = 0; i < k; i++) printf(" "); //just add space
			} 
			/*update the item of linked list*/
			if (final==7 && r==0) {
				iter2=iter2->next;
				iter=iter2;
			}
			if (final==2 && c==0) {
				
				iter=temp6;
			}	
		}
		/*update*/
		if (final==7 && r==0) {
			iter2=board;
			iter=board;	
		}
		if (final==2) {
			iter=iter2;
		}
		printf("|\n");
		for (c=0;c<final;c++) { //this is for last line(users that are on the block)
			if (final==7 && r==6) {
				iter=board;
				for( i = 0; i <m-c; i++) iter=iter->next; //updating linked list
			}
			if (final==2 && c==1)
			{
				printf("|");
				for (i = 0; i < (5*k)+4; ++i)
	 			{
	 				printf(" "); //add space between two block
	 			}
			}
			if (iter->block_id==player_one.current_block_id  && iter->block_id==player_two.current_block_id)
			{
			
				b=k-9;// 9 means strlen(car---cap)
				printf("|%s%s---%s%s",space[b/2],player_one.name,player_two.name,space[b/2]); //balance the space
			}
			else if (iter->block_id==player_one.current_block_id)
			{
				
				b=k-3;//car
				printf("|%s%s%s",space[b/2],player_one.name,space[b/2]);//balance the space
			}
			else if (iter->block_id==player_two.current_block_id)
			{
				
				b=k-3;//cap
				printf("|%s%s%s",space[b/2],player_two.name,space[b/2]);//balance the space
			}
			else{ //no gamer on the blok
				printf("|");
				for( i = 0; i < k; i++) printf(" "); //  just print space
			}
			/*update the values*/ 
			if (final==7 && r==0) {
				iter2=iter2->next;
				iter=iter2;
			}
			if (final==2) {
				iter=temp6;
			}
		}
		printf("|\n");
	}
	for( i = 0; i < 7*(k+1)+1; i++) printf("-");
	printf("\n");
}
void show_properties(block *board){
	int i,choice,k=33,b;
	char space[10][10]={""," ", "  ", "   ", "    ","     ","      ","       ","        ","         "};//for balance space
	block *iter;
	do{
		iter=board;//initialize board
		printf("Please select a property to see details:\n");
		/*list the properties*/
		for (i=0; i < 24; ++i)
		{
			if (iter->type==property)
			{
				printf("%d-\t%s\n", iter->block_id,iter->name);
			}
			iter=iter->next;
		}
		printf("0-\tExit\n");
		printf("Choice: ");
		scanf("%d",&choice);
		iter=board;
		/*find the choosen item*/
		for( i = 0; i < choice; i++)
		{
			iter=iter->next; 
		}
		while(iter->type!=property || !(choice>=0 && choice<24)){ //check the number

			printf("Please a Valid number: ");
			scanf("%d",&choice);
			iter=board;
			for( i = 0; i < choice; i++)
			{
				iter=iter->next;
			}
		}
		if(choice!=0){ 
			//this is for name(print name)
			for( i = 0; i < k; i++) printf("-");
 			printf("\n");
			b=k-(strlen(iter->name)+16);
			if (b%2==0) printf("|\t%s%s%s\t|\n",space[b/2],iter->name,space[b/2]);
			else printf("|\t%s%s%s\t|\n",space[b/2],iter->name,space[(b/2)+1]);
			for( i = 0; i < k; i++) printf("-");
 			printf("\n");
			//this is for rent(print rent)
			b=k-(strlen("Rent    ")+18+find_digit(iter->rent));
			printf("|\t%s\t%d$%s|\n","Rent    ",iter->rent,space[b]);
			//this is for Rent 1 H (print Rent 1 H)
			b=k-(strlen("Rent 1 H")+18+find_digit(iter->rent_1));
			printf("|\t%s\t%d$%s|\n","Rent 1 H",iter->rent_1,space[b]);
			//this is for Rent 2 H (print Rent 2 H)
			b=k-(strlen("Rent 2 H")+18+find_digit(iter->rent_2));
			printf("|\t%s\t%d$%s|\n","Rent 2 H",iter->rent_2,space[b]);
			//this is for Rent 3 H (print Rent 3 H)
			b=k-(strlen("Rent 3 H")+18+find_digit(iter->rent_3));
			printf("|\t%s\t%d$%s|\n","Rent 3 H",iter->rent_3,space[b]);
			for( i = 0; i < k; i++) printf("-");
 			printf("\n");
			//this is for House Price (print House price)
			b=k-(strlen("House Price")+15+find_digit(iter->house_price));
			printf("|\t%s\t%d$%s|\n","House Price",iter->house_price,space[b]);
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
			printf("\e[10;31;47m***%s your money is not enough!***\e[0m\n",current_player->name);	
		}
		else{ //if money is enough
			if (current_player->type==car) { //user
				/*update the values*/
				for (i = 0; current_player->owned_block_ids[i]!=-1; ++i);
				current_player->owned_block_ids[i]=current_block->block_id; 
				current_block->owner.type=current_player->type;
				current_player->account=current_player->account-current_block->price;
				printf("***%s bought this property***\n",current_player->name);
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
					printf("\e[10;31;47m***%s your money is not enough for buy a house!***\e[0m\n",current_player->name);
				}
				
			}
			else //computer
			{
				/*just update the values*/
				for (i = 0; current_player->owned_block_ids[i]!=-1; ++i);
				current_player->owned_block_ids[i]=current_block->block_id; 
				current_block->owner.type=current_player->type;
				current_player->account=current_player->account-current_block->price;
				printf("***Computer bought this property***\n"); //give a message
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
		house_count=current_player->account/current_block->house_price; //indicate how many houses can he/she buy?
		if (house_count<=0) // if 0
		{
			printf("\e[10;31;47m***%s your money is not enough!***\e[0m\n",current_player->name);	
		}
		else 
		{
			if (current_player->type==car) { //user
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
			else//computer
			{
				/*update values*/
				current_block->house_count=current_block->house_count+1; 
				current_player->account=current_player->account-current_block->house_price;
				printf("***Computer bought 1 house***\n");
			}
			
		}
	}
	
}
void sell_property(block *board,player* current_player){
	int flag,i,answer=0,condt=0,exite=0,indis,id,house_count,max=0,j,indis2;
	double half_price,sum,half_house;
	block *iter;
	iter=board;
	if (current_player->type==car) { //user
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
				iter=board;
				for(i = 0; i < indis; i++) iter=iter->next;
				/*update values and give the price(half) to user*/
				half_price=(double)iter->price/2.0;
				sum=iter->house_count*iter->house_price;
				half_house=sum/2.0;
				current_player->account=current_player->account+half_price+half_house;
				current_player->owned_block_ids[id]=-1;
				iter->owner.type=noone;
				flag=show_my_properties(board,*current_player,0);
			}

		}
	}
	else{ // computer
		/*indicate the property that have max price*/
		for (i = 0; i<12; ++i){
			if (current_player->owned_block_ids[i]!=-1)
			{
				indis=current_player->owned_block_ids[i];
				iter=board;
				for( j = 0; j < indis; j++) iter=iter->next;
				if (iter->price>max) {
					max=iter->price;
					id=iter->block_id;
					indis2=i;
				}
				
			}		
		}
		/*update values and give the price(half) to computer*/
		iter=board;
		for(i = 0; i < id; i++) iter=iter->next;
		half_price=((double)iter->price)/2.0;
		sum=iter->house_count*iter->house_price;
		half_house=sum/2.0;
		current_player->account=current_player->account+half_price+half_house;
		current_player->owned_block_ids[indis2]=-1;
		iter->owner.type=noone;
		printf("Computer sold the %s for pay rent.\n",iter->name); //give a message
	}
	
}
void gameplay(block *board, player player_one, player player_two){
	int win=0,choice,dice,i,indis,order=2,result,rent,check=0,penalty=0,answer,dice2,flag=0;
	player current_player;//temp player
	block *current_block; // temp block
	block *iter,*temp1,*temp2,*iter2;
	fortune_card card;
	init_the_players(&player_one,car); //initialize the players
	init_the_players(&player_two,cap);
	current_block=board; //initialize the current block
	iter=board; temp1=board; temp2=board; iter2=board;
	show_board(board,player_one,player_two); //show the board
	current_player=player_one;//initialize the current player
	do{
		if (current_player.type==player_one.type) { //user
			printf("|Car: %d$ | Cap: %d$ |\n",player_one.account,player_two.account);
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
		}
		if ( (choice==1) || (current_player.type==player_two.type)) //if roll the dice 
		{
			flag=0;
			if (current_player.type==player_two.type) { //computer
				flag=checking_blocks(board,current_block,&current_player,&check,&penalty,&player_one,&player_two,&win,computer);
			}
			else //user
			{
				flag=checking_blocks(board,current_block,&current_player,&check,&penalty,&player_one,&player_two,&win,user);
			}
			if(flag==1){ // it means player came to the fortune card block
				/*choose a card by using this function*/
				indicate_fortune(board,current_block,&current_player,&player_one,&player_two,&check,&penalty,&win);
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
					buy_property(current_block,&current_player);
					break;
				case 6:
					buy_house(current_block,&current_player,1);
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
		iter=current_block;
		/*Change the gamers according to punish*/
		if (choice==1) {
			
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
		current_block=iter; 
		
	}while(win==0);
	/*if loop is end then give a message for winner*/
	printf("\e[10;31;47m***Gamer %s win the game****\e[0m\n\n", current_player.name);
}
int roll_dice(int flag){
	srand(time(0));
	int dice;
	if (flag==1) {
		dice=(rand()%(6 +1- 1)) + 1; //create a random number between 1 and 6
	}
	else
	{
		dice=(rand()%(5 +1- 1)) + 1; //create a random number between 1 and 5(for fortune card)
	}
	
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
	a_player->account=100000; //at the begginning
	a_player->turn_to_wait=0;
	if (type==cap) a_player->name="Cap";
	else if (type==car) a_player->name="Car";
}
int show_my_properties(block *board,player current_player,int flag){
	int i,k=0,id,j;
	block *iter;
	iter=board;
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
					iter=board;
					for( j= 0; j < current_player.owned_block_ids[i]; j++) iter=iter->next;
					printf("%d- %s\n",current_player.owned_block_ids[i],iter->name);
					if (iter->house_count>0)
					{
						printf(" -There are %d houses on %s\n",iter->house_count,iter->name);
					}
				}
						
			}
		}
		return k;
	}
}
player current_playerr(player player_one, player player_two,player current_player){
	/*change the current player*/
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
void init_the_cards(fortune_card *card,int no){

	card->no=no;
	switch (no)
	{
	case 1:
		card->name="Free House";	
		break;
	case 2:
		card->name="Time Travel";	
		break;
	case 3:
		card->name="Garnishment";	
		break;
	case 4:
		card->name="Generosity";	
		break;
	case 5:
		card->name="Treasure Hunter";	
		break;		
	default:
		break;
	}
}
int checking_blocks(block *board,block *current_block,player *current_player,int *check,int *penalty,player *player_one,player *player_two,int *win,check_type type){
			int answer,rent,result,dice,i,j,sum=0,dice2,counter=0;
			block *iter,*temp1,*temp2,*iter2;
			iter=board;
			temp1=board;
			temp2=board;
			iter2=board;
			if (type!=fortune_c){
				dice=roll_dice(1); //roll the dice
				current_player->current_block_id=current_player->current_block_id+dice;// move the current player
			}
			if (current_player->current_block_id>23) // if current player pass the start block
			{
				/*update the values*/
				current_player->current_block_id=current_player->current_block_id%24;
				if (current_player->type==player_one->type) {
					temp1=board;
					for(i = 0; i <current_player->current_block_id; i++)
					{
						temp1=temp1->next;
					}
					iter=temp1;
					temp1=board;
				}
				else{
					temp2=board;
					for(i = 0; i <current_player->current_block_id; i++)
					{
						temp2=temp2->next;
					}
					iter=temp2;
					temp2=board;
				}
				current_player->account=current_player->account+10000;// add 10000$
				printf("\e[10;31;47m***%s got 10000$***\e[0m\n",current_player->name);
			}
			else{
				if (current_player->type==player_one->type) {
					for(i = 0; i <current_player->current_block_id; i++)
					{
						temp1=temp1->next;
					}
					iter=temp1;
					temp1=board;
				}
				else{
					for(i = 0; i <current_player->current_block_id; i++)
					{
						temp2=temp2->next;
					}
					iter=temp2;
					temp2=board;
				}
			}
			current_block=iter;//indicate the current block
			/*show the board according to current player*/
			if (current_player->type==player_one->type) show_board(board,*current_player,*player_two);
			else show_board(board,*player_one,*current_player);
			if (type==computer && current_player->type==player_two->type) {
				printf("Computer rolled the dice: %d\n",dice);
			}
			if (current_block->type==punish && current_player->turn_to_wait <= 0) //if player comes punish block
			{
				current_player->turn_to_wait=current_block->rent+1; // update the turn the wait
				*check=1;//change the check
				printf("\e[10;31;47m***%s got punished...***\e[0m\n",current_player->name);
			}
			else if (current_block->type==tax)//tax
			{
				while(current_player->account<current_block->rent && *win==0){ // gamer don't have enough money for tax
					printf("\e[10;31;47m***%s don't have enough money for tax!***\e[0m\n",current_player->name);
					printf("\e[10;31;47m***You should sell something!***\e[0m\n");
					result=show_my_properties(board,*current_player,1);
					if (result==0) //gamer have no any properties
					{
						printf("\e[10;31;47m***Sorry you gets bankrupt and lose the game***\e[0m\n\n");
						*win=1;

					}
					else{
						sell_property(board,current_player);
					}
				}
				current_player->account=current_player->account-current_block->rent;
				if (*win==0) {
					printf("\e[10;31;47m***%s gave the tax to the bank***\e[0m\n",current_player->name);
				}
				
			}
			else if (current_block->type==property) //property
			{
				if (current_block->owner.type==noone)//unowned property
				{
					if (current_player->account>=current_block->price)//gamer have enough money
					{
						if (current_player->type==player_one->type && type==user) {//user
								
							do{
								printf("***** Gamer %s *****\n",current_player->name);
								printf("-Do you want to buy this Property ?\n");
								printf("1-Yes\n");
								printf("0-No(Pass to Turn)\n");
								printf("Please Select an Option to continue: ");
								scanf("%d",&answer);
							}while(answer!=0 && answer!=1);//check answer
							if (answer==1)
							{
								buy_property(current_block,current_player);//call the buy function
							}	
						}
						else //computer
						{
							iter2=board;
							for( i = 0; i < 24; i++)
							{
								sum=sum+iter2->price;
								iter2=iter2->next;
							}
							if (current_block->price < (sum/12)) { // price is below the average cost of all properties 
								buy_property(current_block,current_player); //buy that
							}
							else //otherwise 
							{
								dice2=roll_dice(1); //roll the dice
								if (dice2>=1 && dice2<=3) {
									buy_property(current_block,current_player);//buy it
								}
								else{ // 4 and 6
									printf("Cap skiped the turn...\n");
								}
								
							}
							
						}
						
					}
					else{ //don't enough money
						printf("\e[10;31;47m***%s your money is not enough for buy this property!***\e[0m\n",current_player->name);
					}
					
				}
				else if (current_block->owner.type!=current_player->type) // property belongs to other gamer
				{
					/*indicate the rent for property*/
					if (current_block->house_count==0) rent=current_block->rent;
					else if (current_block->house_count==1) rent=current_block->rent_1;
					else if (current_block->house_count==2) rent=current_block->rent_2;
					else if (current_block->house_count>=3) rent=current_block->rent_3;
					while(current_player->account<rent && *win==0){ //gamer have no enough money for rent
						printf("\e[10;31;47m***%s don't have enough money for rent!***\e[0m\n",current_player->name);
						printf("\e[10;31;47m***You should sell something!***\e[0m\n");
						result=show_my_properties(board,*current_player,1);
						if (result==0) // gamer have no any properties
						{
							printf("\e[10;31;47m***Sorry you gets bankrupt and lose the game***\e[0m\n\n");
							*win=1;

						}
						else{ //gamer have property
							sell_property(board,current_player); // call the sell function
						}
					}
					current_player->account=current_player->account-rent; //take the rent
					/*give the other gamer*/
					if (current_player->type==player_one->type)
					{
						player_two->account=player_two->account+rent;
					}
					else{
						player_one->account=player_one->account+rent;
					}
					if (*win==0) {
						printf("\e[10;31;47m***%s gave the rent to the other gamer***\e[0m\n",current_player->name);
					}
				}
				else{ //property belongs to current_player
					if (current_player->account>=current_block->house_price){ //gamer have enough money for buy a house
						if (current_player->type==player_one->type && type==user) { //user
							do{
								printf("***** Gamer %s *****\n",current_player->name);
								printf("-Do you want to build a house on your property ?\n");
								printf("1-Yes\n");
								printf("0-No(Pass to Turn)\n");
								printf("Please Select an Option to continue: ");
								scanf("%d",&answer);
							}while(answer!=0 && answer!=1); //check the answer
							if (answer==1)
							{
								buy_house(current_block,current_player,1); //call the buy fuction
							}
						}
						else //computer
						{
							iter2=board;
							counter=0;
							for( i = 0; i < 12; i++)
							{
								if (current_player->owned_block_ids[i]!=-1)
								{
									counter++;
								}
							}
							if (counter>=4) { //If the computer owns 1/3 of all the properties
								dice2=roll_dice(1);
								if (dice2>=1 && dice2<=3) {
									buy_house(current_block,current_player,1);
								}
								else{
									printf("Cap skipped the turn...\n");
								}

							}
							else
							{
								printf("Cap skipped the turn...\n");
							}
						
						}
					}
					else{
						printf("%s you don't have enough money to build a house on your property\n",current_player->name);
					}
					
				}
				
			}
			else if(current_block->type==start){ //start block
				printf("\e[10;31;47m***%s is in the start block...***\e[0m\n",current_player->name);
			}
			if (*check==0 && *penalty>0)
			{
				
				*penalty=*penalty-1; // decrease the temp turn_to_wait
				
			}
			if(current_block->type==fortune) {
				return 1; //I will check the fortune above by using this value.
			}
			
			return 0;

}
void indicate_fortune(block *board,block *current_block,player *current_player,player *player_one,player *player_two,int *check,int *penalty,int *win){
	int res,condt,id,dice2,i,indis,result;
	fortune_card card;
	block *iter2;
	iter2=board;
	dice2=roll_dice(2);//roll the dice for choose a card(you randomly pick a fortune card)
	init_the_cards(&card,dice2);
	switch (dice2)
	{
	case 1: //Free House
			printf("%s picked the %s card.\n",current_player->name,card.name);
			res=show_my_properties(board,*current_player,1);
			if (res==0) { //there is no any property to build a house
				printf("But %s don't have any properties so you can't use this chance.\n",current_player->name);
			}
			else //there are some property
			{
				if (current_player->type==player_one->type) { //user
					/*choosing a propert to build a house*/
					show_my_properties(board,*current_player,2);
					printf("In order to build a  free house select a property :");
					scanf("%d",&res);
					condt=0;
					do{
						for (i = 0; i<12; ++i){
							if (current_player->owned_block_ids[i]==res)
							{
								condt=1;
								indis=current_player->owned_block_ids[i];
								id=i;
							}
						}
						if (condt==0) //check the answer
						{
							printf("Please Enter correctly!: ");
							scanf("%d",&res);
						}

					}while(condt==0);  
					iter2=board;
					for(i = 0; i < indis; i++) iter2=iter2->next;
					/*update values */
					iter2->house_count=iter2->house_count+1;
					printf("***%s build a house free***\n",current_player->name);
				}
				else{//computer
					indis=-1;
					for (i = 0; i<12; ++i){
						if (current_player->owned_block_ids[i]!=-1)
						{
							/*when you find a property build on it directly*/				
							indis=current_player->owned_block_ids[i];
							break;
						}
					}
					if (indis!=-1) { // there is a property
						iter2=board;
						for(i = 0; i < indis; i++) iter2=iter2->next;
						/*update value */
						iter2->house_count=iter2->house_count+1;
						printf("***%s build a house free on %s***\n",current_player->name,iter2->name);
					}
					else //there is no any property
					{
						printf("But %s don't have any properties so you can't use this chance.\n",current_player->name);
					}
					
				}
							
			}
		break;
	case 2://travel
		printf("%s picked the %s card.\n",current_player->name,card.name);
		printf("%s is rolling dice.... for moving.\n",current_player->name);
		dice2=roll_dice(1);
		if (dice2>=1 && dice2<=3) { //forward by 2 blocks
			current_player->current_block_id=current_player->current_block_id+2;
			checking_blocks(board,current_block,current_player,check,penalty,player_one,player_two,win,fortune_c);
			printf("%s moved forward by 2 blocks.\n",current_player->name);
		}
		else //backward by 2 blocks
		{
			current_player->current_block_id=current_player->current_block_id-2;
			checking_blocks(board,current_block,current_player,check,penalty,player_one,player_two,win,fortune_c);
			printf("%s moved backward by 2 blocks.\n",current_player->name);
		}	
		break;
	case 3: //Garnishment
		printf("%s picked the %s card.\n",current_player->name,card.name);
		/*check the account for rent*/
		while(current_player->account < 5000 && *win==0){ // gamer don't have enough money for tax
			printf("\e[10;31;47m***%s don't have enough money to paid 5.000$ to the bank!***\e[0m\n",current_player->name);
			printf("\e[10;31;47m***You should sell something!***\e[0m\n");
			result=show_my_properties(board,*current_player,1);
			if (result==0) //gamer have no any properties
			{
				printf("\e[10;31;47m***Sorry you gets bankrupt and lose the game***\e[0m\n\n");
				*win=1;

			}
			else{
				sell_property(board,current_player);
			}
		}
		current_player->account=current_player->account-5000; // take the rent
		printf("So %s paid 5.000$ to the bank.\n",current_player->name);
		break;
	case 4: //Generosity
		printf("%s picked the %s card.\n",current_player->name,card.name);
		/*check the account for rent*/
		while(current_player->account < 10000 && *win==0){ // gamer don't have enough money for tax
			printf("\e[10;31;47m***%s don't have enough money to paid 10.000$ to the opponent!***\e[0m\n",current_player->name);
			printf("\e[10;31;47m***You should sell something!***\e[0m\n");
			result=show_my_properties(board,*current_player,1);
			if (result==0) //gamer have no any properties
			{
				printf("\e[10;31;47m***Sorry you gets bankrupt and lose the game***\e[0m\n\n");
				*win=1;

			}
			else{
				sell_property(board,current_player);
			}
		}
		current_player->account=current_player->account-10000; //take the rent
		/*give the rent other gamer*/
		if (current_player->type==player_one->type)
		{
			player_two->account=player_two->account+10000;
		}
		else{
			player_one->account=player_one->account+10000;
		}
		printf("So %s paid 10.000$ to the opponent.\n",current_player->name);
		break;
	case 5: //Treasure Hunter
		printf("%s picked the %s card.\n",current_player->name,card.name);
		current_player->account=current_player->account+20000;	// add 20000$
		printf("So %s got +20.000$ from the bank.\n",current_player->name);
		break;		
	default:
		break;
	}

}



