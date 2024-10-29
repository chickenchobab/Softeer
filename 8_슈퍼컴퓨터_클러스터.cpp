#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 1000000000
using namespace std;

typedef long long ll;
int N;
ll B;
vector<int> a;

void input(){
    cin >> N >> B;
    a.resize(N);
    for (int i = 0; i < N; ++i){
        cin >> a[i];
    }
}

bool isPossible(ll minPerf){
    ll cost = 0;
    for (int i = 0; i < N && a[i] < minPerf; ++i){
        ll gap = minPerf - a[i];
        cost += gap * gap;
        if (cost > B) return false;
    }
    return cost <= B;
}

void solve(){
    ll answer = 0;
    sort(a.begin(), a.end());
    ll s = a.front(), e = (ll)pow(B, (double)1 / 2) + a.back();

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
    cout << answer;
}

int main(int argc, char** argv)
{
    input();
    solve();
   return 0;
}