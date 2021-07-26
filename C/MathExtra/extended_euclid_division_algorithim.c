#include<stdio.h>

/* Extended Euclidean Algorthim implemenation or EEA 
 *
 *Courtesy of An Introduction to Mathematical Cryptography
 * 
 *
 * */
int EEA(int* array,int array_length,int a,int b,int x,int y,int u,int g){
	if(array_length <3){
		printf("Insufficient memory error");
		return -1;
	}
	if(y==0){
		array[0]=g;
		array[1]=u;
		array[2]=(g-a*u)/b;
		return 0;
	}
	else{
	int t = g%y;
	int q = (g-t)/y;
	int s = u-q*x;
	EEA(array,array_length,a,b,s,t,x,y);
	}
	return -1;
}

int main(){
	int arr[3]={0,0,0};
	EEA(arr,3,7,19,0,19,1,7);
	printf("%d %d %d\n",arr[0],arr[1],arr[2]);
	return 0;
}
