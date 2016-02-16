#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8;
int n, m, q, dist[501][501];
vector<int> routes[1000001];
int main() {
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= m; j++)
			if(i != j) dist[i][j] = INF;
	for(int i = 1; i <= m; i++) {
		int s;
		scanf("%d",&s);
		for(int j = 0; j < s; j++) {
			int v;
			scanf("%d", &v);
			routes[v].push_back(i);
		}
	}
	for(int i = 1; i <= n; i++) { // cyclic graph
		for(int j = 0; j < routes[i].size(); j++) {
			for(int k = j+1; k < routes[i].size(); k++) {
				if(routes[i][j] != routes[i][k]) dist[routes[i][j]][routes[i][k]] = dist[routes[i][k]][routes[i][j]] = 1;
			}
		}
	}
	for(int k = 1; k <= m; k++)
		for(int i = 1; i <= m; i++)
			for(int j = 1; j <= m; j++)
				if(dist[i][j]) dist[i][j] = min(dist[i][k]+dist[k][j], dist[i][j]);
	scanf("%d",&q);
	for(int i = 1; i <= q; i++) {
		int u, v, ans = INF;
		scanf("%d%d",&u,&v);
		for(int j = 0; j < routes[u].size(); j++)
			for(int k = 0; k < routes[v].size(); k++) ans = min(dist[routes[u][j]][routes[v][k]], ans);
		if(ans != INF) printf("%d\n", ans);
		else printf("impossible\n");
	}
}
