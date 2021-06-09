#include<stdio.h>
#include<math.h>
#include "Complex.h"

int maxIter =80;


int maxiteration(Complex z){
	int Iter=0;
	Complex result;
	result.a=0;
	result.b=0;
	while(Iter < maxIter && cmodulus(&result) <= 2){
		Complex z_2 = cmultiply(&result,&result);
		result = cadd(&z_2,&z);
		Iter +=1;
	}
	return Iter;
}

int main(){
	double RSTART=-2;
	double REND=1;
	double ISTART=-1;
	double IEND=1;
	double RSCALE= REND -RSTART;
	double ISCALE= IEND -ISTART;
	int DIMX = 1280;
	int DIMY = 720;
	FILE* image = fopen("image.ppm","wb");
	FILE* diag = fopen("diag.txt","w");
	fprintf(image,"P6\n%d %d\n255\n",DIMX,DIMY);
	for(int j=0; j<DIMY; j++){
		for(int i=0; i<DIMX;i++){
			Complex current;
			current.a = RSTART +   (double)i * RSCALE/DIMX ;
			current.b = ISTART + (double)j  * ISCALE/DIMY;
			double maxCurrent = (double)maxiteration(current);
			char colour = round( (maxCurrent/maxIter)*255) ;
			unsigned char pixel[]={colour,colour,colour};
			fwrite(pixel,1,3,image);
		}
		fprintf(diag,"\n");
		/* fprintf(image,"\n");*/

	}
	fclose(image);
	fclose(diag);
	return 0;

}
