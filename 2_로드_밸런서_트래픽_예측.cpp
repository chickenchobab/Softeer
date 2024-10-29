#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef long long ll;
int N;
ll K;
vector<int> graph[100001];
ll request[100001];
int indegree[100001];

void input(){
    cin >> N >> K;
    int r, p;
    for (int i = 1; i <= N; ++i){
        cin >> r;
        while (r--){
            cin >> p;
            graph[i].push_back(p);
            indegree[p]++;
        }
    }
}

void bfs(){
    queue<int> q;
    request[1] = K;
    q.push(1);

    while (q.size()){
        int cur = q.front();
        q.pop();

        if (graph[cur].empty()) continue;
        
        auto surplus = request[cur] % graph[cur].size();
        for (int nxt : graph[cur]){
            if (surplus){
                request[nxt] += request[cur] / graph[cur].size() + 1;
                --surplus;
            }
            else{
                request[nxt] += request[cur] / graph[cur].size();
            }
            if (--indegree[nxt] == 0) q.push(nxt);
        }
    }
}

void solve(){
    bfs();
    for (int i = 1; i <= N; ++i) 
        cout << request[i] << ' ';
}

int main(int argc, char** argv)
{
    input();
    solve();
   return 0;
}