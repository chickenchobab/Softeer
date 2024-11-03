#include<iostream>
#include <algorithm>
#include <vector>
#define endl '\n'

using namespace std;

int N;
typedef pair<int, int> p;
vector<p> scores[4];
vector<int> answers[4];

void input(){
    cin >> N;
    int s;
    for (int c = 0; c < 3; ++c){
        scores[c].resize(N);
        for (int i = 0; i < N; ++i){
            cin >> s;
            scores[c][i] = {s, i};
        }
    }
}

void calcTotalScores(){
    scores[3].resize(N);
    for (int i = 0; i < N; ++i){
        scores[3][i] = {0, i};
        for (int c = 0; c < 3; ++c){
            scores[3][i].first += scores[c][i].first;
        }
    }
}

void rankContenders(){
    for (int c = 0; c < 4; ++c){
        sort(scores[c].begin(), scores[c].end(), greater<p>());
        
        answers[c].resize(N);
        answers[c][scores[c][0].second] = 1;
        
        for (int i = 1; i < N; ++i){
            if (scores[c][i - 1].first == scores[c][i].first)
                answers[c][scores[c][i].second] = answers[c][scores[c][i - 1].second];
            else 
                answers[c][scores[c][i].second] = i + 1;
        }
    }
}

void print(){
    for (int c = 0; c < 4; ++c){
        for (int r : answers[c])
            cout << r << ' ';
        cout << endl;
    }
}

void solve(){
    calcTotalScores();
    rankContenders();
    print();
}

int main(int argc, char** argv)
{
    input();
    solve();
   return 0;
}