#include <stdio.h>
using namespace std;

void genpatt(int n){
    for(int i = 0; i < n; i++){
        if(i != 0){
            if(adrian[i-1] == 'A') adrian[i] = 'B';
            if(adrian[i-1] == 'B') adrian[i] = 'C';
            if(adrian[i-1] == 'C') adrian[i] = 'A';
        }else{
            adrian[i] = 'A';
        }
    }
    for(int i = 0; i < n; i++){
        if(i > 1){
            if(bruno[i-1] == 'A') bruno[i] = 'B';
            if(bruno[i-1] == 'B' && bruno[i-2] == 'A') bruno[i] = 'C';
            if(bruno[i-1] == 'B' && bruno[i-2] == 'C') bruno[i] = 'A';
            if(bruno[i-1] == 'C') bruno[i] = 'B';
        }else{
            bruno[i] = 'B';
            bruno[i+1] = 'A';
            i++;
        }
    }
    for(int i = 0; i < n; i += 2){
        if(i != 0){
            if(!(n-i < 2)){
                if(goran[i-1] == 'A'){
                    goran[i] = 'B';
                    goran[i+1] = 'B';
                }else if(goran[i-1] == 'B'){
                    goran[i] = 'C';
                    goran[i+1] = 'C';
                }else if(goran[i-1] == 'C'){
                    goran[i] = 'A';
                    goran[i+1] = 'A';
                }
            }else{
                if(goran[i-1] == 'A'){
                    goran[i] = 'B';
                }else if(goran[i-1] == 'B'){
                    goran[i] = 'C';
                }else if(goran[i-1] == 'C'){
                    goran[i] = 'A';
                }
            }
        }else{
            goran[i] = 'C';
            goran[i+1] = 'C';
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    char ans[n];
    scanf("%s", ans);
    this->genpatt(n);
    int adrian_score = 0;
    int bruno_score = 0;
    int goran_score = 0;
    for(int i = 0; i < n; i++){
        if(ans[i] == adrian[i]) adrian_score++;
        if(ans[i] == bruno[i]) bruno_score++;
        if(ans[i] == goran[i]) goran_score++;
    }
    int max = adrian_score;
    if(max < bruno_score) max = bruno_score;
    if(max < goran_score) max = goran_score;
    printf("%d\n",max);
    if(max == adrian_score)printf("Adrian\n");
    if(max == bruno_score)printf("Bruno\n");
    if(max == goran_score)printf("Goran\n");

}
