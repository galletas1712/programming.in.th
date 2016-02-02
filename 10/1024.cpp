#include <cstdio>
#include <cstdlib>

int tmp, n, *num, sum,*sums, mean, s1, s2, t1, t2, MIN = 1001;

int max(int a, int b, int c)
{
	int arr[3] = {a,b,c};
	int max = a;
	for(int i = 1; i < 3; i++)
		if(arr[i] > max) max = arr[i];
	return max;
}

int min(int a, int b, int c)
{
	int arr[3] = {a,b,c};
	int m = a;
	for(int i = 1; i < 3; i++)
		if(arr[i] < m) m = arr[i];
	return m;
}

int main()
{
	scanf("%d", &n);
	num = new int[n];
	sums = new int[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
		sum += num[i];
		if(i > 0) sums[i] += sums[i-1] + num[i];
		else sums[i] = num[i];
	}
	mean = sum/3;
	tmp = 0;
	for(int i = 0; i < n-2; i++)
	{
		tmp += num[i];
		int dif = abs(tmp - mean);
		if(dif <= MIN) MIN = dif, s1 = i;
	}
	tmp = 0;
	MIN = 1001;
	for(int i = s1+1; i < n-1; i++)
	{
		tmp += num[i];
		int dif = abs(tmp-mean);
		if(dif <= MIN) MIN = dif, t1 = i;
	}
	tmp = 0;
	MIN = 1001;
	for(int i = n-1; i > 1; i--)
	{
		tmp += num[i];
		int dif = abs(tmp-mean);
		if(dif <= MIN) MIN = dif, t2 = i;
	}
	tmp = 0;
	MIN = 1001;
	for(int i = t2-1; i > 0; i--)
	{
		tmp += num[i];
		int dif = abs(tmp-mean);
		if(dif <= MIN) MIN = dif, s2 = i;
	}
	s1++;
	t1++;
	int s11 = sums[s1-1];
	int s21 = sums[t1-1] - sums[s1-1];
	int s31 = sums[n-1] - sums[t1-1];
	int s12 = sums[s2-1];
	int s22 = sums[t2-1] - sums[s2-1];
	int s32 = sums[n-1] - sums[t2-1];
	int dif1 =max(s11, s21, s31) - min(s11, s21, s31);
	int dif2 =max(s12, s22, s32)-min(s12, s22, s32);  
	if(dif1 <= dif2) printf("%d %d", s1+1, t1+1);
	else printf("%d %d", s2+1, t2+1);
}
