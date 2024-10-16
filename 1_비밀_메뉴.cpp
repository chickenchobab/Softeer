#include<iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
int M, N, K;
string answer, input;

void solve(){
    if (N < M) {
        cout << "normal";
        return;
    }
    for (int i = 0; i < N; ++i){
        if (input.substr(i, M) == answer){
            cout << "secret";
            return;
        }
    }
    cout << "normal";
}

int main(int argc, char** argv)
{
    cin >> M >> N >> K;

    char c;
    for (int i = 0; i < M; ++i){
        cin >> c;
        answer.push_back(c);
    }
    for (int i = 0; i < N; ++i){
        cin >> c;
        input.push_back(c);
    }

    solve();
    
   return 0;
}