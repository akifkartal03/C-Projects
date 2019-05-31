#include<stdio.h>
typedef struct{
	int x;
	int y;
	char shape;
}pixel;
void fill_canvas(pixel canvas[8][14]);
void show_canvas(pixel canvas[8][14]);
void find_shape(pixel canvas[8][14],char *shape);
int sizeofstr(char str[]);
int main(){
	char shp[14]="(-)";
	pixel canvas[8][14];
	fill_canvas(canvas);
	show_canvas(canvas);
	find_shape(canvas,shp);

}
void fill_canvas(pixel canvas[8][14]){
	int i ,j;
	for (i = 0; i < 8; ++i)
	{
		for (j = 0; j < 14; ++j)
		{
			if (i==0 || i==7)
			{
				canvas[i][j].shape='.';
			}
			else if (i==1)
			{
				if (j==0 || j==13)
				{
					canvas[i][j].shape='.';
				}
				else{
					canvas[i][j].shape='S';
				}
			}
			else if (i==2)
			{
				if (j==0 || j==13)
				{
					canvas[i][j].shape='.';
				}
				else if(j==1 || j==12){
					canvas[i][j].shape='|';
				}
				else if(j==2 ||j==6 ||j==7 ||j==11){
					canvas[i][j].shape=' ';
				}
				else if(j==3 ||j==4 ||j==5 ||j==8||j==9 ||j==10){
					canvas[i][j].shape='-';
				}
				
			}
			else if (i==3)
			{
				if (j==0 || j==13)
				{
					canvas[i][j].shape='.';
				}
				else if(j==1 || j==12){
					canvas[i][j].shape='|';
				}
				else if(j==2 ||j==6 ||j==7 ||j==11){
					canvas[i][j].shape=' ';
				}
				else if(j==3 ||j==8 ){
					canvas[i][j].shape='(';
					
				}
				else if(j==5||j==10){
					canvas[i][j].shape=')';
				}
				else if(j==4||j==9){
					canvas[i][j].shape='-';
				}
			}
			else if (i==4)
			{
				
				if (j==0 || j==13)
				{
					canvas[i][j].shape='.';
				}
				else if(j==1 || j==12){
					canvas[i][j].shape='|';
				}
				else if(j==6){
					canvas[i][j].shape='/';
				}
				else if(j==7){
					canvas[i][j].shape='_';
				}
				else if(j==2||j==3 ||j==4 ||j==5 ||j==8||j==9 ||j==10||j==11){
					canvas[i][j].shape=' ';
				}
			}

			else if (i==5)
			{
				
				if (j==0 || j==13)
				{
					canvas[i][j].shape='.';
				}
				else if(j==1 || j==12){
					canvas[i][j].shape='|';
				}
				else if(j==4 ||j==5 ||j==6||j==7 ||j==8||j==9){
					canvas[i][j].shape='_';
				}
				else if(j==2||j==3 ||j==10||j==11){
					canvas[i][j].shape=' ';
				}

			}
			else if (i==6)
			{
				
				if (j==0 || j==13)
				{
					canvas[i][j].shape='.';
				}
				else if(j==1 || j==12){
					canvas[i][j].shape='|';
				}
				else if(j==2||j==3 ||j==10||j==11||j==4 ||j==5 ||j==6||j==7 ||j==8||j==9){
					canvas[i][j].shape='_';
				}
				
			}
		}
		
	}
}
void show_canvas(pixel canvas[8][14]){

	int i ,j;
	for (i = 0; i < 8; ++i)
	{
		for (j = 0; j < 14; ++j)
		{
			printf("%c", canvas[i][j].shape);
		}
		printf("\n");
	}	
}
void find_shape(pixel canvas[8][14],char *shape){
	int i ,j,k=0,size,count;
	pixel koor[4];
	for (i = 0; i < 8; ++i)
	{
		for (j = 0; j < 14; ++j)
		{
			if (k<=4)
			{
				if (canvas[i][j].shape==shape[0])
				{
					koor[k].x=i;
					koor[k].y=j;
					k++;
				}
			}
			
			
		}
		
	}
	if (shape[0]=='(' )
	{
		printf("x: %d y: %d\n",koor[0].x,koor[0].y );
  		printf("x: %d y: %d\n",koor[1].x,koor[1].y );
	}
	else if (shape[0]=='-')
	{
		printf("x: %d y: %d\n",koor[0].x,koor[0].y );
  		printf("x: %d y: %d\n",koor[3].x,koor[3].y );
	}
	else{
		printf("x: %d y: %d\n",koor[0].x,koor[0].y );
	}
  	

}
int sizeofstr(char str[]){


	int i;
	for (i = 0; str[i]!='\0'; ++i);
	return i;
	
}