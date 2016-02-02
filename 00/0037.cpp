#include <stdio.h>
#include <cmath>
using namespace std;

int main(){
    int n, m, l, k, c;
    int sum = 0;
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &l);
    scanf("%d", &k);
    scanf("%d", &c);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int a;
            scanf("%d", &a);
            sum += a;
        }
    }
    sum += l*k*c;
    if((sum/c)*c != sum) 
		printf("%d", (sum/c)+1);
	else
		printf("%d", (sum/c));
}
