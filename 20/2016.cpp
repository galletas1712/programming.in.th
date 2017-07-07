#include <bits/stdc++.h>
using namespace std;
const int N = (5e4)+1;

int n, k;
long long r, dp[N][11][4];
string s, rev_ord = "ACGT";
map<char, int> ord;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> r >> s;
	ord['A'] = 0;
	ord['C'] = 1;
	ord['G'] = 2;
	ord['T'] = 3;
	if(s[n-1] == 'N') {
		for(int j = 0; j < k; j++) for(int x = 0; x < 4; x++) dp[n-1][j][x] = 1;
	} else {
		int x = ord[s[n-1]];
		for(int j = 0; j < k; j++) dp[n-1][j][x] = 1;
	}
	for(int i = n-2; i >= 0; i--) {
		if(s[i] == 'N') {
			for(int j = 0; j < k; j++) for(int x = 0; x < 4; x++) {
				dp[i][j][x] = (j > 0 ? dp[i][j-1][x] : 0);
				for(int y = 0; y < 4; y++) {
					if(y < x) dp[i][j][x] += (j > 0 ? dp[i+1][j-1][y] : 0) - (j > 1 ? dp[i+1][j-2][y] : 0);
					else dp[i][j][x] += dp[i+1][j][y] - (j > 0 ? dp[i+1][j-1][y] : 0);
				}
			}
		} else {
			for(int j = 0; j < k; j++) {
				int x = ord[s[i]];
				dp[i][j][x] = (j > 0 ? dp[i][j-1][x] : 0);
				for(int y = 0; y < 4; y++) {
					if(y < x) dp[i][j][x] += (j > 0 ? dp[i+1][j-1][y] : 0) - (j > 1 ? dp[i+1][j-2][y] : 0);
					else dp[i][j][x] += dp[i+1][j][y] - (j > 0 ? dp[i+1][j-1][y] : 0);
				}
			}
		}
	}
	long long curr = 1;
	if(s[0] == 'N') {
		int x;
		for(x = 0; curr + dp[0][k-1][x] <= r; x++) curr += dp[0][k-1][x];
		assert(x < 4);
		s[0] = rev_ord[x];
	}
	for(int i = 1, j = 0; i < n; i++) {
		if(s[i] == 'N') {
			int x;
			for(x = 0; curr + dp[i][k-1-(j+(ord[s[i-1]] > x))][x] <= r; x++)
				curr += dp[i][k-1-(j+(ord[s[i-1]] > x))][x];
			assert(x < 4);
			s[i] = rev_ord[x];
		}
		j += s[i-1] > s[i];
	}
	cout << s;
}
