#include <stdio.h>
using namespace std;

bool find(int n){
    if(n % 6 == 0 || n % 9 == 0 || n % 20 == 0) return true;
    if(n == 6 || n == 9 || n == 20) return true;
    bool ret = false;
    if(n > 20)
        ret |= find(n-20);
    if(n > 9)
        ret |= find(n-9);
    if(n > 6)
        ret |= find(n-6);
    return ret;
}

int nums[110] = {};

int main(){
    int n;
    scanf("%d", &n);
    nums[0] = 1;
    for(int i = 1; i <= n; i++){
        // printf("%d: ",i);
        if(i >= 20){
            if(nums[i-20] || nums[i-9] || nums[i-6]){
                nums[i] = 1;
            }
        }else if(i >= 9){
            if(nums[i-9] || nums[i-6]){
                nums[i] = 1;
            }
        }else if(i >= 6){
            if(nums[i-6]){
                nums[i] = 1;
            }
        }else{
            nums[i] = 0;
        }
        // printf("%d\n",nums[i]);
    }
    bool found = false;
    for(int i = 1; i <= n; i++){
        if(nums[i])
            printf("%d\n", i), found = true;
    }
    if(!found) printf("no");
}
