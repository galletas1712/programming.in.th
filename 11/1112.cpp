#include <bits/stdc++.h>
using namespace std;

int n, k;
long long dp[2][10001];
int main() {
	scanf("%d%d",&n,&k);
	dp[0][0] = dp[1][0] = 1;
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			dp[1][j] = dp[1][j-1] + (dp[0][j] % 2012);
			if(j-i >= 0) dp[1][j] -= dp[0][j-i] % 2012;
		}
		for(int j = 1; j <= k; j++) dp[0][j] = dp[1][j];
	}
	printf("%lld", dp[1][k] % 2012);
}
