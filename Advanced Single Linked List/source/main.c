#include "linked_list.h"

int main(){
    node_t *head = NULL;
    head = createList(head);
    int a = sortList(head);
    printList(head,a);
    return 0;
}