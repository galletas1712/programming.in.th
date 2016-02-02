#include <cstdio>

int n, freq[101], grid[10][10], r[10], c[10];
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) scanf("%d", &grid[i][j]), freq[grid[i][j]]++;
	for(int i = 1; i <= n*n; i++)
	{
		if(freq[i] != 1)
		{
			printf("No");
			return 0;
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			r[i] += grid[i][j];
			c[j] += grid[i][j];
		}
	}
	int sum = r[0];
	for(int i = 0; i < n; i++)
	{
		if(r[i] != sum || c[i] != sum)
		{
			printf("No");
			return 0;
		}
	}
	int i = n-1, j = 0, d1 = 0, d2 = 0;
	while(i >= 0 && j <= n-1)
	{
		d1 += grid[i][j];
		i--;
		j++;
	}
	i = 0;
	j = n-1;
	while(i <= n-1 && j >= 0)
	{
		d2 += grid[i][j];
		i++;
		j--;
	}
	if(d1 != sum || d2 != sum)
	{
		printf("No");
		return 0;
	}
	printf("Yes");
}
