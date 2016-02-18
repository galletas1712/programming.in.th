#include <bits/stdc++.h>
using namespace std;

int n, x[500000], y[500000];
long long ans, sx, sy;
int main() {
	scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%d%d",&x[i],&y[i]);
	sort(x, x+n);
	sort(y, y+n);
	sx = x[0];
	sy = y[0];
	for(int i = 1; i < n; i++) {
		ans += (long long) i*(long long)(x[i]+y[i])-sx-sy;
		sx += x[i];
		sy += y[i];
	}
	printf("%lld", ans);
}
