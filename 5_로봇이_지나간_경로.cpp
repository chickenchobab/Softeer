#include<iostream>


using namespace std;

int H, W;
char map[27][27];
int startR, startC, startDir;
bool visited[26][26];
int dr[] = {0, -1, 0, 1}, dc[] = {1, 0, -1, 0};
string commands;

void input(){
    cin >> H >> W;
    string str;
    for (int i = 1; i <= H; ++i){
        cin >> str;
        for (int j = 1; j <= W; ++j){
            map[i][j] = str[j - 1];
        }
    }
}

void findStartPoint(){
    int adj = 0;
    for (int i = 1; i <= H; ++i){
        for (int j = 1; j <= W; ++j){
            if (map[i][j] != '#') continue;
            adj = 0;
            for (int d = 0; d < 4; ++d)
                adj += (map[i + dr[d]][j + dc[d]] == '#');
            if (adj == 1){
                startR = i;
                startC = j;
                return;    
            }
        }
    }
}

bool isValid(int r, int c, int d){
    if (r < 1 || r > H || c < 1 || c > W) 
        return false;
    if (visited[r][c])
        return false;
    if (map[r - dr[d]][c - dc[d]] != '#')
        return false;
    return map[r][c] == '#';
}

void trackRoute(int r, int c, int d){
    visited[r][c] = 1;

    int nr = r + 2 * dr[d];
    int nc = c + 2 * dc[d];
    if (isValid(nr, nc, d)){
        commands += "A";
        trackRoute(nr, nc, d);
        return;
    }

    for (int nd = 0; nd < 4; ++nd){
        int nr = r + 2 * dr[nd];
        int nc = c + 2 * dc[nd];
        if (!isValid(nr, nc, nd)) continue;
        if (abs(nd - d) == 2) continue;

        if ((nd - d + 4) % 4 == 1) 
            commands += "LA";
        else if ((d - nd + 4) % 4 == 1) 
            commands += "RA";
        trackRoute(nr, nc, nd);
        return;
    }
}

void start(){
    visited[startR][startC] = 1;
    for (startDir = 0; startDir < 4; ++startDir){
        int nr = startR + 2 * dr[startDir];
        int nc = startC + 2 * dc[startDir];
        if (isValid(nr, nc, startDir)){
            commands += "A";
            trackRoute(nr, nc, startDir);
            return;
        }
    }
}

void solve(){
    findStartPoint();
    start();
    cout << startR << ' ' << startC << '\n';
    if (startDir == 0) cout << '>';
    else if (startDir == 1) cout << '^';
    else if (startDir == 2) cout << '<';
    else cout << 'v';
    cout << '\n' << commands;
}

int main(int argc, char** argv)
{
    input();
    solve();
   return 0;
}