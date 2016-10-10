#include <bits/stdc++.h>
using namespace std;

int n;
long long a[10], b[10], c[10], ab[100], ac[100], bc[100], abc[1000];
int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        char s[4];
        scanf("%s", s);
        a[s[0]-'0']++;
        b[s[1]-'0']++;
        c[s[2]-'0']++;
        ab[(s[0]-'0')*10+s[1]-'0']++;
        ac[(s[0]-'0')*10+s[2]-'0']++;
        bc[(s[1]-'0')*10+s[2]-'0']++;
        abc[(s[0]-'0')*100+(s[1]-'0')*10+s[2]-'0']++;
    }
    long long sum = 0;
    for(int i = 0; i < 10; i++) sum += a[i]*(a[i]-1)/2 + b[i]*(b[i]-1)/2 + c[i]*(c[i]-1)/2;
    for(int i = 0; i < 100; i++) sum -= ab[i]*(ab[i]-1)/2 + ac[i]*(ac[i]-1)/2 + bc[i]*(bc[i]-1)/2;
    for(int i = 0; i < 1000; i++) sum += abc[i]*(abc[i]-1)/2;
    printf("%lld",sum);
}
