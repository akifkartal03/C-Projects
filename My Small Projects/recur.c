#include <stdio.h>
void read_file(char arr[10][20],int names_location[10],char location[3][10]);
int print_str(char arr[10][20],int size);
void find_first_occurrence(const char str[10][20]);
int main(){
   // ={"Ali Veli","Ahmet Selvi","Melike Selen","Mehmet Yigit","Selen Karayel"};
   // ={"istanbul","Ankara","izmir"};
    int names_location[10];
    char names[10][20]={"Ali Veli","Ahmet Selvi","Melike Selen","Mehmet Yigit","Selen Karayel"};;
    char location[3][10];
    char str[]="deneme";
    int result;
    char ch='e';
    find_first_occurrence(names);
    //printf("%d\n", result);
    //read_file(names,names_location,location);
    //print_str(names,5); 
}
int print_str(char arr[10][20],int size){

    if (size==0)
        return 0;
    else{
        printf("%s\n", arr[size-1]);
        print_str(arr,size-1);
        
    }
}
void read_file(char arr[10][20],int names_location[10],char location[3][10]){
    FILE *f;
    int i=0;
    f=fopen("Names.txt","r");
    while(fgets(arr[i],20,f));
    fclose(f);
    f=fopen("Location.txt","r");
    while(fgets(arr[i],20,f));
    fclose(f);
    f=fopen("NamesLocations.txt","r");
    while(fgets(arr[i],20,f));
    fclose(f);


}
void find_first_occurrence(const char str[10][20]){

    if (str[0][0]=='\0') return;
    else{
        find_first_occurrence(&str[1]);
        printf("%s\n",str[0]);
    }

}
