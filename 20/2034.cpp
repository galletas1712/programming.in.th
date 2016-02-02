#include <bits/stdc++.h>
using namespace std;

int n, m, a[51][51], b[51][51], dp[51][51][51][51];

int solve(int r1, int c1, int r2, int c2) {
	if(r1 == r2 && c1 == c2) return 0;
	if(!dp[r1][c1][r2][c2]) {
		int bp = INT_MAX; // best pay
		for(int i = r1+1; i <= r2; i++) bp = min(solve(r1 ,c1, i-1, c2)+solve(i, c1, r2, c2), bp);
		for(int i = c1+1; i <= c2; i++) bp = min(solve(r1, c1, r2, i-1)+solve(r1, i, r2, c2), bp);
		dp[r1][c1][r2][c2] = bp + b[r2][c2]-b[r1-1][c2]-b[r2][c1-1]+b[r1-1][c1-1];
	}
	return dp[r1][c1][r2][c2];
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d",&a[i][j]), b[i][j] = b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j];
	printf("%d",solve(1, 1, n, m));
}
