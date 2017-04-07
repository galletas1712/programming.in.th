/*
Notes on optimization:
- At first, I used two different arrays to keep the states, being dp[][][][] and tmp[][][][].
  The problem with this approach was that I had to copy data to a fro at every iteration, which gave TLE.
- After moving to the dp[2][][][][] style, the need to copy data was eliminated,
  since if I set the initial values to INT_MIN, the impossible cases will always turn out to be negative and thus suboptimal.
  Therefore, I was able to eliminate two 4^4 inner loops, which then passed on all cases.
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1e5)+1;

inline int f(int a, int b, int c) { // never use unique from algorithm to do this again!!!
	int ret = 0;
	if(a == 1 || b == 1 || c == 1) ret++;
	if(a == 2 || b == 2 || c == 2) ret++;
	if(a == 3 || b == 3 || c == 3) ret++;
	return ret;
}
int n, ans, a[MAXN], dp[2][4][4][4][4];
char s[MAXN];
int main() {
	scanf("%d%s",&n,s);
	for(int i = 0; i < n; i++) {
		if(s[i] == 'M') a[i] = 1;
		else if(s[i] == 'B') a[i] = 2;
		else a[i] = 3;
	
	}
	// initialize values
	int then = 0, now = 1;
	for(int xl = 0; xl < 4; xl++) for(int xr = 0; xr < 4; xr++)
		for(int yl = 0; yl < 4; yl++) for(int yr = 0; yr < 4; yr++)
			dp[then][xl][xr][yl][yr] = dp[now][xl][xr][yl][yr] = INT_MIN;
	dp[then][0][a[0]][0][0] = dp[then][0][0][0][a[0]] = 1;
	// dynamic programming
	for(int i = 1; i < n; i++) {
		for(int yl = 0; yl < 4; yl++) for(int yr = 0; yr < 4; yr++)
			for(int xl = 0; xl < 4; xl++) for(int k = 0; k < 4; k++)
				dp[now][xl][a[i]][yl][yr] = max(dp[then][k][xl][yl][yr]+f(k, xl, a[i]), dp[now][xl][a[i]][yl][yr]);
		for(int xl = 0; xl < 4; xl++) for(int xr = 0; xr < 4; xr++)
			for(int yl = 0; yl < 4; yl++) for(int k = 0; k < 4; k++)
				dp[now][xl][xr][yl][a[i]] = max(dp[then][xl][xr][k][yl]+f(k, yl, a[i]), dp[now][xl][xr][yl][a[i]]);
		swap(then, now);
	}
	// find an print answer
	for(int xl = 0; xl < 4; xl++) for(int xr = 0; xr < 4; xr++)
		for(int yl = 0; yl < 4; yl++) for(int yr = 0; yr < 4; yr++)
			ans = max(dp[then][xl][xr][yl][yr], ans);
	printf("%d", ans);
}
