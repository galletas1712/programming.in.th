#include <bits/stdc++.h>
#define maskf first
#define maskl second
using namespace std;
const int N = (1e4)+1;

int n, c, ans, dp[N][1 << 5];
vector<pair<int,int> > children[N];

int getAdd(int i, int mask, int init_mask) {
	bool valid = true;
	for(int k = 0; k < 5; k++) if((i+k)%n >= 0 && (i+k)%n < 5) {
		valid &= (mask >> k & 1) == (init_mask >> (i+k)%n & 1);
	}
	if(!valid) return -1;
	int ret = 0;
	for(auto p: children[i]) ret += (~mask & p.maskf) || (mask & p.maskl);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> c;
	for(int i = 0, start, fc, lc; i < c; i++) {
		cin >> start >> fc >> lc; --start;
		pair<int,int> tmp;
		for(int j = 0, x; j < fc; j++) {
			cin >> x; --x;
			tmp.maskf |= 1 << (x+n-start)%n;
		}
		for(int j = 0, x; j < lc; j++) {
			cin >> x; --x;
			tmp.maskl |= 1 << (x+n-start)%n;
		}
		children[start].push_back(tmp);
	}
	for(int init_mask = 0; init_mask < 1 << 5; init_mask++) {
		memset(dp, 0, sizeof(dp));
		dp[0][init_mask] = getAdd(0, init_mask, init_mask);
		for(int i = 0; i < n-1; i++) {
			for(int mask = 0; mask < 1 << 5; mask++) if(getAdd(i, mask, init_mask) != -1) {
				if(getAdd(i+1, (mask >> 1) + (1 << 4), init_mask) != -1) {
					int add = getAdd(i+1, (mask >> 1) + (1 << 4), init_mask);
					dp[i+1][(mask >> 1) + (1 << 4)] = max(dp[i][mask] + add, dp[i+1][(mask >> 1) + (1 << 4)]);
				}
				if(getAdd(i+1, mask >> 1, init_mask) != -1) {
					int add = getAdd(i+1, mask >> 1, init_mask);
					dp[i+1][mask >> 1] = max(dp[i][mask] + add, dp[i+1][mask >> 1]);
				}
			}
		}
		for(int mask = 0; mask < 1 << 5; mask++) ans = max(dp[n-1][mask], ans);
	}
	cout << ans;
}
