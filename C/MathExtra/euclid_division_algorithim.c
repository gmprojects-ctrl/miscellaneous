#include<stdio.h>
int euclid_algorithim(int a , int b){
	int c= a%b;
	/* printf("%d \t %d \n",c,counter);*/
	if(c==0)
	{
		return b; 
	}
	else
	{
		return euclid_algorithim(b,c);
	};

}

int main(){
	int a,b;
	printf("Enter the first number\n");
	scanf("%d",&a);
	printf("Enter the second number\n");
	scanf("%d",&b);
	if(a>b)
	{
		printf("The greatest commond divisor of %d and %d is %d \n",a,b,euclid_algorithim(a,b));
	}
	else
	{
		printf("The greatest commond divisor of %d and %d is %d \n",a,b,euclid_algorithim(b,a));
	}

}
