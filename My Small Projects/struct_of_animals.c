#include<stdio.h>
#include<string.h>
typedef struct{
	char name[20];
	char species[20];
	int lenght;
	int weight;
	char natural_habitat[20];
}animal;
void fill_struct(animal table[4]);
void lenght_info(animal table[4],int *max,int *min,double *avarage);
void filter(animal table[4],animal filtered_animal[4]);
void change_weight(animal *animal_to_change);
void print_a(animal table[4]);
int main(){
	animal table[4];
	animal filtered_animal[4];
	int max,min;
	double avarage;
	fill_struct(table);
	lenght_info(table,&max,&min,&avarage);
	printf("min:%d max:%d ave:%f\n", table[min].lenght,table[max].lenght,avarage);
	change_weight(&table[3]);
	printf("%d\n", table[1].weight);
	filter(table,filtered_animal);
	print_a(filtered_animal);


}
void fill_struct(animal table[4]){

	strcpy(table[0].name,"lion");
	strcpy(table[1].name,"dolp");
	strcpy(table[2].name,"shark");
	strcpy(table[3].name,"wolf");
	strcpy(table[0].species,"mammals");
	strcpy(table[1].species,"mammals");
	strcpy(table[2].species,"fish");
	strcpy(table[3].species,"mammals");
	strcpy(table[0].natural_habitat,"savannah");
	strcpy(table[1].natural_habitat,"oceans");
	strcpy(table[2].natural_habitat,"oceans");
	strcpy(table[3].natural_habitat,"forest");
	table[0].lenght=200;
	table[1].lenght=300;
	table[2].lenght=450;
	table[3].lenght=160;
	table[0].weight=130;
	table[1].weight=180;
	table[2].weight=250;
	table[3].weight=60;

}
void lenght_info(animal table[4],int *max,int *min,double *avarage){

	int mn=1,mx=1;
	double sum=0.0,ave;
	for (int i = 0; i < 4; ++i)
	{
		if (table[i].lenght<table[mn].lenght)
		{
			mn=i;
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		if (table[i].lenght>table[mx].lenght)
		{
			mx=i;
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		sum=sum+table[i].lenght;
	}
	ave=sum/4.0;
	*min=mn;
	*max=mx;
	*avarage=ave;
}
void filter(animal table[4],animal filtered_animal[4]){

	int k=0;
	for (int i = 0; i < 4; ++i)
	{
		if (strcmp(table[i].species,"mammals")==0)
		{
			if (table[i].weight>=100)
			{
				if (strcmp(table[i].natural_habitat,"oceans")!=0){
					filtered_animal[k]=table[i];
					k++;

				}
			}
		}
	}

}
void change_weight(animal *animal_to_change){
	int w;
	printf("enter a weight\n");
	scanf("%d",&w);
	animal_to_change->weight=w;
}
void print_a(animal table[4]){

	printf("name | species | lenght | weight | natural \n");
	printf("-----------------------------------------------\n");
	for (int i = 0; i < 4; ++i)
	{
		printf("%s  %s     %d      %d      %s\n", table[i].name, table[i].species, table[i].lenght, table[i].weight, table[i].natural_habitat);
		printf("\n");
	}
}

