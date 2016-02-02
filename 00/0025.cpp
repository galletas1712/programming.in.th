#include <iostream>
#include <string.h>
using namespace std;

int main(){
	string a, b;
	char op;
	cin >> a;
	cin >> op;
	cin >> b;
	int ai = a.length()-1;
	int bi = b.length()-1;
	if(op == '+'){
		if(ai > bi){
			int cut = ai-bi;
			for(int i = 0; i <= ai; i++){
				if(i == cut || i == 0) cout << '1';
				else cout << '0';
			}
		}else if(ai == bi){
			for(int i = 0; i <= ai; i++){
				if(i == 0) cout << '2';
				else cout << '0';
			}
		}else if(ai < bi){
			int cut = bi-ai;
			for(int i = 0; i <= bi; i++){
				if(i == cut || i == 0) cout << '1';
				else cout << '0';
			}
		}
	}else if(op == '*'){
		for(int i = 0; i <= ai+bi; i++){
			if(i == 0) cout << '1';
			else cout << '0';
		}
	}
}	
