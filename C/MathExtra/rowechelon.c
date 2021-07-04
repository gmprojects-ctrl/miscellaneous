#include<stdio.h>
int scmulr(double*start,int row,int column,int focus,double scalar)
{
	if(focus>row-1 || focus < 0)
	{
		return -1;
	}else{
		for(int j=0; j<column; j++){

			*(start+row*focus+j)*=scalar;
		}
		return 0;
	}

}
void swaprow(double* start, int row, int column, int row_1, int row_2)
{
	double temp[column];
	for(int i=0; i<column;i++)
	{
		temp[i]=*(start+row_2*row+i);
	}
	for(int i=0; i<column;i++)
	{
		*(start+row_2*row+i)=*(start+row_1*row+i);
	}
	for(int i=0; i<column;i++){
		*(start+row_1*row+i)=temp[i];
	}

}
void addrow(double* start, int row, int column, int row_1, int row_2)
{
	for(int i=0; i<column;i++)
	{
		*(start+row_2*row+i)+=*(start+row_1*row+i);
	}

}
void printmatrix(double* start, int row, int column)
{
	for(int i=0; i < row; i++)
	{
		for(int j =0; j<column;j++)
		{

			printf("%f ",*(start+i*row+j));
		}
		printf("\n");
	}
}
void gaussianelim(double* start, int row, int column){
	int i =0;
	int j=0;
	while(i<row && j<column ){
		double focus_value=*(start+i*row+j);
		if(focus_value == 0)
		{
			j+=1;
		}else{
			printf("%f\n",focus_value);
			scmulr(start,row,column,i,1/focus_value);
			printmatrix(start,row,column);
			printf("\n");
			for(int z=0; z< row;z++)
			{
				if(z==i){}
				else{
					for(int y=0; y<column;y++)
					{
						*(start+z*row+y)-=*(start+i*row+y)*(*(start+z*row+j));
					}
				}
					printmatrix(start,row,column);
					printf("\n");
			}
			i+=1;
			j+=1;
		}
	}
}
int main()
{
	double a[2][3]={
		{1,2,1},
		{3,4,12},
	};
	gaussianelim(&a[0][0],2,3);
printmatrix(&a[0][0],2,3);
	return 0;

}
