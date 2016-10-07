#include <bits/stdc++.h>
using namespace std;

int n, k, res;
long long o[1000001], r[1000001];
char a[1000002];
map<long long,int> mp;
int main() {
    scanf("%d%d%s",&n,&k,a+1);
    for(int i = 1; i <= n; i++) {
        o[i] = o[i-1];
        r[i] = r[i-1];
        if(a[i] == 'O') o[i]++;
        else r[i]++;
    }
    mp[0] = 0;
    for(int i = 1; i <= n; i++) {
        if(mp.count(o[i]-k*r[i])) res = max(i-mp[o[i]-k*r[i]], res);
        else mp[o[i]-k*r[i]] = i;
    }
    printf("%d", res);
}
