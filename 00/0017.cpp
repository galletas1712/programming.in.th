#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int val[4];
    for(int i = 0; i < 4; i++){
        scanf("%d", &val[i]);
    }
    sort(val, val+4);
    printf("%d", val[0]*val[2]);
}
