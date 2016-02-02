#include <cstdio>

int n,m,x,y,k,a[1001][1001],b[1001][1001]; // a = whether the box has a key or not, b = sum of the keys in the rectangle from (0,0) to (i,j)
int main()
{
	scanf("%d%d", &n, &m);
	
	// recv values
	for(int i = 0; i < n; i++)
	{
		int cx,cy;
		scanf("%d%d", &cx, &cy);
		a[cx][cy]++;
	}
	
	// dp memorization
	for(int i = 0; i <= 1000; i++)
	{
		for(int j = 0; j <= 1000; j++)
		{
			int imj = 0, ijm = 0, imjm = 0;
			if(i > 0) imj = b[i-1][j];
			if(j > 0) ijm = b[i][j-1];
			if(i > 0 && j > 0) imjm = b[i-1][j-1];
			b[i][j] = imj + ijm - imjm + a[i][j];
		}
	}
	
	// handle queries
	for(int i = 0; i < m; i++)
	{
		// xp = x+k, yp = y+k
		// using formula sum(i, j) - sum(i-k, j) - sum(i, j-k) + sum(i-k, j-k)
		scanf("%d%d%d", &x, &y, &k);
		int xp = 1000, yp = 1000, sum;
		if(y+k <= 1000) yp = y+k;
		if(x+k <= 1000) xp = x+k;
		sum = b[xp][yp];
		if(x-k-1 >= 0) sum -= b[x-k-1][yp];
		if(y-k-1 >= 0) sum -= b[xp][y-k-1];
		if(x-k-1 >= 0 && y-k-1 >= 0) sum += b[x-k-1][y-k-1];
		printf("%d\n", sum);
	}
}
