#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <raylib.h>
class Block{
	private:
		int ALIVE;
		int POSX;
		int POSY;
		int WIDTH;
	public:
		Block(bool,int,int,int);
		void MakeAlive();
		void MakeDead();
		void drawBlock(Color);
		int getX();
		int getY();
		int getW();
		int getS();
		void changeS(int);
};


void scopygrid( std::vector<std::vector<Block>>& ,  std::vector<std::vector<Block>>& ,int);

void nextgn( std::vector< std::vector<Block>>& ,  std::vector<std::vector<Block> >& , int );

void MakeAllDead(std::vector<std::vector<Block>>&, int );

void printgrid(std::vector<std::vector<Block>>&, int);

#endif
