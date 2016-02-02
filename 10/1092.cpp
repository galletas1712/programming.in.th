#include <cstdio>

// uses quick union. Finding roots is O(lg n), so the output is produced in O(n lg n).
int n, m, soldier[100001], general[100001];
int root(int k)
{
	while(general[k] != k) k = general[k] = general[general[k]];
	return k;
}

void beat(int p, int q)
{
	int i = root(p);
	int j = root(q);
	if(i == j) return;
	general[j] = general[i];
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		general[i] = i;
		scanf("%d", &soldier[i]);
	}
	for(int i = 1; i <= m; i++)
	{
		int a, b, ga, gb;
		scanf("%d%d", &a, &b);
		ga = root(a);
		gb = root(b);
		if(ga != gb)
		{
			if(soldier[ga] > soldier[gb] || (soldier[ga] == soldier[gb] && ga < gb))
			{ 
				beat(ga, gb); 
				printf("%d\n", ga); 
				soldier[ga] += soldier[gb]/2; 
				soldier[gb] /= 2;
			}
			else if(soldier[ga] < soldier[gb] || (soldier[ga] == soldier[gb] && ga > gb))
			{
				beat(gb, ga);
				printf("%d\n", gb);
				soldier[gb] += soldier[ga]/2;
				soldier[ga] /= 2;
			}
		}
		else printf("-1\n");
	}
}
