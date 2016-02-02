#include <cstdio>
#define ull unsigned long long

// Series solution
/*ull n, ans, temp, a;
int main()
{
	scanf("%lld", &n);
	for(int i = 0; i < n; i++)
	{   
		a = (n-i)*(n-i+1)/2;
		scanf("%lld", &temp);
		ans += (a*temp) % 2553; 
	}
	printf("%lld", ans);
}*/


/* DP solution */
ull n, sum[1000000], dp[1000000], ans;
int main()
{
	scanf("%lld %lld", &n, &sum[0]);
	ans = dp[0] = sum[0];
	for(int i = 1; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		sum[i] = sum[i-1] + a;
		dp[i] = dp[i-1] + sum[i];
		ans += dp[i];
		sum[i] %= 2553;
		dp[i] %= 2553;
		ans %= 2553;
	}
	printf("%lld", ans);
}


/* Working
n = 10
0 0 0

1 0 0

1 1 0
1 1 1

2 0 0

2 1 0
2 1 1

2 2 0
2 2 1
2 2 2

3 0 0

3 1 0
3 1 1

3 2 0
3 2 1
3 2 2

3 3 0
3 3 1
3 3 2
3 3 3

series a[i] freq is 1+2+3.......n-i+1

dp
old sum + old curr (old sum of last set) + n
old = n-1

*/
