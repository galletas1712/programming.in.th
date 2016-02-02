#include <cstdio>
using namespace std;

int lines[10001]; // index = line id, val = line round
int rounds[100001][3]; // index = round id, val0 = player id, val1 = player speed
int runners[100001][3]; // index = queue, val0 = player id, val1 = line, val2 = speed

int main(){
	int n, m, nrounds=0;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d %d %d", &runners[i][0], &runners[i][1], &runners[i][2]);
	for(int i = 1; i <= n; i++){
		int a = runners[i][0],l = runners[i][1],s = runners[i][2];
		lines[l]++;
		if(nrounds < lines[l]) nrounds = lines[l];
		if((s > rounds[lines[l]][2]) || (s == rounds[lines[l]][2] && l < rounds[lines[l]][1])){
			rounds[lines[l]][0] = a;
			rounds[lines[l]][1] = l;
			rounds[lines[l]][2] = s;
		}
	}
	for(int i = 1; i <= nrounds; i++) printf("%d\n", rounds[i][0]);
}