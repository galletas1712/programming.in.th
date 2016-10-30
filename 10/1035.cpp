#include <bits/stdc++.h>
using namespace std;

int n, arr[9];
bool mark[100001];
vector<int> primes;
int main() {
	scanf("%d",&n);
	for(int i = 2; i <= 100000; i++) if(!mark[i]) {
		primes.push_back(i);
		for(int j = i; j <= 100000; j += i) mark[j] = true;
	}
	for(int i = n; 1; i++) {
		int tmp = i, j = 0;
		bool valid = true;
		while(tmp) arr[j++] = tmp%10, tmp /= 10;
		for(int k = 0; k < j/2; k++) valid &= arr[k] == arr[j-k-1];
		if(valid) {
			bool prime = true;
			for(int j = 0; primes[j] <= sqrt(i); j++) prime &= (bool) (i%primes[j]);
			if(prime) {
				printf("%d", i);
				return 0;
			}
		}
	}
}
