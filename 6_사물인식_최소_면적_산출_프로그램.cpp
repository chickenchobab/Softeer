#include<iostream>
#include <vector>

using namespace std;

int N, K;
vector<pair<int, int>> points[101];
int answer;

void input(){
    cin >> N >> K;
    int r, c, k;
    for (int i = 0; i < N; ++i){
        cin >> r >> c >> k;
        points[k].push_back({r, c});
    }
}

void pickPoint(int color, int top, int bottom, int left, int right){
    if (color > K){
        answer = min(answer, (bottom - top) * (right - left));
        return;
    }

    for (auto point : points[color]){
        auto [r, c] = point;
        int newTop = min(top, r);
        int newBottom = max(bottom, r);
        int newLeft = min(left, c);
        int newRight = max(right, c);
        if (answer <= (newBottom - newTop) * (newRight - newLeft)) continue;
        pickPoint(color + 1, newTop, newBottom, newLeft, newRight);
    }
}

void solve(){
    answer = 4000004;
    for (auto point : points[1]){
        auto [r, c] = point;
        pickPoint(2, r, r, c, c);
    }
    cout << answer;
}

int main(int argc, char** argv)
{
    input();
    solve();
   return 0;
}