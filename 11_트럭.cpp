#include<iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N, M, Q;
int MAX;
typedef long long ll;
typedef pair<int, int> p;
map<int, int> suggests[100001];
vector<int> sizes[100001], prices[100001];
vector<ll> totalSizes, totalPrices;

void input(){
    cin >> N;
    int A, S, P;
    for (int i = 0; i < N; ++i){
        cin >> A;
        for (int j = 0; j < A; ++j){
            cin >> S >> P;
            MAX = max(S, MAX);
            if (suggests[i].count(S)) 
                suggests[i][S] = max(suggests[i][S], P);
            else 
                suggests[i][S] = P;
        }
    }
}

void sortSuggests(){
    
    for (int i = 0; i < N; ++i){
        auto it = suggests[i].begin();
        sizes[i].push_back((*it).first);
        prices[i].push_back((*it).second);
        
        int price = (*it).second;
        advance(it, 1);
        for (; it != suggests[i].end(); ++it){
            if ((*it).second > price){
                sizes[i].push_back((*it).first);
                prices[i].push_back((*it).second - price);
                price = (*it).second;
            }
        }
    }
}

void integrateSuggests(){
    map<int, ll> totalSuggests;

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < sizes[i].size(); ++j){
            if (totalSuggests.count(sizes[i][j]))
                totalSuggests[sizes[i][j]] += prices[i][j];
            else
                totalSuggests[sizes[i][j]] = prices[i][j];
        }
    }

    auto it = totalSuggests.begin();
    ll sum = (*it).second;
    advance(it, 1);
    for (; it != totalSuggests.end(); ++it){
        (*it).second += sum;
        sum = (*it).second;
    }

    for (it = totalSuggests.begin(); it != totalSuggests.end(); ++it){
        totalSizes.push_back((*it).first);
        totalPrices.push_back((*it).second);
    }
}

bool isPossible(int siz){
    auto it = lower_bound(totalSizes.begin(), totalSizes.end(), siz);
    if ((*it) == siz)
        return totalPrices[distance(totalSizes.begin(), it)] >= Q;
    else if (it == totalSizes.begin())
        return false;
    else {
        advance(it, -1);
        return totalPrices[distance(totalSizes.begin(), it)] >= Q;
    }
}

int getMinSizeToPossible(ll s, ll e){
    ll answer = -1;
    while (s <= e){
        ll m = (s + e) / 2;
        if (isPossible(m)){
            e = m - 1;
            answer = m;
        }
        else {
            s = m + 1;
        }
    }
    return answer;
}

void solve(){
    sortSuggests();
    integrateSuggests();
    cin >> M;
    // show();
    while(M--){
        cin >> Q;
        cout << getMinSizeToPossible(1, MAX) << ' ';
    }
}


int main(int argc, char** argv)
{
    input();
    solve();
    
   return 0;
}