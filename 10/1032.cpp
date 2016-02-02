#include <cstdio>
using namespace std;

int n;
int start[9][9];
int charts[100][9][9];

bool checkRows(int a){
	for(int i = 0; i < 9; i++){
		int ck[10] = {0,0,0,0,0,0,0,0,0};
		for(int j = 0; j < 9; j++){
			ck[charts[a][i][j]]++;
		}
		for(int j = 1; j <= 9; j++){
			if(ck[j] != 1) return false;
		}
	}
	return true;
}

bool checkCol(int a){
	for(int i = 0; i < 9; i++){
		int ck[10] = {0,0,0,0,0,0,0,0,0};
		for(int j = 0; j < 9; j++){
			ck[charts[a][j][i]]++;
		}
		for(int j = 1; j <= 9; j++){
			if(ck[j] != 1) return false;
		}
	}
	return true;
}

bool checkGrid(int t){
	for(int a = 0; a < 9; a += 3){
		for(int b = 0; b < 9; b += 3){
			int ck[10] = {0,0,0,0,0,0,0,0,0};
			for(int i = a; i < a+3; i++){
				for(int j = b; j < b+3; j++){
					ck[charts[t][i][j]]++;
				}
			}
			for(int i = 1; i <= 9; i++){
				if(ck[i] != 1) return false;
			}
		}
	}
	return true;
}

bool checkMatch(int a){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(start[i][j] != 0 && charts[a][i][j] != start[i][j]) return false;
		}
	}
	return true;
}

bool check(int a){
	return (checkRows(a) && checkCol(a) && checkGrid(a) && checkMatch(a));
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++) scanf("%d", &start[i][j]);
	}
	for(int a = 0; a < n; a++){
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				scanf("%d", &charts[a][i][j]);
			}
		}
	}
	for(int a = 0; a < n; a++){
		if(check(a)) printf("%d\n", a+1);
	}
	printf("END");
}