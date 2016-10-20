#include <bits/stdc++.h>
using namespace std;

int r, c, s, t, ds[2501], dw[2501];
bool rock[2501];
vector<int> graph[2501];
queue<int> bs, bw;
char tmp[60];
int main() {
	scanf("%d%d",&r,&c);
	for(int i = 1; i <= r*c; i++) dw[i] = INT_MAX, ds[i] = INT_MAX;
	for(int i = 0; i < r; i++) {
		scanf("%s",tmp+1);
		for(int j = 1; j <= c; j++) {
			if(tmp[j] == 'X') {
				rock[i*c+j] = true;
				continue;
			}
			else if(tmp[j] == 'D') t = i*c+j;
			else if(tmp[j] == 'S') s = i*c+j;
			else if(tmp[j] == '*') dw[i*c+j] = 0, bw.push(i*c+j);
			if(i > 0 && !rock[(i-1)*c+j]) graph[i*c+j].push_back((i-1)*c+j), graph[(i-1)*c+j].push_back(i*c+j);
			if(j > 1 && !rock[i*c+j-1]) graph[i*c+j].push_back(i*c+j-1), graph[i*c+j-1].push_back(i*c+j);
		}
	}
	while(!bw.empty()) {
		int v = bw.front();
		bw.pop();
		for(int j = 0; j < graph[v].size(); j++) {
			if(graph[v][j] == t) continue;
			if(dw[v]+1 < dw[graph[v][j]]) bw.push(graph[v][j]), dw[graph[v][j]] = dw[v]+1;
		}
	}
	bs.push(s);
	ds[s] = 0;
	while(!bs.empty()) {
		int v = bs.front();
		bs.pop();
		for(int j = 0; j < graph[v].size(); j++) {
			if(dw[graph[v][j]] > ds[v]+1) {
				if(ds[graph[v][j]] == INT_MAX) bs.push(graph[v][j]);
				ds[graph[v][j]] = min(ds[v]+1, ds[graph[v][j]]);
			}
		}
	}
	if(ds[t] == INT_MAX) printf("KAKTUS");
	else printf("%d",ds[t]);
}
