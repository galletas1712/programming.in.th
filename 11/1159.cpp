#include <bits/stdc++.h>
using namespace std;

int n, m, J[1001], K[1001];
pair<int, int> dp[1001][1001];

pair<int, int> add(pair<int, int> p, int x) {
	if(p.second + x > m) p.first++, p.second = x;
	else p.second += x;
	return p;
}

int main() {
	scanf("%d%d",&m,&n);
	dp[0][0] = make_pair(1, 0);
	for(int i = 1; i <= n; i++) scanf("%d",J+i), dp[i][0] = add(dp[i-1][0], J[i]);
	for(int i = 1; i <= n; i++) scanf("%d",K+i), dp[0][i] = add(dp[0][i-1], K[i]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) dp[i][j] = min(add(dp[i-1][j], J[i]), add(dp[i][j-1], K[j]));
	printf("%d\n%d", dp[n][n].first, dp[n][n].second);
}
