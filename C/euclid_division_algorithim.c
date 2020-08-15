#include<stdio.h>
int euclid_algorithim(int a , int b){
	int c= a%b;
	int counter=(a-c)/b;
	/* printf("%d \t %d \n",c,counter);*/
	if(c==0){
		return b; 
	}else{
		return euclid_algorithim(b,c);
	};

}

int main(){
	printf("%d",euclid_algorithim(57,42));
}
