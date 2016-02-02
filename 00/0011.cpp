#include <stdio.h>
using namespace std;

int main(){
    int arr[10];
    int used_mod[10];
    int used_mod_index = 0;
    for(int i = 0; i < 10; i++){
        int a;
        scanf("%d", &a);
        arr[i] = a % 42;
    }
    int n = 0;
    for(int i = 0; i < 10; i++){
        bool found = false;
        for(int j = 0; j < used_mod_index; j++){
            if(arr[i] == used_mod[j]) found = true;
        }
        if(!found){
            n += 1;
            used_mod[used_mod_index] = arr[i];
            used_mod_index++;
        }
    }
    printf("%d", n);
}
