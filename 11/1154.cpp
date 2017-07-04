#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e4;
const ll B1 = 31, B2 = 37, M1 = (1e9)+7, M2 = (1e9)+9;

int n, m;
char s[MAX];
ll modPow(ll b, ll e, ll mod) {
	if(e == 0) return 1ll;
	else if(e == 1) return b;
	else return modPow(b*b%mod, e >> 1, mod)*modPow(b, e & 1, mod)%mod;
}
bool check(int len) {
	map<pair<ll, ll>, int> f;
	ll h1 = 0, h2 = 0, p1 = 1, p2 = 1;
	for(int i = len-1; i >= 0; i--, p1 = (p1*B1)%M1, p2 = (p2*B2)%M2) {
		h1 = (h1 + p1*(s[i]-'a'))%M1;
		h2 = (h2 + p2*(s[i]-'a'))%M2;
	}
	f[make_pair(h1, h2)]++;
	for(int i = len; i < n; i++) {
		h1 = ((h1 - (modPow(B1, len-1, M1)*(s[i-len]-'a'))%M1 + M1)%M1*B1 + (s[i]-'a'))%M1;
		h2 = ((h2 - (modPow(B2, len-1, M2)*(s[i-len]-'a'))%M2 + M2)%M2*B2 + (s[i]-'a'))%M2;
		f[make_pair(h1, h2)]++;
	}
	for(auto p: f) if(p.second >= m) return true;
	return false;
}
int main() {
	scanf("%d%d%s",&n,&m,s);
	int l = 0, r = n;
	while(l < r) {
		int mid = l+r+1 >> 1;
		if(check(mid)) l = mid;
		else r = mid-1;
	}
	printf("%d", l);
}
