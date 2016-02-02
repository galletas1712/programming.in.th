#include <stdio.h>
using namespace std;

// add glob

bool isIn(int n){
    for(int i = 0; i < r-1; i++){
        if (na[i] == n) return true;
    }
    return false;
}

void permute(int lvl){
    if(lvl == r){
        for(int c = 0 ; c < r ; c++){
            if(isIn(a[0])) return;
            printf("%d ",a[c]);
        }
        printf("\n");
        return;
    }
    for(int c = 1 ; c <= r ; c++){
        if(u[c]) continue;
        a[lvl] = c;
        u[c] = 1;
        permute(lvl+1);
        u[c] = 0;
    }
}

int main(){
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &na[i]);
    }
    r = n;
    permute(0);
}
