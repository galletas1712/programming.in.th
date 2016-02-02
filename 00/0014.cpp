#include <stdio.h>
using namespace std;

int main(){
	int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

	int gcd = 0;
    int mod = a % b;
    int prev = b;

    while(mod != 0){
    	int mod_old = mod;
    	mod = prev % mod;
    	prev = mod_old;
    }
    gcd = prev;
    printf("%d\n", gcd);
}
