#include <iostream>  
using namespace std;  
  
int main() {  
    int n,k;  
    cin >> n >> k;  
    int num[n+1], count = 0;  
    for(int i = 2; i <= n; i++) num[i] = i;  
    for(int i = 2; i <= n; i++){
        for(int j = i; j <= n; j += i){
            if(num[j] != -1) count++;
            if(count == k){
                cout << j;
                return 0;
            }
            num[j] = -1;
        }
    }
}  