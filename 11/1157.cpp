#include <bits/stdc++.h>
using namespace std;

int n, k, ans, a[500001], b[500001];
map<int, int> mn;
int main() {
	scanf("%d%d",&n,&k);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	mn[a[1]]++;
	b[1] = a[1];
	for(int i = 2; i <= n; i++) {
		if(i > k) {
			if(mn[b[i-k-1]] > 1) mn[b[i-k-1]]--;
			else mn.erase(b[i-k-1]);
		} 
		b[i] = a[i] + mn.begin()->first;
		mn[b[i]]++;
	}
	printf("%d", b[n]);
}
