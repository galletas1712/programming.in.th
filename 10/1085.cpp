#include <cstdio>
#include <cstdlib>
using namespace std;

int n, m, k;
bool rooms[500010];
bool rock[500010];
int warp[1000001][2];

void printRoom(){
    for(int i = 1; i <= n; i++){
        if(rooms[i]) printf("T");
        else printf("F");
    }
}

int sort(const void* a, const void* b){
    return *(int*)a > *(int*)b;
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++) rooms[i] = false, rock[i] = false;
    for(int i = 0; i < m; i++) scanf("%d %d", &warp[i][0], &warp[i][1]);
    for(int i = 0; i < k; i++){
        int a;
        scanf("%d", &a);
        rock[a] = true;
    }
    qsort(warp, m, sizeof(warp[0]), sort);
    rooms[1] = true;
    int max = 0;
	int cwi = 0;
    for(int i = 1; i <= n; i++){
        if((rooms[i-1] && !rock[i-1]) || rooms[i]) {
            rooms[i] = true;
            max = i;
            while(warp[cwi][0] <= i && cwi < m){ 
                if(warp[cwi][0] == i) rooms[warp[cwi][1]] = true;
                cwi++;
            }
        }
    }
    if(max == n) printf("1");
    else printf("0 %d", max);
}