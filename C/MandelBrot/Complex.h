#ifndef COMPLEX_H
#define COMPLEX_H

#include<stdio.h>
#include<math.h>
/* Defines the Complex Number as a struct
 * Complex number is in the form a+ib
 */
typedef struct Complex{
	double a;
	double b;
}Complex;

/* Adds two complex numbers together
 *
 */
Complex cadd(Complex* x, Complex* y){
	Complex z;
	z.a=x->a + y->a;
	z.b=x->b +y->b;
	return z;
}
/* Multiplies two complex numbers together*/
Complex cmultiply(Complex* x, Complex* y){
	Complex z;
	z.a = x->a * y->a - x->b * y->b;
	z.b= x->a * y->b + y->a * x->b;
	return z;

}
/* Finds the modulus of a complex number
 */
double cmodulus(Complex* x){
	double modulus = x->a * x->a + x->b * x->b;
	return sqrt(modulus);
}
#endif
