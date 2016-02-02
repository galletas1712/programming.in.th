#include <cstdio>
#include <queue>

struct edge
{
	int u, v, w;
};

bool operator < (const edge& a, const edge& b) {
	return (a.w> b.w);
}

int n, m;
std::priority_queue<edge> pq;
bool mark[100001];
int uf[100001];

int root(int i)
{
	while(i != uf[i])
		uf[i] = uf[uf[i]], i = uf[i];
	return i;
}

bool same(int a, int b)
{
	return root(a) == root(b);
};

void un(int a, int b)
{
	uf[root(a)] = uf[root(b)];
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) uf[i] = i;
	for(int i = 0; i < m; i++)
	{
		edge e;
		scanf("%d%d%d",&e.u,&e.v,&e.w);
		pq.push(e);
	}
	int ct = 0;
	while(ct < n-1 && !pq.empty())
	{
		edge e = pq.top();
		if(!same(e.u, e.v)) printf("%d %d\n", e.u, e.v), ct++;
		pq.pop();
		un(e.u, e.v);
	}
}