#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int n, m, cnt, ans = INT_MAX, g[151][151], dist_s[151][151], dist_e[151][151];
pii s, e;
set<pii> zs, ze;
queue<pii> q;
int main() {
	scanf("%d%d%d%d%d%d",&m,&n,&s.first,&s.second,&e.first,&e.second);
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &g[i][j]), dist_s[i][j] = dist_e[i][j] = INT_MAX;
	dist_s[s.first][s.second] = dist_e[e.first][e.second] = 1;
	q.push(s);
	while(!q.empty()) {
		pii u = q.front();
		q.pop();
		if(u.first > 1 and dist_s[u.first-1][u.second] == INT_MAX) {
			dist_s[u.first-1][u.second] = dist_s[u.first][u.second] + 1;
			if(g[u.first-1][u.second]) q.push(make_pair(u.first-1, u.second));
			else zs.insert(make_pair(u.first-1, u.second));
		}
		if(u.first < m and dist_s[u.first+1][u.second] == INT_MAX) {
			dist_s[u.first+1][u.second] = dist_s[u.first][u.second] + 1;
			if(g[u.first+1][u.second]) q.push(make_pair(u.first+1, u.second));
			else zs.insert(make_pair(u.first+1, u.second));
		}
		if(u.second > 1 and dist_s[u.first][u.second-1] == INT_MAX) {
			dist_s[u.first][u.second-1] = dist_s[u.first][u.second] + 1;
			if(g[u.first][u.second-1]) q.push(make_pair(u.first, u.second-1));
			else zs.insert(make_pair(u.first, u.second-1));
		}
		if(u.second < n and dist_s[u.first][u.second+1] == INT_MAX) {
			dist_s[u.first][u.second+1] = dist_s[u.first][u.second] + 1;
			if(g[u.first][u.second+1]) q.push(make_pair(u.first, u.second+1));
			else zs.insert(make_pair(u.first, u.second+1));
		}
	}
	q.push(e);
	while(!q.empty()) {
		pii u = q.front();
		q.pop();
		if(u.first > 1 and dist_e[u.first-1][u.second] == INT_MAX) {
			dist_e[u.first-1][u.second] = dist_e[u.first][u.second] + 1;
			if(g[u.first-1][u.second]) q.push(make_pair(u.first-1, u.second));
			else ze.insert(make_pair(u.first-1, u.second));
		}
		if(u.first < m and dist_e[u.first+1][u.second] == INT_MAX) {
			dist_e[u.first+1][u.second] = dist_e[u.first][u.second] + 1;
			if(g[u.first+1][u.second]) q.push(make_pair(u.first+1, u.second));
			else ze.insert(make_pair(u.first+1, u.second));
		}
		if(u.second > 1 and dist_e[u.first][u.second-1] == INT_MAX) {
			dist_e[u.first][u.second-1] = dist_e[u.first][u.second] + 1;
			if(g[u.first][u.second-1]) q.push(make_pair(u.first, u.second-1));
			else ze.insert(make_pair(u.first, u.second-1));
		}
		if(u.second < n and dist_e[u.first][u.second+1] == INT_MAX) {
			dist_e[u.first][u.second+1] = dist_e[u.first][u.second] + 1;
			if(g[u.first][u.second+1]) q.push(make_pair(u.first, u.second+1));
			else ze.insert(make_pair(u.first, u.second+1));
		}
	}
	for(set<pii>::iterator its = zs.begin(); its != zs.end(); its++) {
		set<pii>::iterator ite = ze.find(*its);
		if(ite != ze.end()) cnt++, ans = min(dist_s[its->first][its->second] + dist_e[its->first][its->second] - 1, ans);
	}
	printf("%d\n%d", cnt, ans);	
}
