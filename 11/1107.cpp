#include <bits/stdc++.h>
using namespace std;

int n, k, p, a[1000001];
bool m[1000001];

bool check(int lim) {
	bool exists = false;
	for(int i = 0; i < n; i++) if(a[i] <= lim) exists |= 1;
	if(!exists) return false;
	fill(m, m+n, 0);
	int t = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] <= lim) continue;
		t++;
		int j;
		for(j = 0; j < min(n-i, p); j++) m[i+j] = 1;
		for(j = min(n-i-1, p-1); j >= 0 and a[i+j] <= lim; j--) m[i+j] = 0;
		i += j;
	}
	exists = false;
	for(int i = 0; i < n; i++) if(!m[i]) exists |= 1;
	if(exists) return t <= k;
	else return t+1 <= k;
}

int main() {
	scanf("%d%d%d",&n,&k,&p);
	for(int i = 0; i < n; i++) scanf("%d",a+i);
	int l = 1, r = (1e9)+11;
	while(l < r) {
		int mid = l+r>>1;
		if(check(mid)) r = mid;
		else l = mid+1;
	}
	printf("%d", l);
}
