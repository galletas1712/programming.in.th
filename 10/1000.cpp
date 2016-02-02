#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	char word[a+1];
	char prev[a+1];
	int sub;
	bool broken = false;
	for(int i = 0; i < b; i++){
		scanf("%s", word);
		if(i > 0){
			int num_diff = 0;
			for(int j = 0; j < a; j++){
				if(word[j] != prev[j]) num_diff++;
			}
			if(num_diff > 2){
				sub = i+1;
				break;
			}
		}
		for(int j = 0; j <= a; j++){
			prev[j] = word[j];
		}
	}
	for(int i = 0; i < b-sub; i++){
		char s[a+1];
		scanf("%s", s);
	}
	printf("%s", prev);
}
