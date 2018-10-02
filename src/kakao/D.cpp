#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

vector<pair<int, int> > checkpoints;
unordered_set<int> visited;
unordered_map<int, unordered_map<int, int> > dp;

bool possible(int from, int to, int HP) {
    // cout << from << "-" << to << endl;
    if (from == to) {
        return true;
    }
    if (HP < 0) {
        return false;
    }
    if (dp[from][to] != 0) {
        cout << "hit" << endl;
        return dp[from][to] - 1 <= HP ? true : false;
    }
    if (visited.count(from)) {
        return false;
    }

    auto current = checkpoints[from];
    visited.insert(from);

    bool ret = false;
    for (int i = 1; i < checkpoints.size(); ++i) {
        
        auto p = checkpoints[i];
        if (visited.count(i)) continue;

        int delX = abs(current.first - p.first);
        if (delX <= HP) {
            int remainHP = HP - delX;
            ret = ret || possible(i, to, remainHP);
        }
        int delY = abs(current.second - p.second);
        if (delY <= HP) {
            int remainHP = HP - delY;
            ret = ret || possible(i, to, remainHP);
        }
    }
    // cout << from << "-" << to << "-" << HP << endl;
    if (ret) {
        dp[from][to] = HP + 1;
    }
    return ret;
}

int main(void) {
    int N, Q;
    cin >> N >> Q;
    dp.clear();
    checkpoints.resize(N + 1);

    for (int i = 1; i < N + 1; ++i) {
        int from, to;
        cin >> from >> to;
        checkpoints[i] = make_pair(from, to);
    }

    for (int i = 0; i < Q; ++i) {
        int from, to, HP;
        cin >> from >> to >> HP;
        visited.clear();

        string ans = possible(from, to, HP) ? "YES" : "NO";
        cout << ans << endl;
    }

    return 0;
}
