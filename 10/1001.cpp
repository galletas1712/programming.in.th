#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n, m;
	cin >> n;
	cin >> m;
	char grid[n][m];
	int bricks[m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c;
			scanf(" %c", &grid[i][j]);
		}
	}
	for(int i = 0; i < m; i++) cin >> bricks[i];
	for(int i = 0; i < m; i++){
		for(int k = 0; k < bricks[i]; k++){
			int j;  
			for(j = 0;j < n && grid[j][i] == '.';++j) {;}  
			if(j > 0) grid[j-1][i] = '#'; 
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cout << grid[i][j];
		cout << endl;
	}
}