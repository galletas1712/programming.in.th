#include <bits/stdc++.h>
using namespace std;

int n, a[1001], ans;
bool dp[60001], tmp[60001];
int main() {
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
	dp[30000] = true;
	for(int i = 1; i <= n; i++) {
		for(int k = 0; k <= 60000; k++) {
			int x = k-a[i];
			if(x < 0) x = 60000+x+1;
			if(x > 60000) x -= 60001;
			tmp[k] |= dp[x];
		}
		for(int k = 0; k <= 60000; k++) dp[k] |= tmp[k], tmp[k] = false;
	}
	for(int k = 0; k <= 60000; k++)
		if(dp[k]) ans = k-30000;
	printf("%d",ans);
}
