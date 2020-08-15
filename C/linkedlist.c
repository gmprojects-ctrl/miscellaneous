#include<stdio.h>
struct Node{
int value;
struct Node *pointer; };
typedef struct Node node;
int main(){
	node a,b,c,d;
	a.value=6;
	a.pointer=&d;
	d.value=133;
	d.pointer=&b;
	b.value=7;
	b.pointer=&c;
	c.value=8;
	c.pointer=NULL;
	printf("The value of b is %d \n",a.pointer->value);
}
