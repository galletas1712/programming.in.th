#include "1004.h"

int nc, ns;
int students[10001];
qarr<int> cqueue;
qarr<int>* squeue;

void add(int id){
    if(!cqueue.contains(students[id])) cqueue.enqueue(students[id]);
    squeue[students[id]].enqueue(id);
}

void del(){
    int c = cqueue.queue[cqueue.front];
    int val = squeue[c].queue[squeue[c].front];
    squeue[c].dequeue();
    if(squeue[c].isEmpty()) cqueue.dequeue();
    cout << val << endl;
}

int main(){
    cin >> nc >> ns;
    cqueue.construct(nc);
    squeue = new qarr<int>[nc+1];
    for(int i = 0; i <= nc; i++){
        squeue[i].construct(ns);
    }
    for(int i = 0; i < ns; i++){
        int c, id;
        cin >> c >> id;
        students[id] = c;
    }
    char inst;
    cin >> inst;
    while(inst != 'X'){
        if(inst == 'E'){
            int id;
            cin >> id;
            add(id);
        }else if(inst == 'D'){
            del();
        }
        cin >> inst;
    }
    cout << 0;
}
