#include <bits/stdc++.h>
using namespace std;

int n, a[10], res[101][101];
pair<int, int> mn;
int main() {
	scanf("%d", &n);
	mn.second = INT_MAX;
	for(int i = 1; i <= 9; i++) {
		scanf("%d", &a[i]);
		if(a[i] <= mn.second) mn.first = i, mn.second = a[i];	
	}
	int len = n/mn.second, cost = mn.second*len;
	for(int i = 1; i <= len; i++) res[len][i] = mn.first;
	for(int i = 1; i <= len; i++) {
		int last = mn.second;
		for(int j = mn.first+1; j <= 9; j++) {
			if(cost - last + a[j] <= n) {
				cost += a[j] - last;
				res[len][i] = j;
				last = a[j];
			}
		}
	}
	for(int i = 1; i <= len; i++) printf("%d",res[len][i]);
}
