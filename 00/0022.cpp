#include <stdio.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    if(n % 2 == 1){
        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < n; j++){
                if((j == n/2 + i) || (j == n/2 - i)){
                    printf("*");
                }else{
                    printf("-");
                }
            }
            printf("\n");
        }
        for(int i = n/2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                if((j == n/2 + i) || (j == n/2 - i)){
                    printf("*");
                }else{
                    printf("-");
                }
            }
            printf("\n");
        }
    }else{
        for(int i = 0; i < n/2; i++){
            for(int j = 0; j < n-1; j++){
                if((j == (n-1)/2 + i) || (j == (n-1)/2 - i)){
                    printf("*");
                }else{
                    printf("-");
                }
            }
            printf("\n");
        }
        for(int i = (n-1)/2; i >= 0; i--){
            for(int j = 0; j < n-1; j++){
                if((j == (n-1)/2 + i) || (j == (n-1)/2 - i)){
                    printf("*");
                }else{
                    printf("-");
                }
            }
            printf("\n");
        }
    }
}
