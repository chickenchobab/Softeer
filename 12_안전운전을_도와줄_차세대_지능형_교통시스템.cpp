#include<iostream>
#include <vector>

using namespace std;

int N, T;
int signals[100][100][4];
int dr[] = {0, -1, 0, 1}, dc[] = {1, 0, -1, 0};
vector<int> directions[13];
bool visited[100][100];
int answer;

void input(){
    cin >> N >> T;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            for (int t = 0; t < 4; ++t){
                cin >> signals[i][j][t];
            }
        }
    }
}

void digitalizeSignals(){    
    for (int d = 0; d < 4; ++d){

        for (int s = 0; s <= 8; s = s + 4)
            directions[d + 1 + s].push_back(d);
        directions[d + 1].push_back((d + 1) % 4);
        directions[d + 1].push_back((d + 3) % 4);
        directions[d + 5].push_back((d + 1) % 4);
        directions[d + 9].push_back((d + 3) % 4);
    }
}

void move(int r, int c, int d, int t){

    if (t > T) return;

    int nr = r + dr[d];
    int nc = c + dc[d];
    
    if (nr < 0 || nr >= N || nc < 0 || nc >= N) return;
   
    for (int nd : directions[signals[nr][nc][(t) % 4]]){
        if (!visited[nr][nc]){
            ++answer;
            visited[nr][nc] = 1;
        }
        if (directions[signals[nr][nc][(t) % 4]][0] == d)
            move(nr, nc, nd, t + 1);
    }
}

void solve(){
    digitalizeSignals();
    move(1, 0, 1, 0);
    cout << answer;
}

int main(int argc, char** argv)
{
    input();
    solve();
   return 0;
}