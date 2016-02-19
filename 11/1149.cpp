#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int n, grid[1001][1001];
bool vis[1001][1001];
vector<pii> s;

void clean() {
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) vis[i][j] = false;
}

bool can(int k) {
	queue<pii> q;
	q.push(s[0]);
	while(!q.empty()) {
		pii v = q.front();
		q.pop();
		if(vis[v.first][v.second]) continue;
		vis[v.first][v.second] = true;
		
		if(v == s[1]) {
			clean();
			return true;
		}

		if(v.first > 1 and grid[v.first-1][v.second] <= k and !vis[v.first-1][v.second]) q.push(make_pair(v.first-1,v.second));
		if(v.second > 1 and grid[v.first][v.second-1] <= k and !vis[v.first][v.second-1]) q.push(make_pair(v.first,v.second-1));
		if(v.first < n and grid[v.first+1][v.second] <= k and !vis[v.first+1][v.second]) q.push(make_pair(v.first+1,v.second));
		if(v.second < n and grid[v.first][v.second+1] <= k and !vis[v.first][v.second+1]) q.push(make_pair(v.first,v.second+1));
	}
	clean();
	return false;
}

int solve(int l, int r) {
	int mid = (l+r)/2;
	if(l == r) return mid;
	if(can(mid)) return solve(l, mid);
	else return solve(mid+1, r);
}

int main() {
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d",&grid[i][j]);
			if(!grid[i][j]) s.push_back(make_pair(i, j));
		}
	}
	printf("%d", solve(1, 1000000));
}
