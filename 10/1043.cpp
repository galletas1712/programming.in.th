#include <cstdio>
#include <cmath>

int n;
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int y;
		bool found = false;
		scanf("%d", &y);
		for(int k = 27; k > 1; k--) 
		{
			int root = floor(pow(y, 1.0/k)+0.5);
			int ty = floor(pow(root, k)+0.5);
			if(ty == y)
			{
				found = true;
				printf("%d\n", k);
				break;
			}
		}
		if(!found) printf("NO\n");
	}
}
