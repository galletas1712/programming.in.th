#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define FORA(i, a) for(int i = 0; i < a; i++)
#define FORI(i, a, b, c) for(int i = a; i < b; i += c)
#define FOR(i, a, b) for(int i = a; i < b; i++)

using namespace std;

int main(){
	std::ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int posts[n][2];
	int post_index = 0;
	int max = 0;
	FORA(i, n)  posts[i][0] = 0, posts[i][1] = 0;
	FORA(i, n){
		int a;
		cin >> a;
		// find operation
		int index = -1;
		FORA(j, i){
			if(posts[j][0] == a){
				index = j;
				break;
			}
		}
		//end find operation
		if(index == -1){
			posts[post_index][0] = a;
			posts[post_index][1] = 1;
			post_index++;
		}else{
			posts[index][1]++;
		}
	}
	FORA(i, n) if(posts[i][1] > max) max = posts[i][1];
	vector<int> maxes;
	FORA(i, n){
		if(posts[i][1] == max) maxes.push_back(posts[i][0]);
	}
	int max_size = maxes.size();
	sort(maxes.begin(), maxes.end());
	int passed = 0;
	FORA(i, max_size){
		cout << maxes[i];
		passed++;
		if(passed < max_size) cout << " ";
	}
}
