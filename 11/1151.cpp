#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> f;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0, x; i < n; i++) {
		cin >> x;
		auto it = lower_bound(f.begin(), f.end(), x);
		if(it == f.end()) f.push_back(x);
		else *it = x;
	}
	cout << f.size();
}
