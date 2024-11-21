#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int N;
vector<int> m;

void init(){
    cin >> N;
    m.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> m[i];
}

void solve(){
    int answer = 0;
    int s = 0, e = N - 1;
    int numPad = 0;
    
    sort(begin(m), end(m));
    
    while (s <= e){
        if (m[s] == 300){
            ++numPad;
            ++s;
        }
        else if (m[e] > 600) {
            ++answer;
            --e;
        }
        else if (s != e && m[s] + m[e] <= 900){
            ++answer;
            --e;
            ++s;
        }  
        else {
            if (numPad) --numPad;
            ++answer;
            --e; // Should not be ++s
        }
    }

    answer += numPad / 3 + (numPad % 3 != 0);
    cout << answer << '\n';
}

int main(int argc, char** argv)
{
    cin >> T;
    while (T--){
        init();
        solve();
    }
   return 0;
}