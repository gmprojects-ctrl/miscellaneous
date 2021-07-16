#include<stdio.h>
#include<math.h>
#include "Complex.h"
#include "MandelBrot.h"

int maxiteration(Complex* z,Complex* start,int maxIter){
	int Iter=0;
	Complex result;
	result.a=start->a;
	result.b=start->b;
	while(Iter < maxIter && cmodulus(&result) <= 2){
		result = cmultiply(&result,&result);	
		result = cadd(&result,z);
		Iter +=1;
	}
	return Iter;
}
int RenderImage(double RSTART,double REND, double ISTART, double IEND, int DIMX, int DIMY, int power,int maxIter, Complex start){
	static int number =0;
	double RSCALE= REND -RSTART;
	double ISCALE= IEND -ISTART;
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
			double maxCurrent = (double) maxiteration(&current,&start,maxIter);
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

