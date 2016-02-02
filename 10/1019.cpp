#include <stdio.h>
#include <string>
#include <iostream>
#define FORA(i, a) for(int i = 0; i < a; i++)
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main(){
	string a;
	string b;
	string max;
	int maxlen = 0;
	cin >> a;
	cin >> b;
	FORA(i, a.length()){ //find max length
		FORA(j, b.length()){
			if(a[i] == b[j]){
				int len = 1; // length of common string
				if(i+1 < a.length() && j+1 < b.length()){ // check only if index+1 is not out of bounds
					int ia = i+1; // separate iterator for a
					int ib = j+1; // same with b
					while(a[ia] == b[ib] && ia < a.length() && ib < b.length()){ 
						len++;
						ia++;
						ib++;
					}
				}
				if(len > maxlen) maxlen = len;
			}
		}
	}
	
	FORA(i, a.length()-maxlen+1){ // find first string from max length 
		FORA(j, b.length()- maxlen+1){
			if(a[i] == b[j]){
				if(a.substr(i, maxlen) == b.substr(j, maxlen)){
					max =  a.substr(i, maxlen);
					cout << max;
					return 0;
				}
			}
		}
	}
}
