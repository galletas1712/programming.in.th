#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
    int a, b, c;
    int longest = 0;
    scanf("%d %d %d", &a, &b, &c);
    int gecko[3] = {a, b, c};
    if(b-a > c-b)
        longest = b-a-1;
    else
        longest = c-b-1;
    printf("%d", longest);
}
