#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
string seq[15];
string superSeq[1 << 15];
int answer[1 << 15];

void init(){
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> seq[i];
}

string merge(string &a, string &b){
    if (a.empty() || b.empty())
        return "";
    
    string ret;
    
    for (int i = 0; i < M; ++i){
        if (a[i] == '.')
            ret.push_back(b[i]);
        else if (b[i] == '.')
            ret.push_back(a[i]);
        else if (a[i] == b[i])
            ret.push_back(a[i]);
        else
            return "";
    }
    return ret;
}

void makeSuperSeq(int idx){
    int i = idx;
    int power = 0;
    while (i % 2 == 0){
        i /= 2;
        ++power;
    }
    superSeq[idx] = merge(seq[power], superSeq[idx - (1 << power)]);
}

void show(){
    for (int i = 0; i < (1 << N); ++i)
        cout << superSeq[i] << endl;
}

int getAnswer(int idx){

    if (answer[idx] < N + 1)
        return answer[idx];
    
    int i = idx;
    int idx1 = idx, idx2 = 0;
    vector<int> powers;
    
    for (int p = 0; p < N; ++p){
        if (i % 2 == 1)
            powers.push_back(p);
        i /= 2;
    }

    vector<int> digit(powers.size(), 0);

    int tmp;
    for (int i = 1; i < (1 << (powers.size() - 1)); ++i){
        // Process of adding 1 to digit.
        for (int j = 0; j < powers.size(); ++j){
            if (digit[j]){
                digit[j] = 0;
                tmp = (1 << powers[j]);
                idx1 += tmp;
                idx2 -= tmp;
            }
            else {
                digit[j] = 1;
                tmp = (1 << powers[j]);
                idx1 -= tmp;
                idx2 += tmp;
                break;
            }
        }
        tmp = getAnswer(idx1) + getAnswer(idx2);
        answer[idx] = min(answer[idx], tmp);
    }
    return answer[idx];
}

void solve(){
    superSeq[0].assign(M, '.');
    for (int i = 1; i < (1 << N); ++i)
        makeSuperSeq(i);
    
    fill(&answer[1], &answer[(1 << N)], N + 1);

    for (int i = 1; i < (1 << N); ++i){
        if (!superSeq[i].empty())
            answer[i] = 1;
        else 
            getAnswer(i);
    }
    // show();
    cout << answer[(1 << N) - 1];
}

int main(int argc, char** argv)
{
    init();
    solve();
   return 0;
}