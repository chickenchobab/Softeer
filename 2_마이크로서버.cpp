#include<iostream>
#include<algorithm>

using namespace std;
int T;
int N;
int m[100001];

void input(){
    cin >> N;
    for (int i = 1; i <= N; ++i) 
        cin >> m[i];
}

void solve(){
    int answer = 0;
    sort(m + 1, m + N + 1);

    int num300 = 0;
    for (int i = 1; i <= N && m[i] == 300; ++i){
        ++num300;
    }

    int s = num300 + 1;
    int e = N;
    
    while (s <= e){
        ++answer;
        if (m[e] > 600){ // this service cannot coexist.
            --e;
        }
        else if (s != e && m[s] + m[e] <= 900){ // both are under 600.
            ++s;
            --e;
        }
        else { // sum of both is over 900 or s == e
            if (num300 > 0) --num300; // combine with 300 if possible
            --e;
        }
    }

    answer += (num300 / 3) + (num300 % 3 != 0);
    cout << answer << '\n';
}

int main(int argc, char** argv)
{
    cin >> T;
    while(T--){
        input();
        solve();
    }
   return 0;
}