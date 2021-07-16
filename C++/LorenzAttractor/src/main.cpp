#include<iostream>
#include<raylib.h>
#include<vector>
class LorenzAttractor{
	public:
		std::vector<Vector3>poslist ;
		int storelist=0;
		LorenzAttractor(Vector3 initialposition, Vector3 constants){
			CONSTS = constants;
			OBJPOSITION=initialposition;
			
		}
 
		Vector3 generateposition(float time){
			float x = OBJPOSITION.x+ time * ( CONSTS.x * (OBJPOSITION.y -OBJPOSITION.x) );
			float y = OBJPOSITION.y+ time * (OBJPOSITION.x * ( CONSTS.y- OBJPOSITION.z) -OBJPOSITION.y);
			float z = OBJPOSITION.z+ time * ( OBJPOSITION.x * OBJPOSITION.y - CONSTS.z * OBJPOSITION.z);
			OBJPOSITION={x,y,z};
			storelist++;
			if(storelist>1000){
				 poslist.erase(poslist.begin());
				 storelist=0;
			}
			poslist.push_back(OBJPOSITION);
			return OBJPOSITION;
		}

		void printposition(){
			std::cout<< OBJPOSITION.x << "\t" <<OBJPOSITION.y <<"\t" << OBJPOSITION.z << std::endl;
		}

	private:
		Vector3 OBJPOSITION;
		Vector3 CONSTS;
};



int main(){
	// Define Screen Size
	const int SCREENWIDTH = 800;
	const int SCREENHEIGHT = 600;

	// Initialise the Windo
	
	InitWindow(SCREENWIDTH,SCREENHEIGHT,"Lorenz Attractor");

	// Define the 3D camera;
	Camera3D camera = { 0 };
	camera.position = (Vector3){30.0f,30.0f,30.0f};
	camera.target=(Vector3) {0.0f,0.0f,0.0f};
	camera.up={0.0f,1.0f,0.0f};
	camera.fovy=45.0f;
	camera.projection=CAMERA_PERSPECTIVE;
	SetCameraMode(camera,CAMERA_FREE);



	// Setting up the LorenzAttractor
	

	Vector3 INITPOS = {1.0f,1.0f,1.0f};
	Vector3 CONSTS ={10.0f,28.0f,(float) 8/3};

	LorenzAttractor LA(INITPOS,CONSTS);
	// Set Fps
	
	SetTargetFPS(60);

	// Main Loop
	while(!WindowShouldClose()){
		UpdateCamera(&camera);
		ClearBackground(BLACK);
		BeginDrawing();

		BeginMode3D(camera);
		//DrawGrid(10,1.0f);
		for(int i=1; i< (int) LA.poslist.size();i++){
			
			DrawLine3D(LA.poslist[i-1],LA.poslist[i],BLUE);
		}
		Vector3 Sphere_Centre=LA.generateposition(GetFrameTime()); 
		DrawSphereWires(Sphere_Centre, 1.0f, 10, 10, WHITE);
		DrawSphere(Sphere_Centre,1.0f,RED);
		LA.printposition();
		EndMode3D();
		


		EndDrawing();
	}

	return 0;
}
