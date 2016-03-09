#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int n;
bool mark[100002];
vector<pii> g[100002];

int dfs(int u) {
	int ret = 0;
	mark[u] = true;
	for(int i = 0; i < g[u].size(); i++) {
		int v = g[u][i].first;
		if(!mark[v]) ret = max(dfs(v) + g[u][i].second, ret);
	}
	return ret;
}

int main() {
	scanf("%d",&n);
	for(int i = 0; i < n-1; i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}
	printf("%d", dfs(1));
}
