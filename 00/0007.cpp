#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
	int r;
	double a, b;
	scanf("%d", &r);
	a = M_PI*r*r;
	b = r*r*2;
	printf("%0.6lf\n%0.6lf\n", a, b);
}
