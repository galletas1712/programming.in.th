#include <bits/stdc++.h>
using namespace std;

int n,t,p,tval[2001], score[2001], ans[2001];
vector<int> complete[2001];

bool comp(int a, int b) {
	if(score[a] > score[b]) return true;
	else if(score[a] < score[b]) return false;
	if(complete[a].size() > complete[b].size()) return true;
	else if(complete[a].size() < complete[b].size()) return false;
	if(a < b) return true;
	else return false;
}

int main() {
	scanf("%d%d%d",&n,&t,&p);
	for(int i = 1; i <= n; i++) {
		ans[i] = i;
		for(int j = 1; j <= t; j++) {
			int x;
			scanf("%d",&x);
			if(!x) tval[j]++;
			else complete[i].push_back(j);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(vector<int>::iterator it = complete[i].begin(); it != complete[i].end(); it++) {
			score[i] += tval[(*it)];
		}
	}
	sort(ans+1, ans+n+1, comp);
	for(int i = 1; i <= n; i++) {
		if(ans[i] == p) {
			printf("%d %d", score[p], i);
			return 0;
		}
	}
}
