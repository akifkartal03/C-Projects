#ifndef LINKEDLIST
#define LINKEDLIST
#include<stdio.h>
#include<stdlib.h>

typedef struct node_s
{
    int count;
    char *word;
    struct node_s *next;

}node_t;

int indexOf(node_t *head, char *word);
node_t* addFirst(node_t *head , char *word);
node_t* add(node_t *head , char *word ,int index);
node_t* addLast(node_t *head ,char *word);
int sortList(node_t *head);
node_t* createList(node_t *head);
void printList(node_t *head,int i);
#endif