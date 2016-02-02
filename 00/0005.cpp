#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
	double a, b, c;
	scanf("%lf %lf", &a, &b);
	c= sqrt((a*a)+(b*b)); 
	printf("%0.6lf",c);
}
