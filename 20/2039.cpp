#include <bits/stdc++.h>
using namespace std;
const int MAX = (1e5)+1;

int n, m, cost[MAX], leader[MAX], cnt[MAX];
vector<int> g[MAX];
long long ans, sum[MAX];
priority_queue<pair<int,int> > pq[MAX];
void dfs(int u) {
	pq[u].emplace(cost[u], u);
	sum[u] = cost[u];
	cnt[u] = 1;
	for(int v: g[u]) {
		dfs(v);
		sum[u] += sum[v];
		cnt[u] += cnt[v];
		if(pq[u].size() < pq[v].size()) swap(pq[u], pq[v]);
		while(!pq[v].empty()) pq[u].push(pq[v].top()), pq[v].pop();
	}
	while(!pq[u].empty() && sum[u] > m) {
		sum[u] -= pq[u].top().first;
		cnt[u]--;
		pq[u].pop();
	}
	ans = max(1ll*leader[u]*cnt[u], ans);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0, p; i < n; i++) {
		cin >> p >> cost[i] >> leader[i];
		if(p) g[p-1].push_back(i);
	}
	dfs(0);
	cout << ans;
}
