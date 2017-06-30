#include <bits/stdc++.h>
using namespace std;
const int MAX = (5e5)+1;

int n;
pair<int,int> x[MAX],y[MAX];
long long ans;
long long costx(int c) {
	long long ret = 0;
	for(int i = 1; i <= n; i++) ret += 1ll*x[i].second*abs(x[i].first-c);
	return ret;
}
long long costy(int c) {
	long long ret = 0;
	for(int i = 1; i <= n; i++) ret += 1ll*y[i].second*abs(y[i].first-c);
	return ret;
}
int main() {
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d%d",&x[i].first,&y[i].first,&x[i].second);
		y[i].second = x[i].second;
	}
	int l = 1, r = 1e9;
	while(r-l > 1) {
		int mid = l+r >> 1;
		if(costx(mid) >= costx(mid+1)) l = mid;
		else r = mid;
	}
	ans = min(costx(l), costx(r));
	l = 1, r = 1e9;
	while(r-l > 1) {
		int mid = l+r >> 1;
		if(costy(mid) >= costy(mid+1)) l = mid;
		else r = mid;
	}
	ans += min(costy(l), costy(r));
	printf("%lld", ans);
}
