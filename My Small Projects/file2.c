#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct room{
    int number,
        capacity,
        flor;

};
int main(){
    int i=0,b;
    FILE *fptr;
    char a[300];
    char ch;
    struct room rooms[28];
    fptr=fopen("rooms.txt","r");
    if (fptr==NULL)
    {
        printf("dosya bulunamadı...\n");
    }
    else{
        for ( ch=getc(fptr); ch!=EOF; ch=getc(fptr))
        {
            a[i]=ch;
            i++;
        }
        a[i]='\0';
        printf("%s",a);
       /* while (fscanf(fptr,"%[^\n]s",a)==1)
        {
            printf("%s",a);
            sscanf(a,"%d,%d,%d",&rooms[i].number,&rooms[i].capacity,&rooms[i].flor);
            i++;
        }*/
        
    }
    /*for ( i = 0; i < 28; i++)
    {
        printf("%d ",rooms[i].number);
    }*/
    

}