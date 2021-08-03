#include<stdio.h>
void scmulr(int column,int focus,double scalar,double arr[][column])
{
	for(int j =0; j<column;j++)
	{
		arr[focus][j]*=scalar;
	}
	

}
void swaprow(int column,int row_1, int row_2, double arr[][column])
{
	double temp[column];
	for(int i=0; i<column;i++)
	{
		temp[i]=arr[row_2][i];
	}
	for(int i=0; i<column;i++)
	{
		arr[row_2][i]=arr[row_1][i];
	}
	for(int i=0; i<column;i++){
		arr[row_1][i]=temp[i];
	}

}
void addrow(int column, int row_1, int row_2,double scalar,double arr[][column])
{
	for(int i=0; i<column;i++)
	{
		arr[row_2][i]+=arr[row_1][i]*scalar;
	}

}
void printmatrix( int row, int column, double arr[][column])
{
	for(int i=0; i < row; i++)
	{
		for(int j =0; j<column;j++)
		{

			printf("%f ",arr[i][j]);
		}
		printf("\n");
	}
}
void gaussianelim( int row, int column, double arr[][column] ){
	int i =0;
	int j=0;
	while(i<row && j<column ){
		double focus_value=arr[i][j];
		if(focus_value == 0)
		{
			j+=1;
		}else{
			scmulr(column,i,1/focus_value,arr);
			for(int z=0; z< row;z++)
			{
				if(z==i){}
				else{
					addrow(column,i,z,-arr[z][j],arr);

				}
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
	gaussianelim(2,3,a);
	printmatrix(2,3,a);
	double b[][4]={{2,-3,0,-6},{1,-1,1,1},{0,-3,-2,-5}};
	printf("\n");
	gaussianelim(3,4,b);
	printmatrix(3,4,b);
	return 0;

}
