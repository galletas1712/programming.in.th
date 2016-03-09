#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int r,c,k,ans,sx[5001],sy[5001];
int main() {
	scanf("%d%d%d",&r,&c,&k);
	for(int i = 0; i < k; i++) {
		int x,y,R;
		scanf("%d%d%d",&x,&y,&R);
		for(int j = max(x-R, 1); j <= min(x+R, c); j++) sx[j]++;
		for(int j = max(y-R, 1); j <= min(y+R, r); j++) sy[j]++;
	}
	for(int i = 1; i <= r; i++) ans = max(sy[i], ans);
   	for(int i = 1; i <= c; i++) ans = max(sx[i], ans);
	printf("%d", ans);
}
