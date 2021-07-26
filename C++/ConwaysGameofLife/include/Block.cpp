#include<iostream>
#include"Block.hpp"
#include <cstdlib>
#include<raylib.h>
#include<vector>
Block::Block(bool Status,int X,int Y,int Length)
{
	this->ALIVE = Status;
	this->POSX=X;
	this->POSY=Y;
	this->WIDTH=Length;
}

inline int Block::getW(){
	return this->WIDTH;
}
inline int Block::getX(){
	return this->POSX;
}
inline int Block::getY(){
	return this->POSY;
}
inline int Block::getS(){
	return this->ALIVE;
}

void Block::changeS(int state){
	this->ALIVE=state;
}

void Block::MakeAlive(){
	this->ALIVE=1;
}
void Block::MakeDead(){
	this->ALIVE=0;
}
void Block::drawBlock(Color colour){
	if(this->ALIVE){
		DrawRectangle(this->POSX*this->WIDTH,this->POSY*this->WIDTH,this->WIDTH,this->WIDTH,RED);
	}
}

void scopygrid( std::vector<std::vector<Block> >&  GRID_SOURCE,  std::vector<std::vector<Block>> & GRID_DEST,int LENGTH)
{
	for(int i=0; i<LENGTH;i++){
		for(int j=0; j<LENGTH;j++)
		{
			GRID_DEST[i][j].changeS(GRID_SOURCE[i][j].getS());
		}
	}
}


void nextgn( std::vector< std::vector<Block>>& GRID_ORIG,  std::vector<std::vector<Block> >& GRID_REF, int LENGTH){
	for(int i=1; i< LENGTH-1;i++){
		for(int j=1; j < LENGTH-1; j++){
			int ALIVE_NEIGBOURS=0;
			for(int up=-1; up<=1;up++)
			{
				for(int down=-1; down<=1;down++)
				{
					ALIVE_NEIGBOURS +=GRID_REF[i+up][j+down].getS();

				}

			}
			ALIVE_NEIGBOURS-=GRID_REF[i][j].getS();

			if(GRID_REF[i][j].getS() ==1 && ALIVE_NEIGBOURS <2 )
			{
				GRID_ORIG[i][j].MakeDead();
			

			}else if(GRID_REF[i][j].getS()==1 && ALIVE_NEIGBOURS >3)
			{
				GRID_ORIG[i][j].MakeDead();
			}
			else if (GRID_REF[i][j].getS()==0 && ALIVE_NEIGBOURS==3){
				GRID_ORIG[i][j].MakeAlive();
			}
			else{
				GRID_ORIG[i][j].changeS(GRID_REF[i][j].getS());
			}

		}
	}
}

void printgrid( std::vector<std::vector<Block>>& GRID, int LENGTH){
	for(int i = 0; i<LENGTH;i++){
		std::cout<<"\n";
		for(int j=0; j<LENGTH; j++){
			std::cout<<GRID[i][j].getS();
		}
	}
	std::cout<<"\n";
}

void MakeAllDead(std::vector<std::vector<Block>>& BlOCK_BUFFER, int LENGTH){
	for(int i=0; i< LENGTH ;i++){
		for(int j=0; j< LENGTH;j++){
			BlOCK_BUFFER[i][j].MakeDead();
		}
	}
}
