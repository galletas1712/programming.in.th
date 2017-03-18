#include <bits/stdc++.h>
using namespace std;

int n;
double fact[26];
int main() {
	scanf("%d",&n);
	fact[0] = 1;
	for(int i = 1; i <= n; i++) fact[i] = fact[i-1]*(double)i;
	double res = fact[n]/(fact[n/2]*fact[(n+1)/2]);
	if(n%2) res *= 2;
	printf("%.0lf",res);
}
