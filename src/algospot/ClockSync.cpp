#include <iostream>
#include <string>
#include <vector>

#define INF 987654321

using namespace std;

int _switch[][16] = {
    // 0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}};

bool isAllAligned(vector<int> &vec) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] != 0) {
            return false;
        }
    }
    return true;
}

void push_switch(int s, vector<int> &vec) {
    for (int _clock = 0; _clock < 16; ++_clock) {
        if (_switch[s][_clock]) {
            vec[_clock] += 3;
            vec[_clock] %= 12;
        }
    }
}

int solve(int s, vector<int> &vec) {
    if (s == 10) {
        return isAllAligned(vec) ? 0 : INF;
    }

    int ret = INF;
    for (int i = 0; i < 4; ++i) {
        ret = min(ret, i + solve(s + 1, vec));
        push_switch(s, vec);
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        vector<int> vec;
        for (int j = 0; j < 16; ++j) {
            int times;

            cin >> times;
            vec.push_back(times % 12);
        }
        int ret = solve(0, vec);
        int ans = ret == INF ? -1 : ret;
        cout << ans << endl;
    }
}