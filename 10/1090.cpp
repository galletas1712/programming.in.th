#include <cstdio>    
using namespace std;    
  
long long tails[1000001];  
int main(){  
    double count=0;  
    long long a, n;    
    scanf("%lld", &n);    
    for(long long i = 0; i < n; i++) tails[i] = 0; //initialize to 0    
    for(long long i = 0; i < n; i++){    
        long long c;    
        scanf("%lld", &c);    
        tails[c] += 1;    
    }    
    scanf("%lld", &a);    
    long long x = 0;
    long long y = a;    
    while(x < y){    
        count += tails[x]*tails[y];    
        x++;    
        y--;    
    }    
    if(x == y){ // combi nC2 = n(n-1)/2    
        count += tails[x]*(tails[x]-1)/2;    
    }    
    printf("%.0lf", count);    
}  
