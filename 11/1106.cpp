#include <bits/stdc++.h>
using namespace std;

int n, k, f[200001];
void update(int i) { while(i <= n) f[i]++, i += i & -i; }
int sum(int i) {
	int ret = 0;
	while(i > 0) ret += f[i], i -= i & -i;
	return ret;
}
int sum(int l, int r) {
	if(l > r) return sum(n) - sum(l-1) + sum(r);
	else return sum(r) - sum(l-1);
}
int dist(int i, int len) {
	if(i+len > n) return len-(sum(n)-sum(i)+sum(i+len-n));
	else return len-(sum(i+len)-sum(i));
}
int main() {
	scanf("%d%d",&n,&k);
	int cnt = n;
	while(--cnt) {
		update(k);
		int l = 0, r = n-1;
		while(l < r) {
			int mid = l+r >> 1;
			if(dist(k, mid) < (k-1)%cnt+1) l = mid+1;
			else r = mid;
		}
		k = (k+l-1)%n+1;
	}
	printf("%d", k);
}
