#include<iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n, q;
vector<int> mileage;
unordered_map<int, int> indice;

void init(){
    cin >> n >> q;
    mileage.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> mileage[i];
}

void solve(){
    int m;
    sort(begin(mileage), end(mileage));
    for (int i = 0; i < n; ++i)
        indice.insert({mileage[i], i});
    
    while (q--){
        cin >> m;
        if (!indice.count(m)) cout << 0;
        else cout << (long long)indice[m] * (n - 1 - indice[m]);
        cout << '\n';
    }
}

int main(int argc, char** argv)
{
    init();
    solve();
   return 0;
}