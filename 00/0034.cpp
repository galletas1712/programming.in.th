#include <cstdio>
using namespace std;

int main(){
	int A, B, C, a, b, c, d, initC;
	scanf("%d %d %d", &A, &B, &C);
	initC = C;
	if(C >= 0) initC = C*-1;
	for(int i = 1; i <= A; i++){
		if(A % i == 0){
			a = i;
			c = A/i;
			for(int j = initC; j <= initC*-1; j++){
				if(j != 0){
					if(C % j == 0){ // modulus with negative
						b = j;
						d = C/j; // how about negative results? 
						//printf("a: %d b: %d c: %d d: %d\n", a, b, c, d);
						if(a*d+b*c == B){
							if(a < c){
								printf("%d %d %d %d", a, b, c, d);
							}else if(c < a){
								printf("%d %d %d %d", c, d, a, b);
							}else{
								if(b < d){
									printf("%d %d %d %d", a, b, c, d);
								}else if(b > d){
									printf("%d %d %d %d", c, d, a, b);
								}else{
									printf("%d %d %d %d", a, b, c, d);
								}
							}
							return 0;
						}
					}
				}
			}

		}
	}
	printf("No Solution");
}
