#include"../include/raylib.h"
#include"../include/MandelBrot.h"
#include<iostream>
#include<unistd.h>
int main(){
	const int RSTART=-2;
	const int REND= 2;
	const int ISTART=-1;
	const int IEND= 1;
	Complex start;
	start.a=0;
	start.b=0;
	int maxIter=80;
	Color color;
	constexpr int SCREEN_WIDTH{1280};
	constexpr int SCREEN_HEIGHT{720};
	InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT,"Main Window");
	SetTargetFPS(60);
	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(BLACK);
		double RSCALE= REND -RSTART;
		double ISCALE= IEND -ISTART;
		for(int j=0; j<SCREEN_WIDTH; j++){
			for(int i=0; i<SCREEN_HEIGHT;i++){
				Complex current;
				current.a = RSTART +   (double)i * RSCALE/SCREEN_WIDTH;
				current.b = ISTART + (double)j  * ISCALE/SCREEN_HEIGHT;
				double maxCurrent = (double) maxiteration(&current,&start,maxIter);
				char colour = round( (maxCurrent/maxIter)*255) ;
				color.r=colour;
				color.g=colour;
				color.b=colour;
				color.a=255;
				DrawPixel(SCREEN_HEIGHT-i,j,color);
                }
			sleep(1);
		}
     EndDrawing();
	}
}

