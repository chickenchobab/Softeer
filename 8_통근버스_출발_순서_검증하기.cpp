#include<iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;

void input(){
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
}

void solve(){
    long long answer = 0;
    
    for (int i = 0; i < N; ++i){
        int bigger = 0;
        for (int j = i + 1; j < N; ++j){
            arr[i] > arr[j] ? ++bigger : answer += bigger;
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