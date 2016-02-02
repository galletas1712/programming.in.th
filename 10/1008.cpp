#include <iostream>
using namespace std;

int skyline[256];
int main(){
    int n, rmax=0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int l, h, r;
        cin >> l >> h >> r;
        if(r > rmax) rmax = r;
        for(int i = l; i < r; i++){
            if(skyline[i] < h) skyline[i] = h;
        }
    }
    int prev = skyline[1];
    for(int i = 1; i <= rmax; i++){
        if((i > 1 && skyline[i] == prev) || (i == 1 && skyline[i] == 0)) continue;
        cout << i << " " << skyline[i];
        if(i < rmax) cout << " ";
        prev = skyline[i];
    }
}