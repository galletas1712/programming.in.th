#include <bits/stdc++.h>
using namespace std;

int n, w[601][601], dp[601];
int main() {
	scanf("%d", &n);
	for(int i = 1; i < 2*n; i++) dp[i] = INT_MAX;
	for(int i = 1; i <= 2*n; i++)
		for(int j = 1; j <= 2*n; j++) scanf("%d", &w[i][j]);
	for(int i = 2*n-1; i >= 2; i--)
		for(int j = i+1; j <= 2*n; j++) dp[i] = min(dp[j] + w[j][i], dp[i]);
	printf("%d", dp[2]);
}
