#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d\n", &n);
    string arr[1111];
    int sub = 0;
    int index = 0;
    for(int i = 0; i < n; i++){
        char c[33];
        scanf(" %s", c);
        bool found = false;
        for(int j = 0; j < i; j++){
            if(c == arr[j]){
                found = true;
                sub += 1;
            }
        }
        if(!found){
            arr[index] = c;
            index++;
        }
    }
    std::sort(arr, arr + (n-sub));
    for(int i = 0; i < n-sub; i++) printf("%s\n", arr[i].c_str());
}


//QuickSort - has a defect
/*
 int less(string *s, int i, int j){
	const char *c1 = s[i].c_str();
	const char *c2 = s[j].c_str();
	unsigned int index = 0;
	while(index < s[i].length() && index < s[j].length() && c1[index] == c2[index]){
 index++;
	}
	if(index == s[i].length() && index == s[j].length()){
 return 0;
	}else if(index == s[i].length()){
 return -1;
	}else if(index == s[j].length()){
 return 1;
	}else{
 if((int) c1[index] > (int) c2[index]){
 return -1;
 }else if((int) c2[index] > (int) c1[index]){
 return 1;
 }
	}
 }
 
 void exch(string *s, int a, int b){
	string holder = s[a];
	s[a] = s[b];
	s[b] = holder;
 }
 
 void sort(string *s, int lo, int hi){
	if(hi <= lo) return;
	int j = partition(s, lo, hi);
	sort(s, lo, j);
	sort(s, j+1, hi);
 }
 
 int partition(string *s, int lo, int hi){
	int i = lo;
	int j = hi+1;
	while(true){
 
 while(less(s, ++i, lo) == 1){
 if(i == hi) continue;
 }
 
 while(less(s, lo, --j) == 1){
 if(j == lo) continue;
 }
 
 if(j <= i) break;
 
 exch(s, i, j);
	}
 
	exch(s, lo, j);
	return j;
 }
 */