#include<string.h>
#include "linked_list.h"

int indexOf(node_t *head, char *word){
    node_t *iter;
    iter = head;
    int i = 0;
    while(iter != NULL){
        if (strcmp(iter->word,word) == 0)
        {
            iter->count = iter->count+1;
            return i;
        }
        i++;
        iter = iter->next;
    }
    return -1 ;

}
node_t* addFirst(node_t *head , char *word){
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    temp->word = (char *) malloc(100);
    strcpy(temp->word,word);
    temp->count = 1;
    temp->next =head;
    head=temp;
    return head;
}
node_t* add(node_t *head , char *word ,int index){
    if(head==NULL){
        return addFirst(head,word);
    }
    node_t *iter;
    iter = head;
    int i = 0;
    while(i < index-1 && iter != NULL){
        i++;
        iter = iter->next;
    }
    node_t *temp = (node_t*)malloc(sizeof(node_t));
    strcpy(temp->word,word);
    temp->count = 1;
    temp->next =iter->next;
    iter->next = temp;
    return head;

}
node_t* addLast(node_t *head ,char *word){
    if(head==NULL){
        return addFirst(head,word);
    }
    node_t *iter;
    iter = head;
    while(iter->next != NULL){

        iter = iter->next;
    }
    node_t *temp = (node_t*)malloc(sizeof(node_t));
    strcpy(temp->word,word);
    temp->count = 1;
    iter->next = temp;
    temp->next = NULL;
    return head;
}

int sortList(node_t *head){
    node_t *node=NULL, *temp = NULL;
    int tempvar;
    char *tempWord = (char *) malloc(100);
    node = head;
    int i = 0;
    while(node != NULL)
    {
        temp=node;
        while (temp->next !=NULL)
        {
           if(temp->count > temp->next->count)
            {
              tempvar = temp->count;
              temp->count = temp->next->count;
              temp->next->count = tempvar;
              strcpy(tempWord,temp->word);
              strcpy(temp->word,temp->next->word);
              strcpy(temp->next->word,tempWord);
            }
         temp = temp->next;
        }
        node = node->next;
        i++;
    }
    return i;
}
node_t* createList(node_t *head){
    FILE *fptr = fopen("input.txt","r");
    if(fptr==NULL){
        printf("File open error!!\n");
        return NULL;
    }
    char * line = NULL;
    size_t len = 0;
    size_t read;
    char *pch = NULL;
    //node_t *head = NULL;
    while ((read = getline(&line, &len, fptr)) != -1) {
        pch = strtok (line," \n");
        while (pch != NULL)
        {
            if (indexOf(head,pch)== -1)
            {
                head = addFirst(head,pch);
            }
            pch = strtok (NULL, " \n");
        }
    }

    fclose(fptr);
    return head;

}
void printList(node_t *head,int i){
    if (head == NULL)
       return;
    printList(head->next,i-1);
    printf("%d. %s: %d\n",i,head->word,head->count);
}