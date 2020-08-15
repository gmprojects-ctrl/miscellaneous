#include<stdio.h>
int fib(int a, int b,int limit){
	int c= a+b;
	if(c>limit){
		return c;
	}else{
		printf("%d\n",c);
		return fib(b,c,limit);
	}

}
int main(){
	int limit;
	printf("Enter the limit of the fibonacci sequence\n");
	scanf("%d",&limit);
	fib(0,1,limit);
	return 0;
}
