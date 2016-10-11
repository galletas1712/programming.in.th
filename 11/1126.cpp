/*
Solution:
First, consider the case where there is only 1 prime.
We will find the number of sequences where each term is that prime raised to a certain power.
All terms will be greater than or equal to the prime itself, and will have value less than prime^k
We get formula for DP: dp[product][len] = sum(j = max(i-k-1, 0) -> i-1) of dp[j][len-1]
We can do state space reduction for second dimension to get memory efficient solution.

1001 has 3 primes: 7, 11, 13
The answer for 3 primes is the sum of the cubes of number of sequences (one prime) for each length,
The resulting sequences are always valid, because the elements for each prime
don't exceed power of k and not less than power of 1 and when multiplying primes together,
its degree cannot increase. Therefore, we have correct solution.
*/

#include <bits/stdc++.h>
using namespace std;
const int MOD = 2553;

int n, k, ans, dp[5001][2];
int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = dp[i-1][0];
        if(i <= k) dp[i][0]++, dp[i][0] %= MOD;
    } // base case
    if(k == n) ans++, ans %= MOD;
    for(int len = 2; len <= n; len++) {
        for(int i = 1; i <= n; i++) dp[i][1] = (dp[i-1][1]+dp[i-1][0]-dp[max(i-k-1, 0)][0])%MOD;
        for(int i = 1; i <= n; i++) dp[i][0] = dp[i][1];
        int res = (dp[n][0] - dp[n-1][0] + MOD)%MOD;
        ans += (((res*res)%MOD)*res)%MOD;
        ans %= MOD;
    }
    cout << ans;
}
