#include<iostream>
#include <raylib.h>
#include <vector>

void printgrid( std::vector<std::vector<int> > GRID, int LENGTH){
	for(int i = 0; i<LENGTH;i++){
		std::cout<<"\n";
		for(int j=0; j<LENGTH; j++){
			std::cout<<GRID[i][j];
		}
	}
	std::cout<<"\n";
}

void gridset( std::vector<std::vector<int>>& GRID, int LENGTH,int value){
	for(int i = 0; i<LENGTH;i++){
		for(int j=0; j<LENGTH; j++){
			GRID[i][j]=value;
		}
	}
}
void scopygrid( const std::vector<std::vector<int> > GRID_SOURCE,  std::vector<std::vector<int>> & GRID_DEST,int LENGTH)
{
	for(int i=0; i<LENGTH;i++){
		for(int j=0; j<LENGTH;j++)
		{
			GRID_DEST[i][j]=GRID_SOURCE[i][j];
		}
	}
}

void nextgn( std::vector< std::vector<int>>& GRID_ORIG,  std::vector<std::vector<int> >& GRID_REF, int LENGTH){
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



int main()
{
	// Defining Screen Size
	const int SCREENWIDTH =  1000;
	const int SCREENHEIGHT = 1000;

	// Window Configuration
	InitWindow(SCREENWIDTH, SCREENHEIGHT, "Conway's Game of Life");
	SetTargetFPS(60);

	// Block Size
	int BLOCK_LENGTH = 50;
	int WIDTH_BLOCKS = SCREENWIDTH/BLOCK_LENGTH;
	int ACTUAL_WIDTH_BLOCKS = WIDTH_BLOCKS+1;
	std::vector<std::vector<int>>BLOCK_BUFFER(ACTUAL_WIDTH_BLOCKS, std::vector<int>(ACTUAL_WIDTH_BLOCKS,0));
	std::vector<std::vector<int>>BLOCK_BUFFER_NEW(ACTUAL_WIDTH_BLOCKS, std::vector<int>(ACTUAL_WIDTH_BLOCKS,0));

	scopygrid(BLOCK_BUFFER,BLOCK_BUFFER_NEW,ACTUAL_WIDTH_BLOCKS);
	printgrid(BLOCK_BUFFER,ACTUAL_WIDTH_BLOCKS);
	



	// Timer
	double TIMER=GetTime();

	//Simstat
	
	bool SIMSTATE=false;


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
	if(IsKeyPressed(KEY_P)){
		SIMSTATE=!SIMSTATE;
	}
	    if(SIMSTATE){
		    if( GetTime()-TIMER>= 0.5 ){

		    nextgn(BLOCK_BUFFER,BLOCK_BUFFER_NEW,ACTUAL_WIDTH_BLOCKS);
		    //printgrid(BLOCK_BUFFER,ACTUAL_WIDTH_BLOCKS);
		    scopygrid(BLOCK_BUFFER,BLOCK_BUFFER_NEW,ACTUAL_WIDTH_BLOCKS);
		    TIMER=GetTime();
	    }
	    }else{
		    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		    {
			    int POSX=GetMouseX()/ BLOCK_LENGTH;
			    int POSY=GetMouseY()/ BLOCK_LENGTH;
			    BLOCK_BUFFER[POSX][POSY]=1;
			    scopygrid(BLOCK_BUFFER,BLOCK_BUFFER_NEW,ACTUAL_WIDTH_BLOCKS);
		    }
		    if(IsKeyPressed(KEY_C)){
			    gridset(BLOCK_BUFFER,ACTUAL_WIDTH_BLOCKS,0);
		    }

	    }
	    BeginDrawing();
	    ClearBackground(RAYWHITE);	
	    for(int i=0; i<ACTUAL_WIDTH_BLOCKS;i++){
		    for(int j=0;j<ACTUAL_WIDTH_BLOCKS;j++)
		    {
			    if(BLOCK_BUFFER[i][j]==1){
				    DrawRectangle(i*BLOCK_LENGTH,j*BLOCK_LENGTH,BLOCK_LENGTH,BLOCK_LENGTH,RED);
			    }
		    }
	    }
	    if(SIMSTATE){DrawText("SimState Activated",0,0,15,BLACK);}
	    EndDrawing();



    }

    CloseWindow();     

    return 0;
}
