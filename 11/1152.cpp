#include <bits/stdc++.h>
using namespace std;

int n;
long long ans, grid[1010][1010];
priority_queue<long long> heap;
int main() {
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) scanf("%lld",&grid[i][j]);
	for(int k = n; k >= 1; k--) {
		for(int i = 0; i <= n-k; i++) heap.push(grid[n-i][k+i]);
		ans += heap.top(), heap.pop();
	}
	for(int k = n-1; k >= 2; k--) {
		for(int i = 0; i < k; i++) heap.push(grid[k-i][i+1]);
		ans += heap.top(), heap.pop();
	}
	printf("%lld",ans);
}