#include <bits/stdc++.h>

int n, ans, dp[1000002], sum[1000002][3], f[1000001];
char s[1000002];

int p(char c) {
	if(c == 'P') return 0;
	else return (c-'P'-1);
}

int main() {
	scanf("%d%s",&n,s+1);
	dp[n] = 1;
	dp[n-1] = 3;
	for(int i = n-2; i >= 1; i--) dp[i] = ((dp[i+1] + dp[i+2])*2)%2553;

	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= 2; j++) sum[i][j] = dp[i]*(j+1);

	if(p(s[1]) > 0) f[1] = sum[1][p(s[1])-1] + 1;
	else f[1] = 1;

	for(int i = 2; i <= n; i++) {
		if(i < n or (i == n and i > 2 and p(s[i-1]) == p(s[i-2]))) {
			int j = p(s[i-1]);

			if(i > 2 and p(s[i-2]) == j) sum[i][j] = 0;
			else sum[i][j] = 2*dp[i+1];

			if(!j) sum[i][j] %= 2553, sum[i][j+1] = sum[i][j] + dp[i], sum[i][j+2] = sum[i][j+1] + dp[i];
			else if(j == 1) sum[i][j] += dp[i], sum[i][j+1] = sum[i][j] + dp[i];
			else sum[i][j] += 2*dp[i];
		}
		f[i] = f[i-1] % 2553;
		if(p(s[i]) > 0) f[i] += sum[i][p(s[i])-1] % 2553;
	}
	printf("%d", f[n] % 2553);
}
