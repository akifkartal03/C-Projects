 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 void reverse_str(char str[]);  
 char *f(char str[],int chr);
 int main(){
     char *adress;
     char str[20]="akif kartal";
     reverse_str(str);
     int chr=107;//k
     adress=f(str,chr);
     printf("%s\n",adress);

 }
 char *f(char str[],int chr){

      char *adress=(char*)malloc(sizeof(char)*30);//keep the addres of character
      if (str[0]=='\0')
      {
          return adress;
      }
      else
      {
          if (chr==(int)str[0])
          {
              sprintf(adress, "%p",&str[0]);//in order to copy adress of character to dynamic address array
              return adress;
          }
         f(&str[1],chr);//call function again 
      }
      
 }
  void reverse_str(char str[]){
      int i;
      int size;
      char temp;
      size=strlen(str);
      for ( i = 0; i < size/2; i++)
      {
          temp=str[i];
          str[i]=str[size-(i+1)];
          str[size-(i+1)]=temp;
      }
      
  }