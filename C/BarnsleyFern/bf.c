#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/* Defining Random Numbers */
typedef struct Pixel{
	unsigned char r;
	unsigned char g;
	unsigned char b;
}Pixel;

/* Changing the Pixel Value */
void ChangePixel( Pixel* a, unsigned char* colour ){
	a->r=*(colour);
	a->g=*(colour+1);
	a->b=*(colour+2);
}
/* Defining the colours */
unsigned char red[] = {255,0,0};

/* Main Function */
int main(){

	/* Defining our x-y plane*/
	double X_MAX = 3;
	double X_MIN = -3;
	double Y_MAX = 10;
	double Y_MIN = 0; 
	int DIMX = 700;
	int DIMY = 1100;

	double X_SCALE = DIMX / (X_MAX - X_MIN);
	double Y_SCALE = DIMY / (Y_MAX - Y_MIN);
	double x = 0;
	double y=0;

	/* Coordinates of (0,0) on our Image */
	int X_CENTRE = DIMX/2;
	int Y_CENTRE = DIMY;


	/* Definining our PixelMap */
	Pixel** pixelmap = (Pixel**) malloc(sizeof(Pixel*) * DIMX);
	if(pixelmap == NULL){
		exit(-1);
	}
	for(int i=0; i < DIMX; i++){
		pixelmap[i]= (Pixel*) malloc(sizeof(Pixel)*DIMY);
		if(pixelmap[i] == NULL){
			exit(-1);
		}
	}
	/* Setting our image white */
	for(int i =0; i <DIMX;i++){
		for(int j=0; j<DIMY;j++){
			pixelmap[i][j].r=0;
			pixelmap[i][j].g=0;
			pixelmap[i][j].b=0;
		}
	}
	ChangePixel(&pixelmap[X_CENTRE-1][Y_CENTRE-1],red);
	for(int i=0; i<1000000;i++){
		int X_COORD = round(x*X_SCALE + X_CENTRE);
		int Y_COORD = round(y*Y_SCALE + Y_CENTRE);
/*
 *   Junk Code that checks if the point are out of bounds
 *
 *              if (X_COORD>DIMX){
			X_COORD=DIMX;
		}
		if (X_COORD<1){
			X_COORD=1;
		}
		if (Y_COORD>DIMY){
			Y_COORD=DIMY;
		}
		if(Y_COORD<1){
			Y_COORD=1;
			}
*/
		ChangePixel(&pixelmap[X_COORD-1][Y_COORD-1],red);
		int r = rand() % 1000;
		double x_n = x;
		double y_n = y;
		if( r < 10)
		{
			x=0;
			y =0.16 * y_n;
		}
		else if( r< 860)
		{
			x = 0.85 * x_n + 0.04 * y_n;
			y = -0.04 * x_n + 0.85 * y_n + 1.6;

		}else if ( r< 930){
			x = 0.20 * x_n - 0.26 * y_n;
			y = 0.23* x_n + 0.22 * y_n +1.6;

		}
		else
		{
			x = -0.15 * x_n + 0.28 * y_n;
			y = 0.26 * x_n + 0.24 * y_n + 0.44;


		}
	}
	/* Writing the Image file
	 * NOTE: The image is flipped so the fern points to the right
	 */
	FILE* fern = fopen("fern.ppm","wb");
	fprintf(fern,"P6\n%d %d \n255\n",DIMX,DIMY);
	for(int j=DIMY-1 ; j >= 0;j--){
		for(int i=0; i< DIMX;i++){
			unsigned char pixel[]={ pixelmap[i][j].r, pixelmap[i][j].g, pixelmap[i][j].b};
			fwrite(pixel,1,3,fern);
		}
	}
	fclose(fern);
	free(pixelmap);
	system("convert fern.ppm fern.png");
	system("rm fern.ppm");
	return 0;
}

