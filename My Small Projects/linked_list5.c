#include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 typedef struct  node_s{

     char a;
     struct node_s *next;

 }list_t;
 char *foo(list_t *list);
 int main(){
     int i;
     char name[12]="akif kartal";
     char *name2;
     list_t *head,*temp;
     char *sentence;
     head=(list_t*)malloc(sizeof(list_t));
     temp=head;
     /*Create a linked list*/
     for ( i = 0; i <11; i++)
     {
         head->a=name[i];
         head->next=(list_t*)malloc(sizeof(list_t));
         head=head->next;
     }
     head->next=NULL;
     name2=foo(temp);
     printf("%s\n",name2);
     
     
 }
 char *foo(list_t *list){

     char *name=(char*)malloc(sizeof(char)*5);
     int i=0;
     while (list!=NULL)
     {
        name[i]=list->a;
        i++;
        list=list->next;

     }
     return name;

 }