#include <bits/stdc++.h>
using namespace std;

int n, q;
struct node {
	int x, l, r;
};

struct tree {
	node st[1000000];
	void init(int curr , int l , int r ){
		st[curr].x = 0;
		st[curr].l = l;
		st[curr].r = r;

		if(l == r) return ;

		int mid = l + r >> 1 ;

		init(2*curr , l , mid);
		init(2*curr + 1 , mid + 1 , r);
	}

	void update(int curr, int index, int val) {
		if(st[curr].l == st[curr].r) {
			st[curr].x = val;
			return;
		}
		
		int mid = st[curr].l+st[curr].r>>1;

		if(index >= st[curr].l and index <= mid) update(2*curr, index, val);
		else if(index >= mid+1 and index <= st[curr].r) update(2*curr+1, index, val);
		st[curr].x = max(st[2*curr].x, st[2*curr+1].x);
	}

	int query(int curr, int l, int r) {
		if(st[curr].l > r or st[curr].r < l) return INT_MIN; // bc max
		if(st[curr].l >= l and st[curr].r <= r) return st[curr].x;
		return max(query(2*curr, l, r), query(2*curr+1, l, r));
	}
} t;
int main() {
	scanf("%d%d", &n, &q);
	t.init(1, 1, n);
	for(int i = 0; i < q; i++) {
		char inst;
		cin >> inst;
		if(inst == 'U') {
			int a, b;
			scanf("%d%d",&a, &b);
			t.update(1, a, b);
		} else if(inst == 'P') {
			int a, b;
			scanf("%d%d", &a, &b);
			printf("%d\n", t.query(1, a, b));
		}
	}
}