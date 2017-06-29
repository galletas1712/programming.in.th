#include <bits/stdc++.h>
using namespace std;
const int MAX = (1e5)+1;

struct node {
	int l, r, cost;
};

bool operator<(node a, node b) {
	return a.cost > b.cost;
}

int n, k, ans, a[MAX], pre[MAX], nxt[MAX], dist[MAX];
bool mark[MAX];
priority_queue<node> pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = i-1;
		nxt[i] = i+1;
		dist[i] = a[i] - a[i-1];
		if(i > 1) pq.push({i-1, i, dist[i]});
	}
	int cnt = 0;
	while(!pq.empty() && cnt < k) {
		int l = pq.top().l, r = pq.top().r, cost = pq.top().cost;
		pq.pop();
		if(mark[l] || mark[r]) continue;
		ans += cost;
		cnt++;
		mark[l] = mark[r] = true;
		int ll = pre[l], rr = nxt[r];
		pre[rr] = ll, nxt[ll] = rr;
		dist[rr] = dist[rr] + dist[l] - dist[r];
		if(ll >= 1 && rr <= n && !mark[ll] && !mark[rr]) {
			pq.push({ll, rr, dist[rr]});
		}
	}
	assert(cnt == k);
	cout << ans;
}
