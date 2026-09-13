include<stdio.h>{
	
	typedef struct{
	int x;
	double y;
	}AAA;


	int main(void){
    AAA a;
	a.x = 10;
	a.y = 3.14;
	AAA* p = &a;
	p -> x = 1;
	p -> y = 2.01;
return 0;
}
