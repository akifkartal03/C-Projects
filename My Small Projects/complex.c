#include<stdio.h>
typedef struct {
	int real;
	int imag;
}CN;
CN add_complex(CN a, CN b);
CN sub_complex(CN a, CN b); 
int main(){
	
	CN k ,d,add,sub;
	printf("Enter 1st complex number: ");
	scanf("%d%d", &k.real , &k.imag);
	printf("Enter 2st complex number: ");
	scanf("%d%d", &d.real , &d.imag);
	add=add_complex(k,d);
	sub=sub_complex(k,d);
	printf("addition: %d + %di\n ",add.real,add.imag);
	printf("subraction: %d  %di\n",sub.real,sub.imag);

}
CN add_complex(CN a, CN b){

	CN result;
	result.real=a.real+b.real;
	result.imag=a.imag+b.imag;
	return result;
}
CN sub_complex(CN a, CN b){

	CN result;
	result.real=a.real-b.real;
	result.imag=a.imag-b.imag;
	return result;
} 
