#include <iostream>
#include <string>
using namespace std;

typedef struct team{
    string name;
    int score;
    int shot;
    int lost;
}team;

team teams[4];
int goals[4][4];

bool better(team a, team b){
    if(a.score > b.score) return true;
    else if(a.score == b.score){
        if(a.shot-a.lost > b.shot-b.lost) return true;
        else if(a.shot-a.lost == b.shot-b.lost){
            if(a.shot > b.shot) return true;
        }
    }
    return false;
}

void exch(int i, int j){
    team holder = teams[i];
    teams[i] = teams[j];
    teams[j] = holder;
}

int main(){
    for(int i = 0; i < 4; i++) cin >> teams[i].name;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) cin >> goals[i][j];
    }
    int st = 0;
    for(int i = 0; i < 4; i++){
        for(int j = st; j < 4; j++){
            if(i == j) continue;
            if(goals[i][j] > goals[j][i]){
                teams[i].score += 3;
            }else if(goals[i][j] < goals[j][i]){
                teams[j].score += 3;
            }else if(goals[i][j] == goals[i][j]){
                teams[i].score += 1;
                teams[j].score += 1;
            }
            teams[i].shot += goals[i][j];
            teams[i].lost += goals[j][i];
            teams[j].shot += goals[j][i];
            teams[j].lost += goals[i][j];
        }
        st++;
    }
    for(int i = 0; i < 4; i++){
        int max = i;
        for(int j = i+1; j < 4; j++){
            if(better(teams[j], teams[max])) max = j;
        }
        exch(i, max);
    }
    for(int i = 0; i < 4;i++){
        cout << teams[i].name << " " << teams[i].score << endl;
    }
}