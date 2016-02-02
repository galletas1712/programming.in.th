#include <iostream>
using namespace std;

int main(){
    int year;
    cin >> year;
    while(year > -1){
        int bees[3] = {1, 1, 0};
        for(int i = 1; i <= year; i++){
            int finwork, fins;
            finwork = bees[2] + 1;
            fins = bees[1]-bees[2];
            bees[1] += finwork;
            bees[2] += fins;
            // cout << bees[1] << " " << bees[2] << endl;
        }
        cout << bees[1] << " " << bees[0]+bees[1]+bees[2] << endl;
        cin >> year;
    }
}