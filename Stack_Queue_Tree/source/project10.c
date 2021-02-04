#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*this is for stack */
typedef struct st{
    int data;
    struct st *next;
}stack;

/*these are for queue*/
typedef struct qu{
    int data;
    struct qu *next;
}node_t;
typedef struct{

    node_t *frontp;
    node_t *rearp;
    int size;
}queue;
/*this is for binary tree*/
typedef struct b_tree{
    int data;
    struct b_tree *leftp,*rightp;
}bst;

void fill_structures(stack ** stack_, queue ** queue_, bst ** bst_, int data[20]);
void ordered_print(stack * stack_, queue * queue_, bst * bst_);
void search(stack * stack_, queue * queue_, bst * bst_, int val_to_search);
void special_traverse(stack * stack_, queue * queue_, bst * bst_);
            /*My Helper Functions*/
bst *fill_bst( bst * bst_,int data); 
void bubble_sort(stack *roots,queue *rootq,int flag);
void print_bst(bst * bst_,int *min,int flag);
void tree_search(bst *rootp,int searc_key,int step);
stack *create_temp_s(stack *root);
queue *create_temp_q( queue *root);
int find_max_s(stack *root);
int find_min_s(stack *root);
stack *pop(stack *root,int key);
int find_max_q(queue *root);
int find_min_q(queue *root);
queue *pop_q(queue *root,int key);
void print_bst_min(bst * bst_,int flag,int *min);
void print_bst_traverse(bst * bst_,bst *bst2,int flag,int *min);
int main(){

    int data[20]={5, 2, 7, 8, 11, 3, 21, 7, 6, 15, 19, 35, 24, 1, 8, 12, 17,8, 23, 4};
    bst * bst_;
    queue * queue_;
    stack  *stack_;
    fill_structures(&stack_, &queue_, &bst_, data);
    ordered_print(stack_, queue_, bst_);
    search(stack_, queue_, bst_, 5);
    special_traverse(stack_, queue_, bst_);
   
    return 0;
    
}
void fill_structures(stack ** stack_, queue ** queue_, bst ** bst_, int data[20]){
    int i;
    /*fill the stack*/
    double time_s,time_q,time_b,mili;
    mili=(double)1000;
    clock_t s,e;
    
    *stack_ =NULL;
    s=clock();
    for (i = 0; i < 20; i++)
    {
        stack *newp;
        newp=(stack *)malloc(sizeof(stack));
        newp->data=data[i];
        newp->next=*stack_;
        *stack_=newp;
    }
    e=clock();
    time_s = ((double) (e - s)/CLOCKS_PER_SEC)*mili;
    
    /*fill the queue*/
    *queue_ =(queue*)malloc(sizeof(queue));
    (*queue_)->size=0;
    s=clock();
    for (i = 0; i < 20; i++)
    {
        if ((*queue_)->size ==0)
        {
            (*queue_)->rearp=(node_t*)malloc(sizeof(node_t));
            (*queue_)->frontp= (*queue_)->rearp; 
        }
        else
        {
            (*queue_)->rearp->next=(node_t*)malloc(sizeof(node_t));
            (*queue_)->rearp= (*queue_)->rearp->next; 
        }
        (*queue_)->rearp->data=data[i];
        (*queue_)->rearp->next=NULL;
        (*queue_)->size=(*queue_)->size+1; 
    }
    e=clock();
    time_q = ((double) (e - s)/CLOCKS_PER_SEC)*mili;
    /*fill the bst*/
    s=clock();
    for (i = 0; i < 20; i++)
    {
        *bst_=fill_bst((*bst_),data[i]);
    }
    e=clock();
    time_b = ((double) (e - s)/CLOCKS_PER_SEC)*mili;
    printf("-------------------FILL--------------------------------\n");
    printf("Structures\tStack\tQueue\tBST\n");
    printf("Exec. Time\t%.3f\t%.3f\t%.3f\n",time_s,time_q,time_b);
    printf("\n");
}
bst *fill_bst( bst * bst_,int data){
    
    if (bst_ == NULL) { 
        bst_ = (bst*)malloc(sizeof(bst));
        bst_->data = data;
        bst_->leftp = NULL;
        bst_->rightp = NULL;
    } 
    else if (data == bst_->data) { 
        //same data 
        //don't insert
    } 
    else if (data < bst_->data) {
        bst_->leftp = fill_bst(bst_->leftp, data);
    } 
    else { 
        bst_->rightp =fill_bst(bst_->rightp,data);
    }

    return bst_; 
}
void ordered_print(stack * stack_, queue * queue_, bst * bst_){
    printf("-------------------ORDERED PRINT-----------------------\n");
    double time_s,time_q,time_b,mili;
    mili=(double)1000;
    clock_t s,e;
    int max,min;
    stack *temp_s,*head;
    queue *temp_q;
    /*order and print temp stack*/

    s=clock();
    temp_s=create_temp_s(stack_); //create a temp stack
    bubble_sort(temp_s,temp_q,0); //sort the temp stack
    printf("Stack: ");
    while (temp_s!=NULL) //print sorted temp stack
    {
        printf("%d ",temp_s->data);
        temp_s=temp_s->next;
    }
    printf("\n");
    e=clock();
    time_s = ((double)(e - s)/CLOCKS_PER_SEC)*mili;
    /*order and print temp queue*/

    s=clock();
    temp_q=create_temp_q(queue_);//create a temp queue
    bubble_sort(temp_s,temp_q,1); //sort the temp queue
    printf("Queue: ");
    while (temp_q->frontp!=NULL) //print sorted temp queue
    {
        printf("%d ",temp_q->frontp->data);
        temp_q->frontp=temp_q->frontp->next;
    }
    printf("\n");
    e=clock();
    time_q = ((double)(e - s)/CLOCKS_PER_SEC)*mili;
    /*print bst*/

    printf("Bst: ");
    s=clock();
    print_bst(bst_,&min,1); //print bst with recursively
    e=clock();
    time_b = ((double)(e - s)/CLOCKS_PER_SEC)*mili;
    printf("\n");
    /*Print time*/
    printf("Structures\tStack\tQueue\tBST\n"); 
    printf("Exec. Time\t%.3f\t%.3f\t%.3f\n",time_s,time_q,time_b);
    /*free the temps variable*/
    free(temp_s);
    free(temp_q);
    printf("\n");
}
stack *create_temp_s(stack *root){
    /*İn order to not break the orijinal stack 
       create a temp stack*/
    stack *temp,*head;
    stack *iter=root;
    temp=(stack*)malloc(sizeof(temp));
    head=temp;
    while (iter!=NULL)
    {
        temp->data=iter->data;
        if (iter->next!=NULL)
        {
            temp->next=(stack*)malloc(sizeof(temp));
            temp=temp->next; 
        }
        else temp->next=NULL;
        iter=iter->next;
       
    }
    return head;
    

}
queue *create_temp_q( queue *root){
    /*İn order to not break the orijinal queue 
       create a temp queue*/
    queue *temp,*head;
    queue *iter;
    iter=(queue*)malloc(sizeof(queue));
    iter->frontp=root->frontp;
    temp =(queue*)malloc(sizeof(queue));
    temp->rearp=(node_t*)malloc(sizeof(node_t));
    temp->frontp=temp->rearp;
    head=temp; 
    while (iter->frontp!=NULL)
    {
        temp->rearp->data=iter->frontp->data;
        if (iter->frontp->next!=NULL)
        {
            temp->rearp->next=(node_t*)malloc(sizeof(node_t));
            temp->rearp= temp->rearp->next;
            temp->size=temp->size+1;
            temp->rearp->next=NULL; 
        }
        else//
        {
            temp->rearp->next=NULL;
        }
        iter->frontp=iter->frontp->next;
    }
    return head;

}
void bubble_sort(stack *roots,queue *rootq,int flag){
   
    if (flag==0)  /*sort stack*/
    {
        stack *iter,*iter2,tmp;
        iter=roots;
        /*bubble sort with while loops*/
        while(iter!=NULL){
            iter2=iter->next;
            while (iter2!=NULL)
            {
                    
                if (iter2->data > iter->data){
                    /*swap them*/
                    tmp=*iter2;
                    iter2->data=iter->data;
                    iter->data=tmp.data;
                }
                iter2=iter2->next;
                    
            }
            iter=iter->next;
            if (iter->next==NULL) iter=iter->next;
        }
    }
    else{  /*sort queue*/
       
        node_t *iter,*iter2,tmp;
        iter=rootq->frontp;
        /*bubble sort with while loops*/
        while(iter!=NULL){
            iter2=iter->next;
            while (iter2!=NULL)
            {
                    
                if (iter2->data > iter->data){
                    /*swap them*/
                    tmp=*iter2;
                    iter2->data=iter->data;
                    iter->data=tmp.data;

                }
                iter2=iter2->next;
                    
            }
            iter=iter->next;
            if (iter->next==NULL) iter=iter->next;
        }

    }
    
}
void print_bst(bst * bst_,int *min,int flag){
    if (bst_==NULL) // base case
    {
        return;//stop;
    }
    else
    {
        print_bst(bst_->rightp,min,flag);
        if (flag==1)
        {
            printf("%d ",bst_->data);
        }
        else
        {
            *min=bst_->data;
        }
        print_bst(bst_->leftp,min,flag);
       
    }
}
void search(stack * stack_, queue * queue_, bst * bst_, int val_to_search){
    printf("-------------------SEARCHING---------------------------\n");
    double time_s,time_q,time_b,mili;
    int i=1;
    mili=(double)1000;
    clock_t s,e;
    stack * iter=stack_;
    s=clock();
    //search in the stack
    while (iter!=NULL)
    {   
        if (iter->data==val_to_search)
        {
            printf("1 result founded on %d. step.(in Stack)\n",i);
        }
        iter=iter->next;
        i++;
    
    }
    e=clock();
    time_s = ((double)(e - s)/CLOCKS_PER_SEC)*mili;
    i=1;
    node_t * iter1=queue_->frontp;
    s=clock();
    //search in the queue
    while (iter1!=NULL)
    {
        if (iter1->data==val_to_search)
        {
            printf("1 result founded on %d. step.(in Queue)\n",i);
        }
        iter1=iter1->next;
        i++;
    
    }
    e=clock();
    time_q = ((double) (e - s)/CLOCKS_PER_SEC)*mili;
    i=0;
    s=clock();
    tree_search(bst_,val_to_search,i); //search in the bst
    e=clock();
    time_b = ((double) (e - s)/CLOCKS_PER_SEC)*mili;
    printf("Structures\tStack\tQueue\tBST\n");
    printf("Exec. Time\t%.3f\t%.3f\t%.3f\n",time_s,time_q,time_b);
    printf("\n");

}
void tree_search(bst *rootp,int searc_key,int step){
    /*search tree with recursively*/
    if (rootp==NULL)
    {
        return;
    }
    else if (rootp->data==searc_key)
    {
        step++;
        printf("1 Result founded on %d. step.(in Bst)\n",step); 
    }
    else if (searc_key<rootp->data)
    {
         step++;
         tree_search(rootp->leftp,searc_key,step);
         
    }
    else
    {
         step++;
         tree_search(rootp->rightp,searc_key,step);
         
    }

}
void special_traverse(stack * stack_, queue * queue_, bst * bst_){
    printf("-------------------SPEACIAL TRAVERSE-------------------\n");
    double time_s,time_q,time_b,mili;
    int max,min;
    mili=(double)1000;
    clock_t s,e;
    stack *temp_s;
    queue *temp_q;
    /*print stack*/
    s=clock();
    temp_s=create_temp_s(stack_);//create a temp stackk
    printf("Stack: ");
    while (temp_s!=NULL)
    {
        max=find_max_s(temp_s);//find max in the temp stack
        printf("%d ",max); //print it
        temp_s=pop(temp_s,max); //delete it from temp stack
        min=find_min_s(temp_s); //find min in the temp stack
        printf("%d ",min); //print it
        temp_s=pop(temp_s,min); //delete it from temp stack

    }
    printf("\n");
    e=clock();
    time_s = ((double) (e - s)/CLOCKS_PER_SEC)*mili;
    /*print queue*/
    s=clock();
    printf("Queue: ");
    temp_q=create_temp_q(queue_);//create a temp stack
    while (temp_q->frontp!=NULL)
    {
        max=find_max_q(temp_q);//find max in the temp queue
        printf("%d ",max); //print it
        temp_q=pop_q(temp_q,max);//delete it from temp queue
        min=find_min_q(temp_q);//find min in the temp queue
        printf("%d ",min);//print it
        temp_q=pop_q(temp_q,min);//delete it from temp queue

    }
    printf("\n");
    e=clock();
    time_q = ((double) (e - s)/CLOCKS_PER_SEC)*mili;
    /*print bst*/
    printf("Bst: ");
    print_bst(bst_,&min,0);//find the min value of bst
    min--;
    s=clock();
    print_bst_traverse(bst_,bst_,min,&min); //print traverse
    e=clock();
    time_b = ((double)(e - s)/CLOCKS_PER_SEC)*mili;
    printf("\n");
    printf("Structures\tStack\tQueue\tBST\n");
    printf("Exec. Time\t%.3f\t%.3f\t%.3f\n",time_s,time_q,time_b);
    printf("------------------------------------------------------\n");
    free(temp_s);
    free(temp_q);
}
int find_max_s(stack *root){
    //find the max value of stack
    int max;
    stack *iter;
    iter=root;
    max=iter->data;
    while(iter!=NULL){
        if (iter->data > max){
            max=iter->data;
        }
        iter=iter->next;
     }
    return max;
}
int find_min_s(stack *root){
    //find the min value of stack
    int min;
    stack *iter;
    iter=root;
    min=iter->data;
    while(iter!=NULL){
        if (iter->data < min){
            min=iter->data;
        }
        iter=iter->next;
     }
    return min;
}
stack *pop(stack *root,int key){
    //delete given key from stack
    stack *iter=root;
    stack *temp;
    if (iter->next==NULL)
    {
        temp=iter;
        root=NULL;
        free(temp);
        return root;   
    }
    else if (iter->data==key)
    {
        temp=iter;
        iter=iter->next;
        root=iter;
        free(temp);
        return root;
            
    }
    else
    {
        while (iter->next!=NULL)
        {
            if (iter->next->data==key)
            {
                temp=iter->next;
                iter->next=iter->next->next;
                free(temp);
                break;
            }
            iter=iter->next;
        }
    }
    return root;
    
}
int find_max_q(queue *root){
    //find the max value of queue
    int max;
    node_t *iter;
    iter=root->frontp;
    max=iter->data;
    while(iter!=NULL){
        if (iter->data > max){
            max=iter->data;
        }
        iter=iter->next;
     }
    return max;
}
int find_min_q(queue *root){
    //find the min value of queue
    int min;
    node_t *iter;
    iter=root->frontp;
    min=iter->data;
    while(iter!=NULL){
        if (iter->data < min){
            min=iter->data;
        }
        iter=iter->next;
     }
    return min;
}
queue  *pop_q(queue *root,int key){
    //delete given key from queue
    queue *iter;
    node_t *temp;
    iter=(queue*)malloc(sizeof(queue));
    iter->frontp=root->frontp;    
    if (iter->frontp->next==NULL)
    {
        temp=iter->frontp;
        root->frontp=NULL;
        free(temp);
        return root;   
    }
    else if (iter->frontp->data==key)
    {
        temp=iter->frontp;
        iter->frontp=iter->frontp->next;
        root->frontp=iter->frontp;
        free(temp);
        return root;
            
    }
    else
    {
        while (iter->frontp->next!=NULL)
        {
            if (iter->frontp->next->data==key)
            {
                temp=iter->frontp->next;
                iter->frontp->next=iter->frontp->next->next;
                free(temp);
                break;
            }
            iter->frontp=iter->frontp->next;
        }
    }
    return root;
}
void print_bst_min(bst * bst_,int flag,int *min){
    /*return min value of bst in order*/
    if (bst_==NULL) // base case
    {
        return;//stop;
    }
    else
    {
        print_bst_min(bst_->leftp,flag,min);
        if (bst_->data > (*min) && flag==(*min))
        {
            *min=bst_->data;
        }
        print_bst_min(bst_->rightp,flag,min);
    }
    
}
void print_bst_traverse(bst * bst_,bst *bst2,int flag,int *min){
    if (bst_==NULL) // base case
    {
        
        return;//stop;
    }
    else//
    {
        
        print_bst_traverse(bst_->rightp,bst2,flag,min);
        if (!(*min>=bst_->data))
        {  
            printf("%d ",bst_->data); //print max value
            if (flag!= (*min)) flag=(*min);
            print_bst_min(bst2,flag,min); //find min value of bst
            flag=(*min);
            if ((*min)!=bst_->data)
            {
                printf("%d ",flag); //print min value
            }
        }
        print_bst_traverse(bst_->leftp,bst2,flag,min);
       
    }
    
}
