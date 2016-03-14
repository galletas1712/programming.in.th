#include <bits/stdc++.h>
#define misi map<int, set<int> >
using namespace std;

int n, k, ls, mr, f[1000001], pk[1000001];
vector<int> mp[2000001];
long long cnt;

int main() {
	scanf("%d%d",&n,&k);
	mp[1000000].push_back(0);
	for(int i = 1; i <= n; i++) {
		int a;
		scanf("%d",&a);
		pk[i] = pk[i-1];
		if(a < k) ls++;
		else if(a > k) mr++;
		else pk[i] = i;
		f[i] = ls - mr + 1000000;
		mp[f[i]].push_back(i);
	}
	for(int i = 2; i <= n; i++) {
		if(pk[i]) {
			vector<int>::iterator it = lower_bound(mp[f[i]].begin(), mp[f[i]].end(), pk[i]);
			if(it != mp[f[i]].end()) {
				int res = distance(mp[f[i]].begin(), it);
				cnt += res;
				/*printf("%d:\n", i);
				for(set<int>::iterator itx = mp[f[i]].begin(); itx != it; itx++) printf("%d ", *itx);
				printf("\n");*/
			}
		}
	}
	printf("%lld", cnt);
}
