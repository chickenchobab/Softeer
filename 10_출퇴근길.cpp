#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, S, T;
vector<int> graph[100001], graphRev[100001];
bool atGoing[100001], atGoingRev[100001];
bool atComing[100001], atComingRev[100001];

void init(){
    cin >> n >> m;
    int a, b;
    while (m--){
        cin >> a >> b;
        graph[a].push_back(b);
        graphRev[b].push_back(a);
    }
    cin >> S >> T;
}

void go(int cur){
    atGoing[cur] = 1;
    if (cur == T) return;
    for (int nxt : graph[cur]){
        if (atGoing[nxt]) continue;
        go(nxt);
    }
}

void goRev(int cur){
    atGoingRev[cur] = 1;
    // if (cur == S) return;
    for (int nxt : graphRev[cur]){
        if (atGoingRev[nxt]) continue;
        goRev(nxt);
    }
}

void come(int cur){
    atComing[cur] = 1;
    if (cur == S) return;
    for (int nxt : graph[cur]){
        if (atComing[nxt]) continue;
        come(nxt);
    }
}

void comeRev(int cur){
    atComingRev[cur] = 1;
    // if (cur == T) return;
    for (int nxt : graphRev[cur]){
        if (atComingRev[nxt]) continue;
        comeRev(nxt);
    }
}


void solve(){
    int answer = 0;
    
    go(S); 
    goRev(T);
    come(T); 
    comeRev(S);
    
    for (int i = 1; i <= n; ++i)
        answer += (atGoing[i] && atGoingRev[i] && atComing[i] && atComingRev[i]);
    cout << answer - 2;
}

int main(int argc, char** argv)
{
    init();
    solve();
   return 0;
}