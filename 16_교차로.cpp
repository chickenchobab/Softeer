#include<iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
queue<pair<int, int>> cross[4];
vector<int> answer;

void input(){
    cin >> N;
    int time;
    char w;
    for (int car = 1; car <= N; ++car){
        cin >> time >> w;
        int pos = w - 'A';
        cross[pos].push({car, time});
    }
}

int updateTime(int time){
    int earliest = 1e9;
    for (int pos = 0; pos < 4; ++pos){
        if (cross[pos].empty()) continue;
        earliest = min(earliest, cross[pos].front().second);
    }
    return max(earliest, time);
}

void solve(){
    int time = 0;
    answer.assign(N + 1, -1);
    
    while (1){
        vector<int> departures;
        time = updateTime(time);
        
        for (int pos = 0; pos < 4; ++pos){
            // Check cars arrived.
            if (cross[pos].empty()) continue;
            if (cross[pos].front().second > time) continue;
            
            // Car at right is done or has not arrived yet.
            if (cross[(pos + 3) % 4].empty() || cross[(pos + 3) % 4].front().second > time)
                departures.push_back(pos);
        }

        if (departures.empty()) break;

        for (auto pos : departures){
            answer[cross[pos].front().first] = time;
            cross[pos].pop();
        }
        ++time;
    }

    for (int car = 1; car <= N; ++car)
        cout << answer[car] << '\n';
}

int main(int argc, char** argv)
{
    input();
    solve();
   return 0;
}