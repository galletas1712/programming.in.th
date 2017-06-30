#include <bits/stdc++.h>
using namespace std;
const int MAX = (1e5)+1;

int n, ans, mnd = INT_MAX, mxd, l[MAX], r[MAX], state[MAX];
bool valid = true;
void dfs1(int u, int d) {
	if(l[u] != -1) dfs1(l[u], d+1);
	if(r[u] != -1) dfs1(r[u], d+1);
	if(l[u] == -1 || r[u] == -1) {
		mnd = min(d+1, mnd);
		mxd = max(d+1, mxd);
	}
}
void dfs2(int u, int d) {
	if(l[u] != -1) {
		dfs2(l[u], d+1);
		state[u] = state[l[u]];
	}
	else state[u] = d+1 == mxd;
	if(r[u] != -1) {
		dfs2(r[u], d+1);
		ans += (state[u] < state[r[u]] && !state[u]) || (state[u] == 2 && state[r[u]] == 1);
		if(state[u] != state[r[u]]) state[u] = 2;
		else if(state[u] == 2 && state[r[u]] == 2) valid = false;
	}
	else if((d+1 == mxd) != state[u]) {
		state[u] = 2;
		ans += d+1 == mxd;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		l[i] -= l[i] != -1;
		r[i] -= r[i] != -1;
	}
	dfs1(0, 0);
	dfs2(0, 0);
	if(mxd - mnd > 1 || !valid) cout << -1, exit(0);
	cout << ans;
}
