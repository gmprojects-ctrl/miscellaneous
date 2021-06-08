#include<stdio.h>
#include"Complex.h"

int main(){
	Complex x;
	x.a=0.31;
	x.b=12.46;

	Complex y;
	y.a=249;
	y.b=1123;

	Complex z = cmultiply(&x,&y);
	Complex z1= cadd(&x,&y);
	printf(" %f  %f i",z.a,z.b);
	printf(" %f ",cmodulus(&x));
	printf(" %f  %f i",z1.a,z1.b);
	return 0;
}
