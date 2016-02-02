#include <cstdio>
#include <climits>
#include <algorithm>

int n, k, dp[257];
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 0; i <= 256; i++) dp[i] = INT_MAX;
	for(int i=0;i<n;i++)
	{
		int wi, val = 0;
		scanf("%d", &wi);
		for(int j=0;j<k;j++)
		{
			int temp;
			scanf("%d", &temp);
			val += temp << (k-j-1);
		}
		dp[val] = std::min(wi, dp[val]);
	}
	for(int i = 1; i <= 256; i++)
	{
		for(int j = i-1; j > 0; j--)
		{
			if(dp[i] != INT_MAX && dp[j] != INT_MAX) dp[i | j] = std::min(dp[i] + dp[j], dp[i | j]);
		}
	}
	printf("%d", dp[(1<<k)-1]);
}
