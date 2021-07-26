#include<iostream>
#include<vector>
#include<raylib.h>

template <typename T>
void printgrid( std::vector<std::vector<T> > GRID, int LENGTH){
	for(int i = 0; i<LENGTH;i++){
		std::cout<<"\n";
		for(int j=0; j<LENGTH; j++){
			std::cout<<GRID[i][j];
		}
	}
	std::cout<<"\n";
}

template <typename T>
void scopygrid( const std::vector<std::vector<T> > GRID_SOURCE,  std::vector<std::vector<T>> & GRID_DEST,int LENGTH)
{
	for(int i=0; i<LENGTH;i++){
		for(int j=0; j<LENGTH;j++)
		{
			GRID_DEST[i][j]=GRID_SOURCE[i][j];
		}
	}
}

void nextgn( std::vector< std::vector<int>>& GRID_ORIG, const std::vector<std::vector<int> >& GRID_REF, int LENGTH){
	for(int i=1; i< LENGTH-1;i++){
		for(int j=1; j < LENGTH-1; j++){
			int ALIVE_NEIGBOURS=0;
			for(int up=-1; up<=1;up++)
			{
				for(int down=-1; down<=1;down++)
				{
					ALIVE_NEIGBOURS +=GRID_REF[i+up][j+down];

				}

			}
			ALIVE_NEIGBOURS-=GRID_REF[i][j];

			if(GRID_REF[i][j]==1 && ALIVE_NEIGBOURS <2 )
			{
				GRID_ORIG[i][j]=0;
			

			}else if(GRID_REF[i][j]==1 && ALIVE_NEIGBOURS >3)
			{
				GRID_ORIG[i][j]=0;
			}
			else if (GRID_REF[i][j]==0 && ALIVE_NEIGBOURS==3){
				GRID_ORIG[i][j]=1;
			}
			else{
				GRID_ORIG[i][j]=GRID_REF[i][j];
			}

		}
	}
}
int main(){
	int N =7;
	std::vector<std::vector<int> >grid_1(N, std::vector<int>(N,0));
	std::vector<std::vector<int> >grid_2(N, std::vector<int>(N,0));
	grid_1[3][2]=1;
	grid_1[3][3]=1;
	grid_1[3][4]=1;
	scopygrid(grid_1,grid_2,N);
	printgrid(grid_1,N);
	nextgn(grid_1,grid_2,N);
	scopygrid(grid_1,grid_2,N);
	printgrid(grid_1,N);
//	const int SCREENWIDTH=N;
//	const int SCREENHEIGHT=N;
//	InitWindow(SCREENWIDTH,SCREENHEIGHT,"WINDOW");
//	SetTargetFPS(1);

//	while(!WindowShouldClose()){
//		nextgn(grid_1,grid_2,N);
//		scopygrid(grid_1,grid_2,N);
//		printgrid(grid_1,N);
//		BeginDrawing();
//		ClearBackground(WHITE);
//		for(int i=0;i<N;i++){
//			for(int j=0;j<N;j++){
//				if(grid_1[i][j]==1)
//				{
//					DrawPixel(i,j,RED);
//				
//				}
//			}
//		}
//		EndDrawing();
//	}
	return 0;

}

