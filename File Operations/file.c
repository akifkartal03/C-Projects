#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct member{

	char name[30];
	char surname[30];
	char mail[30];
	char id[30];


} Member;

int is_upper(char arr[100]);
int is_lower(char arr[100]);
int is_numeric(char arr[100]);
int is_mail(char arr[100]);
void write(Member *members, int limit);

int main(){
	int i, j, p = 0,k=1,l=1;
	char buffer[100];
	char buffer2[1000];
	Member *tmp = malloc(sizeof(Member));
	Member *all_members = malloc(sizeof(Member)*k); 
	FILE *f;
	f=fopen("Disordered.txt","r");
	i = 0;
	while(fscanf(f,"%s", buffer) == 1){
		if(is_mail(buffer)==0 && is_upper(buffer) == 1){
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
		if(i==4){
			Member *x = malloc(sizeof(Member));
			*x = *tmp;
			l=(k/4)+(k%4);
			all_members[p] = *x;
			all_members=realloc(all_members,sizeof(Member)*l);
			p++;
			i = 0;
		}
			
	}
	write(all_members,p);
	fclose(f);
	 // this is a function  here is in order to write another file ordered informations

	
	
	// Now all_members contain all ordered information
	// Do a looop to write another files

}

int is_upper(char arr[100]){
	int d,k=0;
	char c;
	for(d=0;d<strlen(arr);d++){
		c=arr[d];
		if(c>='A' && c<='Z'){
			k=k+1;
		}	
	}
	if(k>1){
		return 1;// upper_case
	}
	else{
		return 0;//lower_case
}

int is_lower(char arr[100]){
	int d,k=0;
	char c;
	for(d=0;d<strlen(arr);d++){
		c=arr[d];
		if(c>='a' && c<='z'){
			k=k+1;
		}	
	}
	if(k>1){
		return 1;// upper_case
	}
	else{
		return 0;// lower_case
	}
}

int is_numeric(char arr[100]){
	int d;
	for(d=0;d<strlen(arr);d++){
		if(arr[d]>='0' && arr[d]<='9'){ // numbers
			return 1;
		}	
	}
	return 0;
}
int is_mail(char arr[100]){
	int d;
	for(d=0;d<strlen(arr);d++){
		if(arr[d]=='@'){ // mail
			return 1;	
		}	
	}
	return 0;
}
void write(Member *members,int limit){
	int n;
	FILE *f2;
	f2=fopen("orderedFile.txt","a");
	fprintf(f2,"%s %s %s %s\n\n","ID","NAME","SURNAME","E-MAIL");
	for(n=0;n<limit;n++){
		fprintf(f2,"%s %s %s %s\n",members[n].id,members[n].name,members[n].surname,members[n].mail);

	}
	fclose(f2);

}


