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































// int n, k, curr, cnt, target;
// bool out[200001];
//
// int modn(int a) {
// 	return (a % n) ? a % n: n;
// }
//
// struct fenwick {
// 	int sum[200001];
//
// 	void add(int pos) {
// 		for(int i = pos; i <= n; i += i & (-i)) sum[i]++;
// 	}
//
// 	int get(int l, int r) {
// 		return get(r) - get(l-1);
// 	}
//
// 	int get(int pos) {
// 		int ans = 0;
// 		for(int i = pos; i > 0; i -= i & (-i)) ans += sum[i];
// 		return ans;
// 	}
// } cut;
//
// int nxt(int l, int r, int s) {
// 	int mid, res;
// 	if(r < l) mid = modn((l+r+n)/2);
// 	else mid = modn((l+r)/2);
//
// 	if(l == r) return mid;
//
// 	if(mid > s) res = mid-s-cut.get(s+1, mid);
// 	else if(mid < s) res = mid+n-s-(cut.get(1,mid)+cut.get(s+1, n));
// 	else {
// 		if(out[r]) res =  0;
// 		else res = 1;
// 	}
//
// 	if(res > target) return nxt(l, mid, s);
// 	else if(res < target) return nxt(mid+1, r, s);
// 	else return mid;
// }
//
// int main() {
// 	scanf("%d%d",&n,&k);
// 	curr = k;
// 	cnt = n;
// 	while(cnt > 1) {
// 		cut.add(curr);
// 		out[curr] = true;
// 		cnt--;
// 		target = k%cnt;
// 		if(!target) target = cnt;
// 		curr = nxt(modn(curr+1), modn(curr-1), curr);
// 	}
// 	printf("%d", curr);
// }
