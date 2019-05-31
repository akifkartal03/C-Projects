#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct lesson{
    char code[35];
    char name[35];
    char class[35];
    int city;
    double credit;
    
    //struct lesson *prev; 

};
struct que{
    struct lesson *les;
    int curser;
    //struct lesson *next;
    //struct lesson *prev; 

};
void fill_quee(char filename[15],struct que **course);
struct lesson generate(char *line);
void add_q(struct que *lesson ,struct lesson item);
int main(){
    struct que *course=NULL;
    char filename[15]="file.txt";
    fill_quee(filename,&course);
    
}
void fill_quee(char filename[15],struct que **course){
    char code[35];
    char name[35];
    char class[35];
    int city,i=0;
    double credit;
    FILE *fptr;
    fptr=fopen(filename,"r");
    if (fptr==NULL)
    {
        printf("asdasda");
    }
    struct que *newp;
    char a[128];
    newp=(struct que *)malloc(sizeof(struct que));
    newp->les=(struct lesson *)malloc(sizeof(struct lesson)*5);
    while ((fgets(a,128,fptr)))
    {
        
        sscanf(a,"%s,%s,%s,%d,%lf",code,name,class,&city,&credit);
        strcpy(newp->les[i].code,code);
        strcpy(newp->les[i].name,code);
        strcpy(newp->les[i].class,code);
        //cty=atoi(city);
        //cred=atoi(credit);
        newp->les[i].city=city;
        newp->les[i].credit=credit;
        i++;
    }
    printf("adasd");
}
struct lesson generate(char *line){

    char code[35];
    char name[35];
    char class[35];
    int city,i=0;
    double credit;
    FILE *fptr;
    fptr=fopen("file.txt","r");
    if (fptr==NULL)
    {
        printf("asdasda");
    }
    struct lesson newp;
    char a[128];
   
    while ((fgets(a,128,fptr)))
    {
        
        sscanf(a,"%s,%s,%s,%d,%lf",code,name,class,&city,&credit);
        strcpy(newp.code,code);
        strcpy(newp.name,code);
        strcpy(newp.class,code);
        newp.city=city;
        newp.credit=credit;
    }
    return newp;

}
void add_q(struct que *lesson ,struct lesson item){
    

}

