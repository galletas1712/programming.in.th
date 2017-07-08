#include <bits/stdc++.h>
using namespace std;
const int MAX = (1e6)+2;

int n, m, ans, mn[MAX], mx[MAX], dp[2][5][5];
char s[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s+1;
	mn[0] = 0, mx[0] = 0;
	for(int i = 1; i <= n; i++) {
		mn[i] = mn[i-1] + (s[i] == 'L') - (s[i] == 'P');
		mx[i] = mx[i-1] + (s[i] == 'L') - (s[i] == 'P');
		mn[i] = min((s[i] == 'L') - (s[i] == 'P'), mn[i]);
		mx[i] = max((s[i] == 'L') - (s[i] == 'P'), mx[i]);
	}
	int pre = 0, curr = 1;
	ans = (mx[n-1] < 2)*(s[n] == 'P')+1;
	for(int l = -2; l <= 2; l++) for(int r = l; r <= 2; r++) {
		dp[pre][l+2][r+2] = (l <= -1 && r >= -1) + (l <= 1 && r >= 1);
	}
	for(int i = n-1; i >= 1; i--, swap(pre, curr)) {
		memset(dp[curr], 0, sizeof(dp[curr]));
		for(int l = -2; l <= 2; l++) for(int r = l; r <= 2; r++) {
			if(l <= -1) dp[curr][l+2][r+2] += dp[pre][min(l+1, 2)+2][min(r+1, 2)+2];
			if(r >= 1) dp[curr][l+2][r+2] += dp[pre][max(l-1, -2)+2][max(r-1, -2)+2];
			dp[curr][l+2][r+2] %= m;
		}
		if(s[i] == 'P') {
			mn[i] = min(mn[i-1] + 1, 1);
			mx[i] = max(mx[i-1] + 1, 1);
			if(mx[i] > 2) continue;
			ans += dp[pre][max(-2-mn[i], -2)+2][min(2-mx[i], 2)+2];
			ans %= m;
		}
	}
	cout << ans;
}
