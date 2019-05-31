#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DICT_SIZE 15
#define WORD_LEN 10
#define LINE_LEN 18
typedef enum{north,south,west,east,northwest,northeast,southeast,soutwest}direction;
typedef enum{normal,reverse}word_type; /*these are in order to do better way*/
/*Prototypes of my function*/
char get_chrc();
void fill_puzzle(char puzzle[15][15],char *dict[],int coord[15][4]);
void print_puzzle(char puzzle[15][15]);
int search_for_word(char puzzle[15][15],char word[WORD_LEN],char *dict[],int row,int column);
int search_for_directions(char puzzle[15][15],char word[WORD_LEN],int size,int row,int column,direction direct,word_type type);
int str_comp(char dest[WORD_LEN],char source[WORD_LEN]);
char make_upper(char letter);
int sizeof_dict(char *dict[]);
/*****MY CODE BEGİN IN THE MAİN*********/
int get_line_size(char *line) {
	char *ch_iter = line; // so as not to lose beginning of line
	int counter = 0;
	// go until you see new line or null char
	while(*ch_iter != '\n' && *ch_iter != '\0') {
		ch_iter++; // next char
		counter++; // increment counter
	}
	
	return counter;
}

void copy_string(char *source, char *destination) {
	// get iterators over original pointers
	char *src_iter = source;
	char *dst_iter = destination;
	// until null char
	while (*src_iter != '\0') {
		// copy pointers
		*dst_iter = *src_iter;
		// advance to next char
		src_iter++;
		dst_iter++;
   }
   // terminate string
   *dst_iter = '\0';
}

void remove_newline(char *line) {
	char *ch_iter = line;
	// go until you see new line
	while(*ch_iter != '\n' && *ch_iter != 13) {
		ch_iter++; // next char
	}
	*ch_iter = '\0'; // overwrite new line
}

void print_dictionary(char *dict[]) {
	int i;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		printf("%s\n", dict[i]);
	}
}

void print_coord(int coord[DICT_SIZE][4]) {
	int i, j;
	for(i = 0 ; i < DICT_SIZE ; i++) {
		for(j = 0 ; j < 4 ; j++) {
			printf("%d ", coord[i][j]);
		}
		printf("\n");
	}
}

int main(){
	char *dict[DICT_SIZE];
    int coord[DICT_SIZE][4];    
    char line[LINE_LEN];
	FILE *fp = fopen("word_hunter.dat", "r");
	
	int line_counter = 0;
	int dict_counter = 0;
	while(fgets(line, LINE_LEN, fp) != NULL) {
		if(line_counter%5 == 0) {
			dict[dict_counter] = (char*) malloc(sizeof(char) * get_line_size(line));
			remove_newline(line);
			copy_string(line, dict[dict_counter]);
		} else if (line_counter%5 == 1){
			coord[dict_counter][0] = atoi(line);
		} else if (line_counter%5 == 2){			
			coord[dict_counter][1] = atoi(line);		
		} else if (line_counter%5 == 3){
			coord[dict_counter][2] = atoi(line);
		} else if (line_counter%5 == 4){
			coord[dict_counter][3] = atoi(line);
			dict_counter++;
		}
		line_counter++;
	}
	
	fclose(fp);
	//print_dictionary(dict);
	//print_coord(coord);
//---------MY CODES-----------------//
	int row,column,i,j,k,result,size,size_word;
	char word[WORD_LEN],exit[WORD_LEN]="exit game";
	srand(time(0));
	char puzzle[15][15];
	fill_puzzle(puzzle,dict,coord); // fill puzle with random characters and dicts
	size=sizeof_dict(dict);// maybe the size of dict will be changed
	printf("\t***WELCOME THE PUZZLE GAME***\n");
	printf("-In order to exit please type 'exit game'.*GOOD LUCK:)*\n");
	do{
		
		print_puzzle(puzzle); // print puzzle
		printf("Please Enter the hidden word: ");
		scanf("%s",word);
		if (str_comp(exit,word)!=-1) break; //Player types “exit game”.
		printf("Please Enter a row Value for word(0-14): ");
		scanf("%d",&row);
		while(!(row>=0 && row<15)){ // check row

			printf("Please Enter a Value between 0 and 14: ");
			scanf("%d",&row);

		}
		printf("Please Enter a column Value for word(0-14): ");
		scanf("%d",&column);
		while(!(column>=0 && column<15)){ //check column

			printf("Please Enter a Value between 0 and 14: ");
			scanf("%d",&column);

		}
		result=search_for_word(puzzle,word,dict,row,column);
		if (result!=-1) // if the words find
		{
			printf("\n*** WELL DONE! The word is found***\n");
			size--; // decrease a size because one word is found
		}
		else{
			printf("\n***The Word was not found!***\n");
		}
		if (size==0){ // Player finds all the words in the puzzle.
			print_puzzle(puzzle); // first print puzzle
			printf("***Congratulations! You Win*** \n\n"); // then give message and finish with while condition
		}
	}while(size!=0); //check size
	
	return 0;
}
char get_chrc(){ //create a random character
	int asci_of_ch;
	char ch;
	asci_of_ch=(rand()%(122 +1- 97)) + 97; 
	ch=(char)asci_of_ch;
	return ch;
}
void fill_puzzle(char puzzle[15][15],char *dict[],int coord[15][4]){
	/*firstly fill the puzzle with random charecter*/
	int r, c,j,i,size,count,row;
	char karakter;
	for (r=0;r<15;r++) {
		for (c=0;c<15;c++){
			karakter=get_chrc();
			puzzle[r][c]=karakter;
			
		}
	}
	/*then fill the puzle with words which are in the dict*/
	for (r=0;r<15;r++) {
		size=get_line_size(dict[r]); // size of one word 
		for (j = 0; j <size; ++j)
		{
			puzzle[coord[r][0]][coord[r][1]]=dict[r][j]; // copy the letters to puzzle
			if ((coord[r][2]-coord[r][0])>=0 && (coord[r][3]-coord[r][1])==0) coord[r][0]++;// up to down
			else if ((coord[r][2]-coord[r][0])<=0 && (coord[r][3]-coord[r][1])==0) coord[r][0]--;// down to up
			else if ((coord[r][2]-coord[r][0])==0 && (coord[r][3]-coord[r][1])>=0) coord[r][1]++;//left to right
			else if ((coord[r][2]-coord[r][0])==0 && (coord[r][3]-coord[r][1])<=0) coord[r][1]--;//right to left 
			else if ((coord[r][2]-coord[r][0])>=0 && (coord[r][3]-coord[r][1])>=0) //up to down diagonal
			{
				coord[r][0]++;
				coord[r][1]++;
			}
			else if ((coord[r][2]-coord[r][0])<=0 && (coord[r][3]-coord[r][1])<=0) //down to up diagonal
			{
				coord[r][0]--;
				coord[r][1]--;
			}
			
		}
			
	}

}
void print_puzzle(char puzzle[15][15]){
	int j,i;
	// print the puzzle
	printf("\n");
	for(i = 0 ; i < 15 ; i++) {
		for(j = 0 ; j < 15 ; j++) {
			printf("%c ", puzzle[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int search_for_word(char puzzle[15][15],char word[WORD_LEN],char *dict[],int row,int column){
	int size,r,j,i,k,flag=1;
	size=get_line_size(word); // size_of_user's_word
	for (r=0;r<15;r++) {
		/*Check for all directions(16)*/
		flag=search_for_directions(puzzle,word,size, row,column,north,normal);
		if(flag!=-1){
			flag=r; // if find then save where it is
			break;//and don't continue
		}
		flag=search_for_directions(puzzle,word,size, row,column,north,reverse);
		if(flag!=-1){
			flag=r;
			break;
		}
		flag=search_for_directions(puzzle,word,size, row,column,south,normal);
		if(flag!=-1){
			flag=r;
			break;
		}
		flag=search_for_directions(puzzle,word,size, row,column,south,reverse);
		if(flag!=-1){
			flag=r;
			break;
		}
		flag=search_for_directions(puzzle,word,size, row,column,west,normal);
		if(flag!=-1){
			flag=r;
			break;
		}
		flag=search_for_directions(puzzle,word,size, row,column,west,reverse);
		if(flag!=-1){
			flag=r;
			break;
		}
		flag=search_for_directions(puzzle,word,size, row,column,east,normal);
		if(flag!=-1){
			flag=r;
			break;
		}
		flag=search_for_directions(puzzle,word,size, row,column,east,reverse);
		if(flag!=-1){
			flag=r;
			break;
		}
		flag=search_for_directions(puzzle,word,size, row,column,northwest,normal);
		if(flag!=-1){
			flag=r;
			break;
		}
		flag=search_for_directions(puzzle,word,size, row,column,northwest,reverse);
		if(flag!=-1){
			flag=r;
			break;
		}
		flag=search_for_directions(puzzle,word,size, row,column,northeast,normal);
		if(flag!=-1){
			flag=r;
			break;
		}
		flag=search_for_directions(puzzle,word,size, row,column,northeast,reverse);
		if(flag!=-1){
			flag=r;
			break;
		}
		flag=search_for_directions(puzzle,word,size, row,column,southeast,normal);
		if(flag!=-1){
			flag=r;
			break;
		}
		flag=search_for_directions(puzzle,word,size, row,column,southeast,reverse);
		if(flag!=-1){
			flag=r;
			break;
		}
		flag=search_for_directions(puzzle,word,size, row,column,soutwest,normal);
		if(flag!=-1){
			flag=r;
			break;
		}
		flag=search_for_directions(puzzle,word,size, row,column,soutwest,reverse);
		if(flag!=-1){
			flag=r;
			break;
		}
				
	}

	return flag; //return result
}
char make_upper(char letter){
	int d;
	d=letter;
	d=d-32;
	letter=(char)d;
	return letter;
}
int str_comp(char dest[WORD_LEN],char source[WORD_LEN]){ 
	//compare two different string
	int i=0,j,flag=0,size;
	size=get_line_size(source);
	for(j=0;j<size;j++){
		if(dest[j]!=source[j])
		{
			flag=-1;
		}	
	}
	if(flag!=-1){
		flag=2; //make the flag diferent than -1
	}
	return flag; // return flag
}
int sizeof_dict(char *dict[]){
	//in order to indicate  how many words do we have?
	int i,size=0;
	for (i = 0; i<DICT_SIZE; ++i)
	{
		if (dict[i][0]!='\0') size++;
		else break;	
	}
	return size;
}
int search_for_directions(char puzzle[15][15],char word[WORD_LEN],int size,int row,int column,direction direct,word_type type){
	/*In here I am checking the word which entered by user on the puzzle with 8 direction and 2 type. Is there any word like this on the puzzle ?
	if I find it , then  I make it upper on the puzzle by using loop.*/
	int flag=1,k,d,temp_row,temp_column;
	temp_row=row; // these are in order to use row and column later.
	temp_column=column;
	if (type==normal) // normal
	{
		for (k = 0; k <size; ++k) // normal loop
		{
			if (puzzle[row][column]!=word[k] && puzzle[row][column]!=make_upper(word[k])) // if any letter is different 
			{
				flag=-1; // then hold the flag
			}
			switch(direct){ // set the row and column according to direction
			case north:
				row--;
				break; 	
			case south:
				row++;
				break;
			case west:
				column--;
				break;
			case east:
				column++;
				break;
			case northwest:
				row--;
				column--;
				break;				
			case northeast:
				row--;
				column++;
				break;
			case soutwest:
				row++;
				column--;
				break;
			case southeast:
				row++;
				column++;
				break;
			default:
				printf("Unknown Error Happened!\n"); // default message
			}
			
		}
		if(flag==1){ // if the word was found make it upper on the puzzle by using same procedure
			for (k = 0; k <size; ++k) // normal loop
			{
				d=puzzle[temp_row][temp_column]; // take ascii
				if (d>90)// if the letter is lowercase then make upper, if not don't make uppercase
				{
					puzzle[temp_row][temp_column]=make_upper(puzzle[temp_row][temp_column]); // make upper
				}
				switch(direct){ // set row and column
				case north:
					temp_row--;
					break; 	
				case south:
					temp_row++;
					break;
				case west:
					temp_column--;
					break;
				case east:
					temp_column++;
					break;
				case northwest:
					temp_row--;
					temp_column--;
					break;				
				case northeast:
					temp_row--;
					temp_column++;
					break;
				case soutwest:
					temp_row++;
					temp_column--;
					break;
				case southeast:
					temp_row++;
					temp_column++;
					break;
				default:
					printf("Unknown Error Happened!\n");
				}
			}	
		}
	}
	else if (type==reverse) // reverse type 
	{
		for (k = size-1; k>=0; k--) // reverse the loop
		{
			if (puzzle[row][column]!=word[k] && puzzle[row][column]!=make_upper(word[k])) // if the letter is different
			{
				flag=-1; // hold the flag
			}
			switch(direct){ // set
			case north:
				row--;
				break; 	
			case south:
				row++;
				break;
			case west:
				column--;
				break;
			case east:
				column++;
				break;
			case northwest:
				row--;
				column--;
				break;				
			case northeast:
				row--;
				column++;
				break;
			case soutwest:
				row++;
				column--;
				break;
			case southeast:
				row++;
				column++;
				break;
			default:
				printf("Unknown Error Happened!\n");
			}
		}
		if(flag==1){ // if it was found
			for (k = size-1; k>=0; k--) // reverse loop
			{
				d=puzzle[temp_row][temp_column];//ascii
				if (d>90)// it means it is lowercase
				{
					puzzle[temp_row][temp_column]=make_upper(puzzle[temp_row][temp_column]); //make it upper
				}
				switch(direct){// set
				case north:
					temp_row--;
					break; 	
				case south:
					temp_row++;
					break;
				case west:
					temp_column--;
					break;
				case east:
					temp_column++;
					break;
				case northwest:
					temp_row--;
					temp_column--;
					break;				
				case northeast:
					temp_row--;
					temp_column++;
					break;
				case soutwest:
					temp_row++;
					temp_column--;
					break;
				case southeast:
					temp_row++;
					temp_column++;
					break;
				default:
					printf("Unknown Error Happened!\n");
				}
			}	
		}
	}	
	return flag; // and return flag

}








