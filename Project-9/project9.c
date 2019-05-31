#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 25
struct person{
    char name[size],
        surname[size] ,
        musical_Work[size];
    int age;
    struct person *next;
} *top;
/*prototypes of functions*/
void menu();//my auxilary function
void addNode(char name[], char surname[], char creation[], int age);
void deleteNode();
void Sort_Alphabetically();
void Sort_Increasingly(); 
void print_node();
int main(){

    
    menu();
    return 0;

}
void menu(){

    int choice,age;
    char name[25], surname[25],creation[25];
    do {
        printf("\t***MENU***\n");
        printf("1-Add a Person to the Stack\n");
		printf("2-Pop a Person from the Stack\n");
		printf("3-Sort Alphabetical Order\n");
		printf("4-Sort Age in Increasing Order\n");
		printf("5-Exit menu\n");
		printf("Please Select an Option to continue: ");
		scanf("%d",&choice);
		while((choice<1) || (choice>5)){ //check the choice
					
			printf("This is an invalid choice. Try again!\n");
			printf("Please Select an Option to continue: ");
			scanf("%d",&choice);
		}
        switch(choice){
        case 1:
			addNode(name, surname, creation, age);
            print_node();
			break;
		case 2:
            deleteNode();
            print_node();
			break;
		case 3:
			Sort_Alphabetically();
            print_node();
			break;
		case 4:
			Sort_Increasingly();
            print_node();
			break;
		case 5:
			//in the while condition
			break;
		default :
			printf("Invalid choice\n");
		}

    }while(choice!=5);

}
void addNode(char name[], char surname[], char creation[], int age){
    struct person *newp; // create a temp node
    newp = (struct person*)malloc(sizeof(struct person));
    printf("Name: "); 
    scanf(" %[^\n]s",name);
    printf("Surname: ");
    scanf(" %[^\n]s",surname);
    printf("Creation: ");
    scanf(" %[^\n]s",creation);;
    printf("Age: ");
    scanf("%d",&age);
    strcpy(newp->name,name);
    strcpy(newp->surname,surname);
    strcpy(newp->musical_Work,creation);
    newp->age=age;
    /*add the node top of the linked list(stack)*/
    if (top==NULL) {
        top=newp;
        newp->next=NULL;
    }
    else{
        newp->next=top;
        top=newp;
    }
    
}
void deleteNode(){

    struct person *temp; //temp node
    if (top==NULL) {
        return;
    }
    else
    {
        /*Delete the first node*/
        temp=top;
        top=top->next;
        free(temp);
    }

}
void print_node(){
    int i=1;
    struct person *iter;//iterater
    iter=top;
    if (top==NULL) {
        printf("List is empty!\n");
    }
    else
    {
        /*print the values*/
        while(iter!=NULL){
            printf("%d)%s\n",i,iter->name);
            printf("%s\n",iter->surname);
            printf("%s\n",iter->musical_Work);
            printf("%d\n",iter->age);
            i++;
            iter=iter->next;
            
        }
        printf("\n");
        
    }
}
void Sort_Alphabetically(){
    struct person *iter,*iter2,tmp;
    iter=top;
    if (top==NULL) {
        return;
    }
    else
    {
        /*bubble sort with while loops*/
        while(iter!=NULL){
            iter2=iter->next;
            while (iter2!=NULL)
            {
                
                 if ((strcmp(iter2->name,iter->name)<0)) {
                    /*swap them*/
                    tmp=*iter2;
                    strcpy(iter2->name,iter->name);
                    strcpy(iter2->surname,iter->surname);
                    strcpy(iter2->musical_Work,iter->musical_Work);
                    iter2->age=iter->age;
                    strcpy(iter->name,tmp.name);
                    strcpy(iter->surname,tmp.surname);
                    strcpy(iter->musical_Work,tmp.musical_Work);
                    iter->age=tmp.age;

                }
                iter2=iter2->next;
                
            }
            iter=iter->next;
            if (iter->next==NULL) iter=iter->next;
        }

    }

}
void Sort_Increasingly(){

    struct person *iter,*iter2,tmp;
    iter=top;
    if (top==NULL) {
        return;
    }
    else
    {
        /*bubble sort with while loops*/
        while(iter!=NULL){
            iter2=iter->next;
            while (iter2!=NULL)
            {
                
                 if (iter2->age < iter->age){
                    /*swap them*/
                    tmp=*iter2;
                    strcpy(iter2->name,iter->name);
                    strcpy(iter2->surname,iter->surname);
                    strcpy(iter2->musical_Work,iter->musical_Work);
                    iter2->age=iter->age;
                    strcpy(iter->name,tmp.name);
                    strcpy(iter->surname,tmp.surname);
                    strcpy(iter->musical_Work,tmp.musical_Work);
                    iter->age=tmp.age;

                }
                iter2=iter2->next;
                
            }
            iter=iter->next;
            if (iter->next==NULL) iter=iter->next;
        }

    }

}
