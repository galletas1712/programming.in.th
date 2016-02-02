#include <cstdio>

int n, k, temp, count[2000001];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; i++) scanf("%d", &temp), count[temp]++;
	for(int i = 1999999; i >= 0; i--) 
	{
		count[i] += count[i+1];
		if(count[i] >= k) // debug
		{
			printf("%d", i);
			return 0;
		}
	}
}
