#include <bits/stdc++.h>
using namespace std;
const int MAX = (1e6)+1;

int n, p, q, a[MAX];
bool inc[MAX];
long long ans;
deque<int> mx, mn;
int main() {
	scanf("%d%d%d",&n,&p,&q);
	for(int i = 0; i < n; i++) scanf("%d",a+i);

	for(int i = 0, j = 0; i < n; i++) {
		while(!mx.empty() && a[mx.back()] <= a[i]) mx.pop_back();
		while(!mn.empty() && a[mn.back()] >= a[i]) mn.pop_back();
		mx.push_back(i);
		mn.push_back(i);
		if(a[mx.front()] - a[mn.front()] < p) continue;
		int tmpmx = INT_MAX, tmpmn = INT_MAX;
		while(!mx.empty() && !mn.empty() && a[mx.front()] - a[mn.front()] >= p && j <= i) {
			++j;
			while(!mx.empty() && mx.front() < j) tmpmx = mx.front(), mx.pop_front();
			while(!mn.empty() && mn.front() < j) tmpmn = mn.front(), mn.pop_front();
		}
		ans += --j;
		inc[i] = true;
		if(tmpmx < INT_MAX) mx.push_front(tmpmx);
		if(tmpmn < INT_MAX) mn.push_front(tmpmn);
	}
	
	mx.clear();
	mn.clear();

	for(int i = 0, j = 0; i < n; i++) {
		while(!mx.empty() && a[mx.back()] <= a[i]) mx.pop_back();
		while(!mn.empty() && a[mn.back()] >= a[i]) mn.pop_back();
		mx.push_back(i);
		mn.push_back(i);
		while(!mx.empty() && !mn.empty() && a[mx.front()] - a[mn.front()] > q) {
			++j;
			while(!mx.empty() && mx.front() < j) mx.pop_front();
			while(!mn.empty() && mn.front() < j) mn.pop_front();
		}
		if(inc[i]) ans -= j - 1;
	}
	printf("%lld", ans);
}
