#include <cstdio>
using namespace std;

int n, k;
char action[5][1001];
int grid[101][101]; // owners
int parea[5] = {0, 1, 1, 1, 1}; // areas
int coord[5][2];

bool ingrid(int c){
	if(c >= 1 && c <= n) return true;
	return false;
}

bool nop(int i, int j){
	if(coord[grid[i][j]][0] == i && coord[grid[i][j]][1] == j) return false;
	return true;
}

int main(){
	scanf("%d %d", &n, &k);
	grid[1][n] = 1;
	grid[n][n] = 2;
	grid[n][1] = 3;
	grid[1][1] = 4;
	coord[1][0] = 1;
	coord[1][1] = n;
	coord[2][0] = n;
	coord[2][1] = n;
	coord[3][0] = n;
	coord[3][1] = 1;
	coord[4][0] = 1;
	coord[4][1] = 1;
	for(int i = 1; i <= 4; i++){
		for(int j = 0; j < k; j++){
			scanf(" %c", &action[i][j]);
		}
	}
	for(int i = 0; i < k; i++){
		for(int j = 1; j <= 4; j++){
			char c = action[j][i];
			bool eog = false;
			switch(c){
				case 'N':
					if(ingrid(coord[j][0] - 1) && nop(coord[j][0]-1, coord[j][1])) coord[j][0]--;
					else eog = true;
					break;
				case 'E':
					if(ingrid(coord[j][1] + 1) && nop(coord[j][0], coord[j][1]+1)) coord[j][1]++;
					else eog = true;
					break;
				case 'S':
					if(ingrid(coord[j][0] + 1) && nop(coord[j][0]+1, coord[j][1])) coord[j][0]++;
					else eog = true;
					break;
				case 'W':
					if(ingrid(coord[j][1] - 1) && nop(coord[j][0], coord[j][1]-1)) coord[j][1]--;
					else eog = true;
					break;
			}
			
			if(!eog && grid[coord[j][0]][coord[j][1]] != j){
				parea[j]++;
				parea[grid[coord[j][0]][coord[j][1]]]--; // if position in grid has owner, the owner of the grid --;
				grid[coord[j][0]][coord[j][1]] = j;
			}
			/*printf("%d %d\n", coord[j][0], coord[j][1]);
			for(int i = 1; i <= 4; i++){
				printf("%d\n", parea[i]);
			}
			printf("\n");*/
		}
	}
	/*for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}*/
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(!grid[i][j]){
				printf("No");
				return 0;
			} 
		}
	}
	int max = 0, count = 0;
	for(int i = 1; i <= 4; i++){
		if(parea[i] > max) max = parea[i];
	}
	for(int i = 1; i <= 4; i++){
		if(parea[i] == max) count++;
	}
	printf("%d %d\n", count, max);
	for(int i = 1; i <= 4; i++){
		if(parea[i] == max) printf("%d\n", i);
	}
}
