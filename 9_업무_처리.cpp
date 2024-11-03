#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int H, K, R;
vector<queue<int>> queues;
int answer;

void passLeftWork(int level);
void passRightWork(int level);

void input(){
    cin >> H >> K >> R;
    queues.resize(1 << (H + 1));
    int work;
    for (int i = (1 << H); i < (1 << (H + 1)); ++i){
        for (int j = 0; j < K; ++j){
            cin >> work;
            queues[i].push(work);
        }
    }
}

void finishWork(){
    if (queues[1].empty()) return;
    answer += queues[1].front();
    queues[1].pop();
}

void passLeftWork(int level){
    if (!level) {
        finishWork();
        return;
    }
    for (int i = (1 << level); i < (1 << (level + 1)); i = i + 2){
        if (queues[i].empty()) continue;
        queues[i / 2].push(queues[i].front());
        queues[i].pop();
    }
    passRightWork(level - 1);
}

void passRightWork(int level){
    if (!level) {
        finishWork();
        return;
    }
    for (int i = (1 << level) + 1; i < (1 << (level + 1)); i = i + 2){
        if (queues[i].empty()) continue;
        queues[i / 2].push(queues[i].front());
        queues[i].pop();
    }
    passLeftWork(level - 1);
}

void solve(){
    int turn = 0;
    while (H + 1 + turn <= R){
        if (turn % 2)
            passLeftWork(H);
        else
            passRightWork(H);
        ++turn;
    }
    cout << answer;
}

int main(int argc, char** argv)
{
    input();
    solve();
   return 0;
}