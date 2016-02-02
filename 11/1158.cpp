#include <cstdio>
#include <algorithm>
using namespace std;

int m, n, k, ans, d[1001][1001];
int main() {
	scanf("%d%d%d", &m, &n, &k);
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			int x;
			scanf("%d", &x);
			d[i][j] = d[i-1][j] + d[i][j-1] - d[i-1][j-1] + x;
		}
	}
	for(int i = k; i <= m; i++) {
		for(int j = k; j <= n; j++) {
			ans = max(d[i][j] - d[i-k][j] - d[i][j-k] + d[i-k][j-k], ans);
		}
	}
	printf("%d", ans);
}