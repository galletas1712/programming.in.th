#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

int k, n, m, dist[10001];
std::vector<int> floor[10001];
bool mark[10001];

void bfs(int s)
{
	std::queue<int> q;
	q.push(s);
	dist[s] = 0;
	while(!q.empty())
	{
		int ss = q.front();
		q.pop();
		for(int i = 0; i < floor[ss].size(); i++)
		{
			if(!mark[floor[ss][i]]) q.push(floor[ss][i]), mark[floor[ss][i]] = true;
			dist[floor[ss][i]] = std::min(dist[ss] + 1, dist[floor[ss][i]]);
		}
	}
}

int main()
{
	scanf("%d%d%d", &k, &n, &m);
	for(int i = 1; i <= n; i++) dist[i] = 100000000;
	for(int i = 1; i <= m; i++) 
	{
		int a, b;
		scanf("%d%d", &a, &b);
		floor[a].push_back(b);
	}
	bfs(1);
	int max = 1;
	for(int i = 1; i <= n; i++)
		if(dist[i] >= dist[max] && dist[i] <= k && dist[i] > 0) max = i;
	printf("%d", max);
}
