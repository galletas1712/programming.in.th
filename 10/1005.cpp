#include <cstdio>
using namespace std;

struct seq{
    int sum;
    int start;
    int len;
};

int main(){
    int n;
    scanf("%d", &n);
    int org[n];
    int cumsum = 0;
    int sum[n];
    seq max;
    max.sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &org[i]);
        cumsum += org[i];
        sum[i] = cumsum;
    }
    for(int i = n; i > 0; i--){
        for(int j = 0; j <= n-i; j++){
            int hisum = 0;
            int losum = 0;
            if(n > j+i) hisum = cumsum - sum[j+i-1];
            if(j > 0) losum = sum[j-1];
            int lsum = cumsum - hisum - losum;
            if(lsum > max.sum){
                max.sum = lsum;
                max.start = j;
                max.len = i;
            }
            // printf("hi %d lo %d\n", hisum, losum);
            // printf("%d %d: %d\n", j, j+i-1, lsum);
        }
        // printf("\n");
    }
    if(max.sum <= 0) printf("Empty sequence");
    else{
        for(int i = max.start; i < max.start + max.len; i++){
            printf("%d", org[i]);
            if(i < max.start + max.len-1) printf(" ");
        }
        printf("\n%d", max.sum);   
    }
}