#include <cstdio>
#include <algorithm>

struct domino
{
	int x;
	int h;
};

int n, i, j, mr, ml, l[100002], r[100002];
domino d[100002], dr[100002];

int main()
{
	scanf("%d", &n);
	for(i = 1; i <= n; i++) scanf("%d%d", &d[i].x, &d[i].h);
	for(i = 1; i <= n; i++) dr[i] = d[n-i+1], dr[i].x = 2000000000 - dr[i].x;
	i = 1;
	mr = 1;
	while(i <= n)
	{
		int max = d[i].x + d[i].h;
		if(!r[i]) r[i] = 1;
		j = i+1;
		while(j <= n && d[j].x < max)
		{
			r[j] = r[j-1] + 1;
			max = std::max(max, d[j].x + d[j].h);
			if(r[j] > r[mr]) mr = j;
			j++;
		}
		i = j;
	}
	i = 1;
	ml = n;
	while(i <= n)
	{
		int max = dr[i].x + dr[i].h;
		if(!l[i]) l[i] = 1;
		j = i+1;
		while(j <= n && dr[j].x < max)
		{
			l[j] = l[j-1] + 1;
			max = std::max(max, dr[j].x + dr[j].h);
			if(l[j] >= l[ml]) ml = j;
			j++;
		}
		i = j;
	}
	int ansr = mr-r[mr]+1;
	int ansl = n-(ml-l[ml]+1)+1;
	if(l[ml] > r[mr] || (r[mr] == l[ml] && ansl <= ansr)) printf("%d L", ansl);
	else printf("%d R", ansr);
}

// try test case

/*
2
1 1
2 1
	5
   1 1
   3 3
   5 1
   6 1
   7 2

   4
   1 5
   5 4
   8 2 1
   9 1
*/
