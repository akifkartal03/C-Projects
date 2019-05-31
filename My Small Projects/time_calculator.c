#include<stdio.h>
typedef struct{
	int second;
	int minute;
	int hour;

}TIME;
void diffrence_time(TIME start,TIME stop,TIME *diff);
int main(){
	TIME start,stop,elaps;
	printf("statrt time(h m s): ");
	scanf("%d%d%d", &start.hour , &start.minute,&start.second);
	printf("stop time(h m s): ");
	scanf("%d%d%d", &stop.hour ,&stop.minute,&stop.second);
	diffrence_time(start,stop,&elaps);
	printf("Time elapsed: %d:%d:%d - %d:%d:%d = %d:%d:%d\n",start.hour , start.minute,start.second,stop.hour ,stop.minute,stop.second ,elaps.hour, elaps.minute,elaps.second);
	
	

}
void diffrence_time(TIME start,TIME stop,TIME *diff){

	diff->hour=start.hour-stop.hour;
	diff->minute=start.minute-stop.minute;
	diff->second=start.second-stop.second;
}