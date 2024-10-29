#include<iostream>
#include <set>
#include <string>
#include <unordered_set>

using namespace std;
int N, M;
set<string> rooms;
unordered_set<string> reservation[10];

void solve(){
    int cnt;
    bool inMeeting = 0;
    string info;

    for (auto it = rooms.begin(); it != rooms.end(); ++it){
        cnt = 0;
        inMeeting = 1;
        info = "";

        if (it != rooms.begin()) cout << "-----\n";

        reservation[9].insert(*it);
        cout << "Room " << (*it) << ":\n";
        
        for (int time = 0; time < 10; ++time){
            int printedTime = time + 9;
            if (inMeeting){
                if (!reservation[time].count(*it)){
                    if (printedTime < 10) info += '0';
                    info += (to_string(printedTime) + '-');
                    inMeeting = 0;
                    ++cnt;
                }
            } 
            else{
                if (reservation[time].count(*it)) {
                    if (printedTime < 10) info += '0';
                    info += (to_string(printedTime) + '\n');
                    inMeeting = 1;
                }
            }
        }
        if (cnt){
            cout << cnt << " available:\n";
            cout << info << '\n';
        }
        else {
            cout << "Not available\n";
        }
    }
}

int main(int argc, char** argv)
{
    cin >> N >> M;
    string room;
    int s, e;
    for (int i = 0; i < N; ++i){
        cin >> room;
        rooms.insert(room);
    }
    for (int i = 0; i < M; ++i){
        cin >> room;
        cin >> s >> e;
        s -= 9, e -= 9;
        for (int time = s; time < e; ++time){
            reservation[time].insert(room);
        }
    }
    solve();
   return 0;
}