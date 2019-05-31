#include<stdio.h>
#include<string.h>
void word_counter(char text[],int counters[150],char words[150][20]);
int size(char words[150][20]);
int main(){
	char text[300]="abcd kalmn örs kalmn abcd orsc örs abcd akif kartal akif abcd";
	int counters[150],siz;
	char words[150][20];
	word_counter(text,counters,words);
	siz=size(words);
	for (int i = 0; i<siz; ++i)
	{
		printf("there are %d '%s' in the text.\n",counters[i],words[i]);
	}
}
void word_counter(char text[],int counters[150],char words[150][20]){

	char temp[20];
	int j=0,i,k,sizee,flag=0;
	for (i = 0;text[i]!='\0' ; ++i)
	{
		
		if (text[i]==' ')
		{
			temp[0]='\0';
			flag=0;
			sizee=size(words);
			strncpy(temp,&text[j],i-j);
			temp[i-j]='\0';
			j=i+1;
			for (k = 0; k<sizee+1; ++k)
			{
				if (strcmp(temp,words[k])==0)
				{
					counters[k]++;
					flag=1;
				}
				
			}
			if (flag!=1)
			{
				strcpy(words[sizee],temp);
				counters[sizee]++;
			}

		}
		
	}
}

int size(char words[150][20]){
	int i;
	for (i = 0; words[i][0]!='\0'; ++i);
	return i;

}