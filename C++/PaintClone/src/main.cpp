#include<iostream>
#include <raylib.h>
#include <vector>



typedef struct Shape{
    int SHAPE_TYPE;
    Vector2 POSITION;
    float LENGTH;
    Color COLOR;
}Shape;

Shape DEFAULT={0,{0,0} ,0, {0,0,0,0} };



int main()
{
	// Defining Screen Size
	const int SCREENWIDTH =  640;
	const int SCREENHEIGHT = 480;

	// Window Configuration
	InitWindow(SCREENWIDTH, SCREENHEIGHT, "Paint Clone ");
	SetTargetFPS(60);
    SetWindowMinSize(SCREENWIDTH,SCREENHEIGHT);

    // Brush Size Default

    float BrushSize = 10;
    Color ActiveColour = {255,0,0,255};



    // Shape History;

    std::vector<Shape> SHAPE_HISTORY;

    // Main loop
    while (!WindowShouldClose()){    // Detect window close button or ESC key
        if(WindowShouldClose()){
            break;
        }
        int MOUSE_POSX= GetMouseX();
        int MOUSE_POSY= GetMouseY();
        if(IsKeyPressed(KEY_C)){
            SHAPE_HISTORY.clear();

        };
        if(IsKeyPressed(KEY_EQUAL)){
         ActiveColour = {0,0,255,255};
        }
        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
            if(MOUSE_POSX<0){MOUSE_POSX=BrushSize;}
            if(MOUSE_POSY<0){MOUSE_POSY=BrushSize;}
            if(MOUSE_POSX>GetScreenWidth()){MOUSE_POSX=GetScreenWidth()-BrushSize;};
            if(MOUSE_POSY>GetScreenHeight()){MOUSE_POSY=GetScreenHeight()-BrushSize;};
            SHAPE_HISTORY.push_back({1,{(float) MOUSE_POSX, (float) MOUSE_POSY},BrushSize,ActiveColour});

        }
        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
         SHAPE_HISTORY.push_back(DEFAULT);
        }
	    BeginDrawing();
	    ClearBackground(RAYWHITE);
//        DrawText("Right Click on a block to make it dead",SCREENWIDTH-11*BLOCK_LENGTH,BLOCK_LENGTH,24,BLACK);
//        DrawText("Press c to clear",SCREENWIDTH-11*BLOCK_LENGTH,2*BLOCK_LENGTH,24,BLACK);
//        DrawText("Press p to play",SCREENWIDTH-11*BLOCK_LENGTH,3*BLOCK_LENGTH,24,BLACK);
//	    DrawText("This Executable is Working", 0 ,0 ,12, BLACK );

        if(IsKeyDown(KEY_LEFT_BRACKET)){
            if(BrushSize!=1){
            BrushSize-=1;
            }
            DrawCircleLines(MOUSE_POSX,MOUSE_POSY,BrushSize,BLACK);
            }
        if(IsKeyDown(KEY_RIGHT_BRACKET)){
            if(BrushSize!=50){
            BrushSize+=1;
            }
            DrawCircleLines(MOUSE_POSX,MOUSE_POSY,BrushSize,BLACK);
        }
        for(unsigned int i = 0 ; i < SHAPE_HISTORY.size(); i++ ){
            if( SHAPE_HISTORY[i].SHAPE_TYPE==1){
             DrawCircleV(SHAPE_HISTORY[i].POSITION,SHAPE_HISTORY[i].LENGTH,SHAPE_HISTORY[i].COLOR);
             if( i> 0){
                if(SHAPE_HISTORY[i-1].SHAPE_TYPE !=0){

                DrawLineEx(SHAPE_HISTORY[i-1].POSITION,SHAPE_HISTORY[i].POSITION,SHAPE_HISTORY[i].LENGTH*2,SHAPE_HISTORY[i].COLOR);
                }
            }

            }

        }



        DrawText("Press C to Clear Image ",0,0,24,BLACK);
        EndDrawing();

    }

    CloseWindow();     

    return 0;
}
