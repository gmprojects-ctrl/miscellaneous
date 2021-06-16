/* Calculating the vector dot product */
int dot_product(int *a, int *b){
	int c=0;
	for(int i=0; i<2;i++){c+=a[i]*b[i];};
	return c;}
/* I know it's a very cheap method of calculating the product
 * of two 2x2 matrices but it works and its intuitive for
 * me to understand */

/* Multiplication of 2x2 matrix */
int * twobytwom(int *a, int *b){
	static int c[4];
	int co_a_up[]={a[0],a[1]};
	int co_a_down[]={a[2],a[3]};

	int co_b[2][2]={ {b[0],b[2]}
		        ,{b[1],b[3]}};

	for(int i =0 ; i<=1; i++){
		c[i]=dot_product(co_a_up,co_b[i]);
	/*	printf("%d \n ", c[i]); Debugging only */
	};
	for(int i =0 ; i<=1; i++){
		c[2+i]=dot_product(co_a_down,co_b[i]);
	/*	printf("%d \n ", c[3-i]); Debugging only */
	};

	return c;



}
