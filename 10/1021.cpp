#include <cstdio>
#include <queue>

int n;
std::priority_queue<int> prices;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		char c;
		scanf(" %c", &c);
		if(c == 'P')
		{
			int price;
			scanf("%d", &price);
			prices.push(price);
		}
		else if(c == 'Q')
		{
			if(!prices.empty())
			{
				printf("%d\n", prices.top()), prices.pop();	
			}
			else
			{
				printf("-1\n");
			}
		}
	}
}