#include <bits/stdc++.h>
using namespace std;

int n, ans, mi[300001], md[300001];
vector<int> g[300001];

int dfs(int u, int p) {
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(v != p) {
            dfs(v, u);
            if(u < v) mi[u] = max(mi[v], mi[u]);
            else md[u] = max(md[v], md[u]);
        }
    }
    mi[u]++;
    md[u]++;
    ans = max(mi[u]+md[u]-1, ans);
}

int main() {
    scanf("%d",&n);
    for(int i = 1,u,v; i < n; i++) {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    printf("%d",ans);
}
