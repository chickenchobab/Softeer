#include<iostream>
#include <vector>
#include <algorithm>
#define hungry -1
#define full 0
#define MAX 1111

using namespace std;

int N, M, Q;
bool seats[22][22];
vector<int> status(10001, hungry); // hungry, eating, full

int getSafty(int r, int c){
    int d = MAX;

    if (seats[r + 1][c] || seats[r - 1][c] || seats[r][c + 1] || seats[r][c - 1])
        return 0;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            if (!seats[i][j]) continue;
            d = min(d, (i - r) * (i - r) + (j - c) * (j - c));
        }
    }
    return d;
}

void getIn(int id){
    if (status[id] == full) {
        cout << id << " already ate lunch.\n";
        return;
    }
    if (status[id] != hungry) {
        cout << id << " already seated.\n";
        return;
    }
    int curSafty, maxSafty = 0;
    int r, c;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            if (seats[i][j]) continue;
            if ((curSafty = getSafty(i, j)) > maxSafty){
                maxSafty = curSafty;
                r = i, c = j;
            }
        }
    }

    if (!maxSafty) 
        cout << "There are no more seats.\n";
    else {
        cout << id << " gets the seat (" << r << ", " << c << ").\n";
        status[id] = (r - 1) * M + c;
        seats[r][c] = 1;
    }
}

void getOut(int id){
    if (status[id] == hungry){
        cout << id << " didn't eat lunch.\n";
        return;
    }
    else if (status[id] == full){
        cout << id << " already left seat.\n";
        return;
    }
    int r = (status[id] - 1) / M + 1;
    int c = (status[id] - 1) % M + 1;
    cout << id << " leaves from the seat (" << r << ", " << c << ").\n";
    status[id] = full;
    seats[r][c] = 0;
}

int main(int argc, char** argv)
{
    cin >> N >> M >> Q;
    string work;
    int id;
    while (Q--){
        cin >> work >> id;
        if (work[0] == 'I') getIn(id);
        else getOut(id);
    }
   return 0;
}