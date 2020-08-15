#include<stdio.h>
int fib(int a, int b){
	int c= a+b;
	if(c>100000000){
		return c;
	}else{
		printf("%d\n",c);
		return fib(b,c);
	}

}
int main(){
	printf("%d",fib(0,1));
	return 0;
}
