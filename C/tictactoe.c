#include<stdio.h>
#include<stdlib.h>
void printgrid(char *table)
{
	for(int i=0; i<=2; i++)
	{
	for(int j=0; j<=2; j++)
	{
		printf("%c",*(table+i*2+j));
		if(j==2){
			printf("\n");
		}
	}
	
	}
}

void enter(char* table)
{
	int xpos,ypos;
	while(xpos>2 && ypos>2)
	{
		xpos=12;
		ypos=12;
		printf("\nEnter x cordinate\n");
		scanf("%d",&xpos);
		printf("\nEnter y cordinate\n");
		scanf("%d",&ypos);
		if(xpos>2 || ypos>2)
		{
			printf("\nInvalid coordinates");
		}
	}
	*(table+xpos*2+ypos)='O';
}
int main(){
	char table[3][3];
	for(int i=0; i<=2; i++)
	{
	for(int j=0; j<=2; j++)
		{
			table[i][j]='*';
		}
	
	}
	enter(table[0]);
	printgrid(table[0]);
	return 0;





}
