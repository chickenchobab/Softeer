#include<iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, T;
typedef long long ll;
vector<ll> problems;

void input(){
    M = 2 * N - 1;
    problems.resize(M + 2);
    for (int i = 1; i <= M; ++i)
        cin >> problems[i];
    problems.front() = problems.back() = 0;
}

bool isPossible(ll cnt){
    vector<ll> problemsCopy(problems);

    for (int i = 1; i <= M; i = i + 2){
        if (problemsCopy[i] + problemsCopy[i - 1] >= cnt);
        else if (problemsCopy[i] + problemsCopy[i - 1] + problemsCopy[i + 1] >= cnt)
            problemsCopy[i + 1] -= (cnt - problemsCopy[i] - problemsCopy[i - 1]);
        else if (problemsCopy[i] + problemsCopy[i + 1] >= cnt)
            problemsCopy[i + 1] -= cnt - problemsCopy[i];
        else return false;
    }
    return true;
}

void solve(){
    ll answer = 0;
    ll s = *min_element(problems.begin() + 1, problems.end() - 1);
    ll e = *max_element(problems.begin() + 1, problems.end() - 1) * 2;

    while (s <= e){
        ll m = (s + e) / 2;
        if (isPossible(m)){
            answer = m;
            s = m + 1;
        }
        else {
            e = m - 1;
        }
    }
    cout << answer << '\n';
}

int main(int argc, char** argv)
{
    cin >> N >> T;
    while (T--){
        input();
        solve();
    }
   return 0;
}