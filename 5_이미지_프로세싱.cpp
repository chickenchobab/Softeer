#include<iostream>
#include <queue>
#include <vector>
using namespace std;
int H, W, Q;
int color[130][130];
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
typedef pair<int, int> p;

void solve(int i, int j, int c){
    int x = color[i][j];
    if (x == c) return;

    queue<p> q;

    q.push({i, j});
    color[i][j] = c;

    while (!q.empty()){
        auto [i, j] = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d){
            int ni = i + di[d];
            int nj = j + dj[d];
            if (ni < 1 || ni > H || nj < 1 || nj > W) continue;
            if (color[ni][nj] != x) continue;
            q.push({ni, nj});
            color[ni][nj] = c;
        }
    }
}

void show(){
    for (int i = 1; i <= H; ++i){
        for (int j = 1; j <= W; ++j){
            cout << color[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(int argc, char** argv)
{
    cin >> H >> W;
    for (int i = 1; i <= H; ++i){
        for (int j = 1; j <= W; ++j){
            cin >> color[i][j];
        }
    }
    cin >> Q;
    int i, j, c;
    while (Q--) {
        cin >> i >> j >> c;
        solve(i, j, c);
    }
    show();
   return 0;
}