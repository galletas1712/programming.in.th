#include <bits/stdc++.h>
using namespace std;

int n, cnt[100001];
long long ans = 1;
int main() {
	scanf("%d",&n);
	for(int i = 0, a; i < n; i++) {
		scanf("%d",&a);
		int org = a;
		for(int j = 2; j <= min(a-1, 1000); j++) {
			int c = 0;
			while(!(a%j)) c++, a /= j;
			cnt[j] = max(c, cnt[j]);
		}
		cnt[a] = max(1, cnt[a]);
	}
	for(int j = 2; j <= 100000; j++) while(cnt[j]--) ans *= j;
	printf("%lld", ans);
}
