#include <cstdio>
using namespace std;

int chars[5];

void add(int n){
    int nums[5] = {0, 0, 0, 0, 0};
    while(n > 0){
        if(n >= 100){
            nums[4] += 1;
            n -= 100;
        }else if(n >= 90){
            nums[4] += 1;
            nums[2] += 1;
            n -= 90;
        }else if(n >= 50){
            nums[3] += 1;
            n -= 50;
        }else if(n >= 40){
            nums[3] += 1;
            nums[2] += 1;
            n -= 40;
        }else if(n >= 10){
            nums[2] += 1;
            n -= 10;
        }else if(n >= 9){
            nums[2] += 1;
            nums[0] += 1;
            n -= 9;
        }else if(n >= 5){
            nums[1] += 1;
            n -= 5;
        }else if(n >= 4){
            nums[1] += 1;
            nums[0] += 1;
            n -= 4;
        }else if(n >= 1){
            nums[0] += 1;
            n -= 1;
        }
    }
    for(int i = 0; i < 5; i++) chars[i] += nums[i];
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) add(i);
    for(int i = 0; i < 5; i++){
        printf("%d", chars[i]);
        if(i < 4) printf(" ");
    }
}