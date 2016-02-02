#include <cstdio>
using namespace std;

int main(){
    int a, b, c, count=0;
    scanf("%d %d %d", &a, &b, &c);
    while(!(a == 1 && b == 1 && c == 1)){
        if(a > 1 && ((a >= b && b >= c) || (a >= c && c >= b))) a /= 2, count++;
        if(b > 1 && ((b >= a && a >= c) || (b >= c && c >= a))) b /= 2, count++;
        if(c > 1 && ((c >= a && a >= b) || (c >= b && b >= a))) c /= 2, count++;
    }
    printf("%d", count);
}
