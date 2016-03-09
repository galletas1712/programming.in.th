#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int n, m, ax;
long long ans;
bool g[1001][1001]; // g[v][v] is intentionally left as 0
vector<pii> e;
int main() {
	scanf("%d%d",&n,&m);
	for(int i = 0; i < m; i++) {
		pii uv;
		scanf("%d%d",&uv.first,&uv.second);
		g[uv.first][uv.second] = true;
		g[uv.second][uv.first] = true;
		e.push_back(uv);
	}
	for(int i = 0; i < m; i++) {
		int u = e[i].first, v = e[i].second;
		long long cnt = 0;		
		for(int w = 1; w <= n; w++) {
			if(g[u][w] and g[v][w]) {
				cnt++;
			}
		}
		cnt = cnt*(cnt-1)/2;
		ans += cnt;
	}
	for(int i = 0; i < m; i++)
		for(int j = i+1; j < m; j++)
			if(g[e[j].first][e[i].first] and g[e[j].first][e[i].second] and g[e[j].second][e[i].first] and g[e[j].second][e[i].second]) ax++;;
	printf("%lld", ans-(ax*5/3)); // notice that set of pairs of 3 nodes that make up the 4 note set that have all vertices connected appear in ans 6 times
}
