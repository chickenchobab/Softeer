#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

string message, key;
char mat[5][5];
vector<int> row(26, -1), col(26, -1);
vector<pair<char, char>> pairs;

void input(){
    cin >> message >> key;
}

void makeMatrix(){

    int r = 0, c = 0;
    int idx;
    
    for (char ch : key){
        idx = ch - 'A';
        if (row[idx] != -1) continue;
        row[idx] = r;
        col[idx] = c;
        mat[r][c] = ch;
        if (++c == 5) ++r, c = 0;
    }

    for (char ch = 'A'; ch < 'J'; ++ch){
        idx = ch - 'A';
        if (row[idx] != -1) continue;
        row[idx] = r;
        col[idx] = c;
        mat[r][c] = ch;
        if (++c == 5) ++r, c = 0;
    }
    for (char ch = 'K'; ch <= 'Z'; ++ch){
        idx = ch - 'A';
        if (row[idx] != -1) continue;
        row[idx] = r;
        col[idx] = c;
        mat[r][c] = ch;
        if (++c == 5) ++r, c = 0;
    }
}

void separateMessage(){
    int i;
    for (i = 0; i < message.length() - 1;){
        if (message[i] == message[i + 1]){
            pairs.push_back({message[i], (message[i] == 'X' ? 'Q' : 'X')});
            ++i;
        }
        else {
            pairs.push_back({message[i], message[i + 1]});
            i = i + 2;
        }
    }
    if (i == message.length() - 1)
        pairs.push_back({message.back(), 'X'});
}


string decipher(){
    string answer = "";

    char a, b;
    int i, j;
    for (auto p : pairs){
        int i = p.first - 'A';
        int j = p.second - 'A';
        
        if (row[i] == row[j]){
            a = mat[row[i]][(col[i] + 1) % 5];
            b = mat[row[i]][(col[j] + 1) % 5];
        }
        else if (col[i] == col[j]){
            a = mat[(row[i] + 1) % 5][col[i]];
            b = mat[(row[j] + 1) % 5][col[i]]; 
        }
        else {
            a = mat[row[i]][col[j]];
            b = mat[row[j]][col[i]];
        }
        answer += a;
        answer += b;
    }

    return answer;
}

void solve(){
    makeMatrix();
    separateMessage();
    cout << decipher();
}

int main(int argc, char** argv)
{
    input();
    solve();
   return 0;
}