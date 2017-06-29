#include <bits/stdc++.h>
using namespace std;
const int N = (2e4)+1, M = (1e3)+1;
const long long INF = 1e18;

int n, x[N], y[N];
long long ans = INF, dp[2][2][2][2*M+2], res[2][2][2*M+2];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	for(int t1 = 0; t1 < 2; t1++) for(int t2 = 0; t2 < 2; t2++) fill(dp[0][t1][t2], dp[0][t1][t2]+2*M+2, INF);
	for(int j = 0; j < M; j++) dp[0][0][0][M+j] = dp[0][1][0][M+j] = 0;
	for(int j = -M-1; j <= 0; j++) dp[0][0][1][M+j] = dp[0][1][1][M+j] = 0;
	int pre = 0, curr = 1;
	for(int i = 1; i <= n; i++, swap(pre, curr)) {
		for(int t1 = 0; t1 < 2; t1++) for(int t2 = 0; t2 < 2; t2++) {
			fill(res[t1][t2], res[t1][t2]+2*M+2, INF);
			fill(dp[curr][t1][t2], dp[curr][t1][t2]+2*M+2, INF);
		}
		for(int j = -M+1; j < M; j++) {
			res[0][0][M+j] = min(dp[pre][0][0][M+j]+j, dp[pre][0][1][M+j]-j)+abs(x[i]-x[i-1]);
			res[0][1][M+j] = min(dp[pre][1][0][M+x[i]]+x[i], dp[pre][1][1][M+x[i]]-x[i])+abs(j-y[i-1]);
			res[1][0][M+j] = min(dp[pre][0][0][M+y[i]]+y[i], dp[pre][0][1][M+y[i]]-y[i])+abs(j-x[i-1]);
			res[1][1][M+j] = min(dp[pre][1][0][M+j]+j, dp[pre][1][1][M+j]-j)+abs(y[i]-y[i-1]);
			dp[curr][0][0][M+j] = min(dp[curr][0][0][M+j-1], min(res[0][0][M+j], res[0][1][M+j])-j);
			dp[curr][1][0][M+j] = min(dp[curr][1][0][M+j-1], min(res[1][0][M+j], res[1][1][M+j])-j);
		}
		for(int j = M-1; j > -M; j--) {
			dp[curr][0][1][M+j] = min(dp[curr][0][1][M+j+1], min(res[0][0][M+j], res[0][1][M+j])+j);
			dp[curr][1][1][M+j] = min(dp[curr][1][1][M+j+1], min(res[1][0][M+j], res[1][1][M+j])+j);
		}
		if(i == n) for(int j = -M+1; j < M; j++)
			for(int t1 = 0; t1 < 2; t1++)
				for(int t2 = 0; t2 < 2; t2++) ans = min(res[t1][t2][M+j], ans);
	}
	cout << ans;
}
