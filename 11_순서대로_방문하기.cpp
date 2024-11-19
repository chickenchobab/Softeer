#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
bool map[5][5];
vector<pair<int, int>> points;
bool isVisited[5][5];
vector<vector<int>> indice(5, vector<int>(5, -1));
int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
int answer;

void init(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> map[i][j];
    int a, b;
    for (int p = 0; p < m; ++p){
        cin >> a >> b;
        points.push_back({a, b});
        indice[a][b] = p;
    }
}

bool isValid(int r, int c, int idx){
    if (r < 1 || r > n || c < 1 || c > n) return false;
    if (map[r][c] || isVisited[r][c]) return false;
    return (indice[r][c] == -1 || indice[r][c] == idx + 1);
}

void dfs(int r, int c, int idx){
    if (idx == m - 1){
        ++answer;
        return;
    }
        
    for (int d = 0; d < 4; ++d){
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (isValid(nr, nc, idx)){
            isVisited[nr][nc] = 1;
            dfs(nr, nc, max(idx, indice[nr][nc]));
            isVisited[nr][nc] = 0;
        }
    }
}

void solve(){
    auto [r, c] = points[0];
    isVisited[r][c] = 1;
    dfs(r, c, 0);
    cout << answer;
}

int main(int argc, char** argv)
{
    init();
    solve();
   return 0;
}