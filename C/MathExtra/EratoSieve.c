#include<stdio.h>
#include<math.h>
int main(){
	int N=50000;
	int arr[N+1];
	arr[0]=0;
	arr[1]=0;
	int count= round(sqrt(N+1))+1;
	for(int i =2; i<N+1; i++)
	{
		arr[i]=1;
	}
	for(int i=2; i<count  ;i++)
	{
		if(arr[i]==1)
		{
			for(int j=i*i;j<N+1;j+=i)
			{
				arr[j]=0;
			}
		}
	}
/*	for(int i=0; i<N;i++)
	{
		if(arr[i]==1)
		{
			printf("%d\n",i);
		}
	} */






	return 0;
}
