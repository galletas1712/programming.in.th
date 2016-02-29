#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int n;
long long ans;
vector<pii> pairs;

struct fenwick {
	
	long long f[100001];

	void update(int pos, int val) {
		while(pos <= n) f[pos] += val, pos += pos & (-pos);
	}

	long long query(int l, int r) {
		return query(r) - query(l-1);
	}

	long long query(int pos) {
		long long ret = 0;
		while(pos > 0) ret += f[pos], pos -= pos & (-pos);
		return ret;
	}

} ft, cnt;

bool comp(pii a, pii b) {
	if(a.first < b.first) return true;
	else if(a.first == b.first and a.second > b.second) return true;
	else return false;
}

int main() {
	scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		pii tmp;
		scanf("%d%d",&tmp.first,&tmp.second);
		pairs.push_back(tmp);
	}
	sort(pairs.begin(), pairs.end(), comp);
	for(int i = 0; i < n; i++) {
		vector<pii>::iterator it = lower_bound(pairs.begin(), pairs.begin()+i, make_pair(pairs[i].first-1, 0));
		if(it != pairs.end()) ans += cnt.query(pairs[i].second+1, n)*pairs[i].first + ft.query(pairs[i].second+1, n);
		ft.update(pairs[i].second, pairs[i].first);
		cnt.update(pairs[i].second, 1);
	}
	printf("%lld", ans);
}
