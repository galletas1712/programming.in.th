#include <bits/stdc++.h>
using namespace std;

int n, m, nxt = 1, r[101], slot[2001], w[2001];
long long ans;
queue<int> wait;
priority_queue<int, vector<int>, greater<int> > avail;
int main() {
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++) scanf("%d", &r[i]), avail.push(i);
	for(int i = 1; i <= m; i++) scanf("%d", &w[i]);
	for(int i = 1; i <= 2*m; i++) {
		int x;
		scanf("%d", &x);
		if(x > 0) {
			if(wait.empty() && !avail.empty()) slot[x] = avail.top(), avail.pop();
			else wait.push(x);
		} else {
			x *= -1;
			ans += r[slot[x]]*w[x];
			avail.push(slot[x]);
			slot[x] = 0;
			if(!wait.empty()) {
				slot[wait.front()] = avail.top();
				avail.pop();
				wait.pop();
			}
		}
	}
	printf("%lld", ans);
}
