#include <stdio.h>
using namespace std;

int main() {
    int arr[9];
    int sum=0;
    for(int i = 0; i < 9; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    int r = sum - 100;
    int n1;
    int n2;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(arr[i]+arr[j] == r){
                n1 = i;
                n2 = j;
            }
        }
    }
    for(int i = 0; i < 9; i++){
        if(!(i == n1 || i == n2)){
            printf("%d\n", arr[i]);
        }
    }
}
