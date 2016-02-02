#include <stdio.h>
using namespace std;

int main(){
	int a, b, res;
		scanf("%d", &a);
		scanf("%d", &b);
		if(b > a){
			if(b % a == 0){
				if(b == a){
					res = 0;
				}else{
					res = b/a;
				}
			}else{
				res = (b/a) + 1;
			}
		}else if (b < a && b > 0){
			res = 2;
		}else{
			res = 0;
		}
	printf("%d", res);
}
