#include <iostream>
using namespace std;

int main(){
	string s;
	cin >> s;
	int pos = 1;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == 'A'){
			if(pos == 1){
				pos = 2;
			}else if(pos == 2){
				pos = 1;
			}
		}else if(s[i] == 'B'){
			if(pos == 2){
				pos = 3;
			}else if(pos == 3){
				pos = 2;
			}
		}else if(s[i] = 'C'){
			if(pos == 1){
				pos = 3;
			}else if(pos == 3){
				pos = 1;
			}
		}
	}
	cout << pos;
}
