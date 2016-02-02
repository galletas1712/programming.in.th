#include <iostream>
#include <cctype>
using namespace std;

bool palindrome(string s, int lo, int hi){
	int i = lo;
	int j = hi;
	while(i <= hi && j >= lo){
		if(s[i] != s[j]) return false;
		i++;
		j--;
	}
	return true;
}

bool d_palindrome(string s){
	int mid = s.length()/2;
	if(s.length()%2 == 0) return palindrome(s, 0, mid-1) && palindrome(s, mid, s.length()-1);
	else return palindrome(s, 0, mid-1) && palindrome(s, mid+1, s.length()-1);	
}

int main(){
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); i++) s[i] = tolower(s[i]);
	if(d_palindrome(s)) cout << "Double Palindrome";
	else if (palindrome(s, 0, s.length()-1)) cout << "Palindrome";
	else cout << "No";
}
