#include<iostream>
#include <vector>
using namespace std;

int T;
string A, B;
string strs[11];

void init(){
    strs[0] = "1110111";
    strs[1] = "0010010";
    strs[2] = "1011101";
    strs[3] = "1011011";
    strs[4] = "0111010";
    strs[5] = "1101011";
    strs[6] = "1101111";
    strs[7] = "1110010";
    strs[8] = "1111111";
    strs[9] = "1111011";
    strs[10] = "0000000";
}

int getCount(int x, int y){
    int ret = 0;
    for (int i = 0; i < 7; ++i){
        ret += (strs[x][i] != strs[y][i]);
    }
    return ret;
}

void solve(){
    int cnt = 0;

    int diff;
    diff = 5 - (int)A.length();
    while (diff--) A = 'X' + A;
    diff = 5 - (int)B.length();
    while (diff--) B = 'X' + B;
    
    for (int i = 0; i < 5; ++i){
        int a = (A[i] == 'X' ? 10 : A[i] - '0');
        int b = (B[i] == 'X' ? 10 : B[i] - '0');
        cnt += getCount(a, b);
    }
    cout << cnt << '\n';
}

int main(int argc, char** argv)
{
    init();
    cin >> T;
    while (T--){
        cin >> A >> B;
        solve();
    }
   return 0;
}