#include <stdio.h>
using namespace std;

int main(){
    int sums[5];
    for(int i = 0; i < 5; i++){
        int sum = 0;
        for(int j = 0; j < 4; j++){
            int a;
            scanf("%d", &a);
            sum += a;
        }
        sums[i] = sum;
    }
    int max = 0;
    int max_index = 0;
    for(int i = 0; i<5; i++){
        if(sums[i] > max)
            max = sums[i], max_index = i;
    }
    printf("%d %d", max_index+1, max);
}
