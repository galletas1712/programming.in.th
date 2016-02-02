#include <stdio.h>
#include <algorithm>

using namespace std;

int a[10][2];
int u[10];
int i[10];
int r = 0;
int range = 0;
int diff = 0;
int m = 100000000;

void permute(int lvl, int st){
    if(lvl > 0){
        int s = 1;
        int b = 0;
        for(int c = 0 ; c < lvl ; c++){
            s *= a[i[c]][0];
            b += a[i[c]][1];
            // printf("%d ", i[c]);
        }
        diff = max(s-b,b-s);
        // printf(": %d\n", diff);
        if(m == 100000000) m = diff;
        if(diff < m){
            m = diff;
        }
    }
    if(lvl == r) return;
    for(int c = st ; c < range ; c++){
        // if(u[c]) continue;
        i[lvl] = c;
        // u[c] = 1;
        permute(lvl+1,c+1);
        // u[c] = 0;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    range = n;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    /*for(int i = 1; i <= n; i++){
    r = i;
    permute(0);
    }*/
    r = n;
    permute(0,0);
    printf("%d", m);
    /*for(int i = 0; i < n; i++){
    printf("%d %d\n", a[i][0], a[i][1]);
    }*/

}
