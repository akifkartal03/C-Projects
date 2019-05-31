#include <stdio.h>
#include<stdlib.h>

 #define TYPED_ALLOC(type) (type *)malloc(sizeof (type))

 typedef struct tree_node_s {
 int key;
 struct tree_node_s *leftp, *rightp;
 } tree_node_t;

tree_node_t *tree_insert(tree_node_t *rootp, int new_key);
void tree_inorder(tree_node_t *rootp);
void tree_search(tree_node_t *rootp,int searc_key);
void ordered_print(tree_node_t *rootp); 

 int
 main(void)
 {
    tree_node_t *bs_treep; /* binary search tree */
    int data_key; /* input - keys for tree */
    int status; /* status of input operation */

    bs_treep = NULL; /* Initially, tree is empty */
    bs_treep=tree_insert(bs_treep,5);
    bs_treep=tree_insert(bs_treep,6);
    bs_treep=tree_insert(bs_treep,3);
    bs_treep=tree_insert(bs_treep,8);
    bs_treep=tree_insert(bs_treep,-1);
    bs_treep=tree_insert(bs_treep,2);
    bs_treep=tree_insert(bs_treep,0);
    bs_treep=tree_insert(bs_treep,4);
    bs_treep=tree_insert(bs_treep,10);
    ordered_print(bs_treep);
    //tree_search(bs_treep,0);
    //printf("sadasd");

 }
 tree_node_t *tree_insert(tree_node_t *rootp, int new_key){

     if (rootp == NULL) { /* Simple Case 1 - Empty tree */
        rootp = TYPED_ALLOC(tree_node_t);
        rootp->key = new_key;
        rootp->leftp = NULL;
        rootp->rightp = NULL;
    } 
    else if (new_key == rootp->key) { /* Simple Case 2 */
        /* duplicate key - no insertion */
    } 
    else if (new_key < rootp->key) { /* Insert in */
        rootp->leftp = tree_insert(rootp->leftp, new_key);
    } 
    else { /* Insert in right subtree */
        rootp->rightp = tree_insert(rootp->rightp,new_key);
    }

    return (rootp); /* left subtree */
 }
 void tree_search(tree_node_t *rootp,int searc_key){
     static int i=0,j=0;
     if (rootp==NULL)
     {
         return;
     }
     else if (rootp->key==searc_key)
     {
        j++;
        printf("1 Result found on %d step\n",j);
        //tree_search(rootp->rightp,searc_key); 
     }
     else if (searc_key<rootp->key)
     {
         j++;
         tree_search(rootp->leftp,searc_key);
         
     }
     else
     {
         j++;
         tree_search(rootp->rightp,searc_key);
         
     }
     
     
 }
 void ordered_print(tree_node_t *rootp){
     tree_node_t *iter=rootp;
     while (iter->rightp!=NULL)
     {
         iter=iter->rightp;
     }
     printf("max: %d\n",iter->key);
    iter=rootp;
     while (iter->leftp!=NULL)
     {
         iter=iter->leftp;
     }
     printf("min: %d\n",iter->key);
     
    
 }