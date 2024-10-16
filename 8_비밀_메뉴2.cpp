#include<iostream>
#include <vector>

using namespace std;

int N, M, K;
int btns1[3001], btns2[3001];

void input(){
    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i)
        cin >> btns1[i];
    for (int i = 1; i <= M; ++i)
        cin >> btns2[i];
}

void solve(){
    int answer = 0;
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            if (btns1[i] != btns2[j]) continue; // unlike LCS
            dp[i][j] = dp[i - 1][j - 1] + 1;
            answer = max(answer, dp[i][j]);
        }
    }

    cout << answer;
}

int main(int argc, char** argv)
{
    input();
    solve();
   return 0;
}