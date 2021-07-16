#ifndef MANDELBROT_H
#define MANDELBROT_H
#include "Complex.h"
int maxiteration(Complex* z,Complex* start,int maxIter);
int RenderImage(double RSTART,double REND, double ISTART, double IEND, int DIMX, int DIMY, int power,int maxIter, Complex start);
#endif
