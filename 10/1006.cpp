#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    int dice[n][6];
    string inst[n];
    for(int i = 0; i < n; i++){
        dice[i][0] = 1;
        dice[i][1] = 2;
        dice[i][2] = 3;
        dice[i][3] = 5;
        dice[i][4] = 4;
        dice[i][5] = 6;
    }
    for(int i = 0; i < n; i++) cin >> inst[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < inst[i].length(); j++){
            int currDice[6];
            for(int k = 0; k < 6; k++) currDice[k] = dice[i][k];
            switch(inst[i][j]){
                case 'F':
                    dice[i][0] = currDice[3];
                    dice[i][1] = currDice[0];
                    dice[i][3] = currDice[5];
                    dice[i][5] = currDice[1];
                    break;
                case 'B':
                    dice[i][0] = currDice[1];
                    dice[i][1] = currDice[5];
                    dice[i][3] = currDice[0];
                    dice[i][5] = currDice[3];
                    break;
                case 'L':
                    dice[i][0] = currDice[4];
                    dice[i][2] = currDice[0];
                    dice[i][4] = currDice[5];
                    dice[i][5] = currDice[2];
                    break;
                case 'R':
                    dice[i][0] = currDice[2];
                    dice[i][2] = currDice[5];
                    dice[i][4] = currDice[0];
                    dice[i][5] = currDice[4];
                    break;
                case 'C':
                    dice[i][1] = currDice[4];
                    dice[i][2] = currDice[1];
                    dice[i][3] = currDice[2];
                    dice[i][4] = currDice[3];
                    break;
                case 'D':
                    dice[i][1] = currDice[2];
                    dice[i][2] = currDice[3];
                    dice[i][3] = currDice[4];
                    dice[i][4] = currDice[1];
                    break;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << dice[i][1];
        if(i < n-1) cout << " ";
    }
}