#include <bits/stdc++.h>
using namespace std;
const int MAX = 1 << 17;

int n, f[MAX];
vector<pair<int,int> > masts;
long long ans;
void update(int i, int v) {
	assert(i != MAX);
	i = MAX - i;
	while(i < MAX) f[i] += v, i += i & -i;
}
int query(int i) {
	i = MAX - i;
	int ret = 0;
	while(i > 0) ret += f[i], i -= i & -i;
	return ret;
}
int get_bound(int v, function<bool (int, int)> comp) { // less for r, less_equal for lb
	int ret = 0;
	for(int j = 16; j >= 0; j--) {
		if(comp(f[ret + (1 << j)], v)) {
			v -= f[ret + (1 << j)];
			ret += 1 << j;
		}
	}
	return MAX - ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0, h, k; i < n; i++) {
		cin >> h >> k;
		masts.emplace_back(h, k);
	}
	sort(masts.begin(), masts.end());
	for(int i = 0, h, k; i < n; i++) {
		tie(h, k) = masts[i];

		int idx = h-k+1, v = query(idx);
		int r = min(get_bound(v, less<int>()), h+1);
		update(h, 1);
		update(r-1, -1);

		int	residue = r - idx;
		int lb = get_bound(v, less_equal<int>());
		update(lb+residue-1, 1);
		update(lb-1, -1);

		// bounds are shifted by one because of reverse fenwick
	}
	for(int i = 1; i < MAX; i++) {
		long long res = query(i);
		ans += res*(res-1) >> 1;
	}
	cout << ans;
}
