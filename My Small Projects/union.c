#include <stdio.h>
#define PI 3.14159

/* Types defining the components needed to represent each shape. */
typedef struct {
 double area,
 circumference,
 radius;
 } circle_t;

 typedef struct {
 double area,
 perimeter,
 width,
 height;
} rectangle_t;

 typedef struct {
 double area,
perimeter,
side;
} square_t;

 /* Type of a structure that can be interpreted a different way for
 each shape */
 typedef union {
 circle_t circle;
 rectangle_t rectangle;
 square_t square;
} figure_data_t;
/* Type containing a structure with multiple interpretations along with
 * a component whose value indicates the current valid interpretation */
 typedef struct {
 char shape;
 figure_data_t fig;
} figure_t;

figure_t get_figure_dimensions(void);
figure_t compute_area(figure_t object);
figure_t compute_perim(figure_t object);
void print_figure(figure_t object);
int main(){

	figure_t onefig;

	printf("Area and Perimeter Computation Program\n");

	
	onefig = get_figure_dimensions(); 
	onefig = compute_area(onefig);
	onefig = compute_perim(onefig);
	print_figure(onefig);
	

	return (0);

}
figure_t get_figure_dimensions(void){

	figure_t obje;
	printf("enter  a obje: ");
	scanf("%c",&obje.shape);
	switch(obje.shape){
	case 'C':
		printf("enter a radius: ");
		scanf("%lf",&obje.fig.circle.radius);
		break;
	case 'R':
		printf("enter a height: ");
		scanf("%lf",&obje.fig.rectangle.height);
		printf("enter a wight: ");
		scanf("%lf",&obje.fig.rectangle.width);
		break;
	default:
		printf("asdasdasd\n");
	}
	return (obje);
}
figure_t compute_area(figure_t object){

	switch(object.shape){
	case 'C':
		object.fig.circle.area=object.fig.circle.radius*PI*object.fig.circle.radius;
		break;
	
	case 'R':
		object.fig.rectangle.area=object.fig.rectangle.height*object.fig.rectangle.width;
		break;
	default:
		printf("asdasdasd\n");
	}
	return (object);
}
figure_t compute_perim(figure_t object){

	switch(object.shape){
	case 'C':
		object.fig.circle.circumference=object.fig.circle.radius*PI*2;
		break;
	
	case 'R':
		object.fig.rectangle.perimeter=(object.fig.rectangle.height+object.fig.rectangle.width)*2;
		break;
	default:
		printf("asdasdasd\n");
	}
	return (object);
}
void print_figure(figure_t object){

	printf("area of circle: %f\n",object.fig.circle.area);
	printf("area of rectangle: %f\n",object.fig.rectangle.area);
	printf("circumference of circle: %f\n",object.fig.circle.circumference);
	printf("perimeter of rectangle: %f\n",object.fig.rectangle.perimeter);
}
