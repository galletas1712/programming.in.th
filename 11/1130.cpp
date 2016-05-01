#include <bits/stdc++.h>
using namespace std;

long long n, a[10001], sum[10001], f[10001];
int main() {
	scanf("%lld",&n);
	for(long long i = 1; i <= n; i++) scanf("%lld",&a[i]), sum[i] = sum[i-1]+a[i];
	for(long long i = 1; i <= n; i++) f[2] += ((i-1)*a[i]-sum[i-1])%49999 , f[2] %= 49999;
	for(long long k = 3; k <= n; k++) f[k] = (f[k-1]*(n-(k-1)))%49999;
	printf("%lld",f[n] % 49999);
}
