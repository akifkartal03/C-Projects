#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct member{ // in here is struct

	char name[30];
	char surname[30];
	char mail[30];
	char id[30]; // I think type of id should be char


} Member;

int is_upper(char arr[100]);// these are check functions
int is_lower(char arr[100]);
int is_numeric(char arr[100]);
int is_mail(char arr[100]);
void write_id(Member *members,int limit); //these are write function
void write_others(Member *members,int limit,int secim);


int main(){
	int i, j, p = 0,k=1,l=1;
	char buffer[100];//word
	Member *tmp = malloc(sizeof(Member));//temprorary one member or one people
	Member *all_members = malloc(sizeof(Member)*k); // all members or people
	FILE *f;
	f=fopen("disordered_people.txt","r");//open file with read(r) mode
	i = 0;
	while(fscanf(f,"%s", buffer) == 1){
		if(is_mail(buffer)==0 && is_upper(buffer) == 1){ // these are in order to check the words(buffer contain just one word and it is checked by functions what is it.)
			strcpy(tmp->surname, buffer);		
		}
		else if(is_mail(buffer)==0 && is_lower(buffer) == 1){
			strcpy(tmp->name, buffer);		
		}
		if(is_mail(buffer)==0 && is_numeric(buffer) == 1){
			strcpy(tmp->id, buffer);		
		}
		if(is_mail(buffer)==1){
			strcpy(tmp->mail, buffer);		
		}
		i++;
		k++;		
		if(i==4){ //here is in order to check a line
			l=(k/4)+(k%4);//this is in order to get how many do we have members or people
			all_members[p] = *tmp;
			all_members=realloc(all_members,sizeof(Member)*l);//this is in order to increaese dimension of array of member
			p++;
			i = 0;
		}
			
	}
	char choice;
	printf("Give a Sort Metric (I = ID / N= NAME / S= SURNAME / M=MAIL) : ");
	scanf("%s",&choice);
	while(choice!='I'&&choice!='N'&&choice!='S'&&choice!='M'&&choice!='i'&&choice!='n'&&choice!='s'&&choice!='m'){//if choice is not true
		printf("Please Enter Again Correctly\n");
		printf("Give a Sort Metric (I = ID / N= NAME / S= SURNAME / M=MAIL) : ");
		scanf("%s",&choice);
		
	}
	if(choice=='I'||choice=='i'){//What do user want?(sort them according to this)
		
		write_id(all_members,p);
	}
	else if(choice=='N'||choice=='n'){
		
		write_others(all_members,p,1);
	}
	else if(choice=='S'||choice=='s'){
		
		write_others(all_members,p,2);
	}
	else if(choice=='M'||choice=='m'){
		
		write_others(all_members,p,3);
	}
	fclose(f); //close
	printf("The Ordered File created successfully. Please Check it.\n");
	return 0;
}

int is_upper(char arr[100]){ // check "buyuk harf"
	int d,k=0;
	char c;
	for(d=0;d<strlen(arr);d++){
		c=arr[d];
		if(c>='A' && c<='Z'){
			k=k+1;
		}	
	}
	if(k>1){
		return 1;// "buyuk harf"
	}
	else{
		return 0;//or not
	}
}

int is_lower(char arr[100]){ // check "kucuk harf"
	int d,k=0;
	char c;
	for(d=0;d<strlen(arr);d++){
		c=arr[d];
		if(c>='a' && c<='z'){
			k=k+1;
		}	
	}
	if(k>1){
		return 1;// "kucuk harf"
	}
	else{
		return 0;//or not
	}
}

int is_numeric(char arr[100]){ //check "sayý"
	int d;
	for(d=0;d<strlen(arr);d++){
		if(arr[d]>='0' && arr[d]<='9'){ // numbers
			return 1;
		}	
	}
	return 0; //or not
}
int is_mail(char arr[100]){  //check "email"
	int d;
	for(d=0;d<strlen(arr);d++){
		if(arr[d]=='@'){ 
			return 1;	// mail
		}	
	}
	return 0; //or not
}
void write_id(Member *members,int limit){ //sort the members according to ID and write the members with ordered.
	int n,i,j;
	int number1,number2;
	int ass,ass2;
	Member *temp = malloc(sizeof(Member));// temprorary member or people
	for(i=0;i<=limit;i++){
	       for(j=0;j<limit; j++){
				ass= sscanf(members[j].id, "%d", &number1);//in here,since type of id is char,I use sscanf in order to get value of id and then I compare them.
				ass2= sscanf(members[i].id, "%d", &number2);
	           	if(number1	> number2){//compare them with id values(I got them above)
	           		*temp = members[i];//and swap them
	           		members[i]= members[j];
	           		members[j]=*temp;
	           	}
		    }
		    
	}
	FILE *f2;
	f2=fopen("orderedFile.txt","a");//in here, in order to write(open files with appendix(a) mode)
	fprintf(f2,"%s\t%15s\t%15s\t%20s\n\n","ID","NAME","SURNAME","MAIL");
	for(n=0;n<limit;n++){
		fprintf(f2,"%s\t%15s\t%15s\t%30s\n",members[n].id,members[n].name,members[n].surname,members[n].mail); //write another file

	}
	fclose(f2);//close

}

void write_others(Member *members,int limit,int secim){ //sort the members according to secim(from user) and write them with ordered.
	int n,d,a1,a2,i,j;
	Member *temp = malloc(sizeof(Member));	
	for(d=0;d<=limit;d++){
		for(i=0;i<limit;i++){
	       	for(j=0;j<30; j++){
	       			if(secim==1){//what do user want? (sort them according to this)
	       				a1=members[i].name[j];//ascii numbers
						a2=members[i+1].name[j];	
					}
	       			else if(secim==2){
	       				a1=members[i].surname[j];//ascii numbers
						a2=members[i+1].surname[j];	
					}
					else if(secim==3){
	       				a1=members[i].mail[j];//ascii numbers
						a2=members[i+1].mail[j];		
					}
	           		if(a1 < a2){//compare them with ascii numbers and "kücükse biþey yapma ve cýk"
	           			
	           			break;
	           		}
	           		else if(a1 > a2){//compare them with ascii numbers and "bulur bulmaz cýk diðerlerine bakma "
	           			*temp = members[i];//and swap them
	           			members[i]= members[i+1];
	           			members[i+1]=*temp;
	           			break;
	           		}
	           	
	       		
			}
		    
		}
	}
	FILE *f2;
	f2=fopen("orderedFile.txt","a");//in here, in order to write(open files with appendix(a) mode)
	if(secim==1){
		fprintf(f2,"%s          %s          %s          %s\n\n","NAME","ID","SURNAME","MAIL");
		
			
	}
	else if(secim==2){
		fprintf(f2,"%s          %s          %s          %s\n\n","SURNAME","ID","NAME","MAIL");
		
			
	}
	else if(secim==3){
		fprintf(f2,"%s                  %s          %s          %s\n\n","MAIL","ID","NAME","SURNAME");
		
			
	}
	for(n=0;n<limit;n++){
		if(secim==1){
			//fprintf(f2,"%s\t%15s\t%15s\t%20s\n\n","NAME","ID","SURNAME","MAIL");
			fprintf(f2,"%s         %s         %s         %s\n",members[n].name,members[n].id,members[n].surname,members[n].mail);//write another file
			
		}
		else if(secim==2){
			//fprintf(f2,"%s\t%15s\t%15s\t%20s\n\n","SURNAME","ID","NAME","MAIL");
			fprintf(f2,"%s         %s         %s         %s\n",members[n].surname,members[n].id,members[n].name,members[n].mail);//write another file
			
		}
		else if(secim==3){
			//fprintf(f2,"%s\t%15s\t%15s\t%20s\n\n","MAIL","ID","NAME","SURNAME");
			fprintf(f2,"%s         %s         %s         %s\n",members[n].mail,members[n].id,members[n].name,members[n].surname);//write another file
			
		}
		
	}//end of for loop
	fclose(f2);//close the file

}




