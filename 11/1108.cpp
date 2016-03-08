#include <bits/stdc++.h>
using namespace std;

int n, k;
long long mx[1000001], dp[1000001], sum[1000001];
deque<int> q;
int main() {
	scanf("%d%d",&n,&k);
	for(int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		sum[i] = sum[i-1] + a;
	}
	int j = 0;
	for(int i = 1; i <= n; i++) {
		while(sum[i] - sum[j] > k) j++;

		while(!q.empty() and q.front() <= j) q.pop_front();
		
		if(i > 2) mx[i] = dp[i-2] - sum[i-1];
		else mx[i] = -sum[i-1];
		
		while(!q.empty() and mx[q.back()] <= mx[i]) q.pop_back();
		q.push_back(i);

		dp[i] = max(sum[i] + mx[q.front()], dp[i-1]);
		
		if(i == j) dp[i] = dp[i-1];
	}
	printf("%lld", dp[n]);
}
