#include<stdio.h>
#include<math.h>
#include "Complex.h"
/*
 * Julia Set Generator
 * ___________________
 *
 * Version 1
 * 
 */



int maxIter =80; /* Defining the MaxIterations */

/* This function takes in a value of z and c and returns the amount of
 * iterations to check for convergence. 
 * If the iteration doesn't converge it will return maxIter
 */

int maxiteration(Complex* start,Complex* c){
	int Iter=0;
	Complex result;
	result.a=start->a;
	result.b=start->b;
	while(Iter < maxIter && cmodulus(&result) <= 2){		
		result = cmultiply(&result,&result);
		result = cadd(&result,c);
		Iter +=1;
	}
	return Iter;
}
int RenderImage(double RSTART,double REND, double ISTART, double IEND, int DIMX, int DIMY, int power, Complex c){
	static int number =0; /* Used to check if the function is called repeatedly */
	double RSCALE= REND -RSTART; /* Scale of the Real Axis*/
	double ISCALE= IEND -ISTART; /* Scale of the Imaginary Axis */
	char imagename[100]; 
	sprintf(imagename,"image%d.ppm",number);
	FILE* image = fopen(imagename,"wb");
	FILE* diag = fopen("diag.txt","a");
	fprintf(image,"P6\n%d %d\n255\n",DIMX,DIMY);
	for(int j=0; j<DIMY; j++){
		for(int i=0; i<DIMX;i++){
			Complex current;
			current.a = RSTART +   (double)i * RSCALE/DIMX ;
			current.b = ISTART + (double)j  * ISCALE/DIMY;
			double maxCurrent = (double) maxiteration(&current,&c);
			char colour = round( (maxCurrent/maxIter)*255) ;
			unsigned char pixel[]={colour,colour,colour};
			fwrite(pixel,1,3,image);
		}
		fprintf(diag,"\n");
		/* fprintf(image,"\n");*/

	}
	fclose(image);
	fclose(diag);
	number++;
	return 0;
}



int main(){
	Complex c;
	c.a=-2;
	c.b=0;
	RenderImage(-2,2,-1,1,1280,720,2,c);	
	return 0;

}
