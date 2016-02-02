#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int m, x, y, t[402], ans = -10000;
vector<int> adjl[402];
bool mark[402];

void add(int k)
{
	if(t[k] == 100) return;
	int n = k-m, e = k+1, s = k+m, w = k-1;
	if(n >= 1 && t[n] > t[k] && t[n] != 100) adjl[k].push_back(n);
	if(e % m <= m && t[e] > t[k] && t[e] != 100) adjl[k].push_back(e);
	if(s <= m*m && t[s] > t[k] && t[s] != 100) adjl[k].push_back(s);
	if(w % m >= 1 && t[w] > t[k] && t[w] != 100) adjl[k].push_back(w);
}

void maxdfs(int s)
{
	mark[s] = true;
	ans = max(t[s], ans);
	for(int i = 0; i < adjl[s].size(); i++)
		if(!mark[adjl[s][i]]) maxdfs(adjl[s][i]);
}

int main()
{
	scanf("%d %d %d", &m, &x, &y);
	for(int i = 1; i <= m*m; i++) scanf("%d", &t[i]);
	for(int i = 1; i <= m*m; i++) add(i);
	maxdfs(m * (y-1) + x);
	printf("%d", ans);
}
