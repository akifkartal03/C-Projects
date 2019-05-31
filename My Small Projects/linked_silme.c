#include <stdio.h>
#include <stdlib.h>

typedef struct node_s
{
    int data;
    char *name;
    struct node_s *next;
}node_t;
node_t * add(node_t *head,int value);
void init( node_t *head);
void deleting(node_t *head,int value);
int main(){
    int i;
    node_t *iter;
    node_t *head;
    iter=(node_t*)malloc(sizeof(node_t));
    head=iter;
    for( i = 0; i < 5; i++)
    {
        if (i!=4) {
            iter->next=(node_t*)malloc(sizeof(node_t));
            iter=iter->next;
        }
        else
        {
            iter=NULL;
        }
        
        
        
    }
    iter=NULL;
    init(head);
    deleting(head,6);
    head=add(head,6);
    head=add(head,7);
    head=add(head,1);
    head=add(head,3);
    head=add(head,-1);

    return 0;
}
void init( node_t *head){
    int i;
    node_t *iter;
    iter=head;
    for( i = 0; i < 5; i++)
    {
        iter->data=i;
        iter=iter->next; 
    }
    
}
void deleting(node_t *head,int value){
    int flag=0;
    node_t *iter,*temp;
    iter=head;
    temp=head;
    if (iter->data==value) {
        temp=iter;
        iter=iter->next;
        head=iter;
        free(temp);
    }

    while(iter->next!=NULL){
    
        if (iter->next->data==value){
            temp=iter;
            flag=1;
        }
        iter=iter->next;
    }
    if (flag==1) {
        iter=temp->next;
        temp->next=iter->next;
        free(iter);
    }
    else
    {
        printf("sayı bulunamadı ...\n");
    }
    
}

node_t * add(node_t *head,int value){

    node_t *iter;
    iter=head;
    if (head==NULL) {
        head=(node_t *)malloc(sizeof(node_t));
        head->data=value;
        head->next=NULL;
        return head;
    }
    if (head->data>value) {
        node_t *temp=(node_t*)malloc(sizeof(node_t));
        temp->data=value;
        temp->next=head;
        return temp;
    }
    while(iter->next!=NULL && iter->next->data<value){
        iter=iter->next;
    }
    node_t *temp=(node_t *)malloc(sizeof(node_t));
    temp->data=value;
    temp->next=iter->next;
    iter->next =temp;
    return head;

}