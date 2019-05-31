#include<stdio.h>
#include<stdlib.h>
struct member{
    int id;
    char *name;
    int age;
    struct member *next;
};
int main(){
    int i,a[5];
    FILE *fptr;
    fptr=fopen("akif.bin","wb");
    struct member *temp,*iter;
    temp=(struct member*)malloc(sizeof(struct member));
    iter=temp;
    for ( i = 0; i < 5; i++)
    {
        temp->id=i;
        temp->age=i+5;
        temp->name="empty";
        temp->next=(struct member*)malloc(sizeof(struct member));
        temp=temp->next;
    }
    temp=NULL;
    while (iter!=NULL)
    {
        
        fwrite(&(iter->id),sizeof(int),1,fptr);
        //fwrite(&(iter->name),sizeof(char),4,fptr);
        fwrite(&(iter->age),sizeof(int),1,fptr);
        iter=iter->next;
    }
    fclose(fptr);
    fptr=fopen("akif.bin","rb");
    for ( i = 0; i < 5; i++)
    {
        fread(&a[i],sizeof(int),1,fptr);
        printf("%d\n",a[i]);
    }
    
}



