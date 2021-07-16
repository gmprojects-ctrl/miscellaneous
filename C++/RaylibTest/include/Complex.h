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
Complex cadd(Complex* x, Complex* y);
/* Multiplies two complex numbers together*/
Complex cmultiply(Complex* x, Complex* y);

/* Finds the modulus of a complex number
 */
double cmodulus(Complex* x);
#endif
