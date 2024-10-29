#include<iostream>
#include <vector>
#include <queue>

using namespace std;

typedef unsigned long long ll;
ll N;
vector<pair<ll, ll>> graph[200002];
ll sumDistToChild[200002];
ll numSubTree[200002];

void input(){
    cin >> N;
    ll x, y, t;
    for (ll i = 1; i < N; ++i){
        cin >> x >> y >> t;
        graph[x].push_back({y, t});
        graph[y].push_back({x, t});
    }
}

// Calculate size of sub tree whose root is the current node.
void cntSubTree(ll cur, ll parent){
    numSubTree[cur] = 1;
    for (ll i = 0; i < graph[cur].size(); ++i){
        ll child = graph[cur][i].first;
        if (child == parent) continue;
        
        cntSubTree(child, cur);
        numSubTree[cur] += numSubTree[child];
    }
}

void dfsBottomUp(ll cur, ll parent){ 
    for (ll i = 0; i < graph[cur].size(); ++i){
        auto [child, weight] = graph[cur][i];
        if (parent == child) continue;
        
        dfsBottomUp(child, cur);
        sumDistToChild[cur] += (sumDistToChild[child] + numSubTree[child] * weight);
    }
}

void dfsTopDown(ll cur, ll parent){  
    for (ll i = 0; i < graph[cur].size(); ++i){
        auto [child, weight] = graph[cur][i];
        if (parent == child) continue;
            
        sumDistToChild[child] = sumDistToChild[cur] + (N - 2 * numSubTree[child]) * weight;
        dfsTopDown(child, cur);
    }
}

void solve(){
    cntSubTree(1, 0); // root : 1
    dfsBottomUp(1, 0); // Calculate answer of root.
    dfsTopDown(1, 0); // Calculate the others from root.
    // show();
    for (ll i = 1; i <= N; ++i){
        cout << sumDistToChild[i] << '\n';
    }
}

int main(int argc, char** argv)
{
    input();
    solve();
   return 0;
}