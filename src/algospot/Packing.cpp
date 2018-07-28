#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_map<string, pair<int, int> > stuff;
unordered_set<string> ans;
unordered_map<int, int> dp;

void solve(int, int);
int main(void) {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        stuff.clear();
        ans.clear();
        dp.clear();
        int numberOfStuff, capacity;
        cin >> numberOfStuff >> capacity;

        for (int j = 0; j < numberOfStuff; j++) {
            string name;
            int volume, desp;
            cin >> name >> volume >> desp;

            stuff[name] = make_pair(volume, desp);
        }

        solve(numberOfStuff, capacity);
        cout << endl;
    }
}
int getMaxDesp(int capacity, int currentVolumns, unordered_set<string> candidate) {
    if (candidate.empty()) {
        return 0;
    }

    int ret = 0;
    auto iter = candidate.begin();
    while (iter != candidate.end()) {
        string nextCandidateName = *(iter++);

        auto next = stuff[nextCandidateName];
        int volume = next.first;
        int desp = next.second;

        candidate.erase(nextCandidateName);
        if (currentVolumns + volume <= capacity) {
            int nextRes = getMaxDesp(capacity, currentVolumns + volume, candidate) + desp;
            if (nextRes > ret) {
                ret = nextRes;

                ans = candidate;             
            }
        }
        candidate.insert(nextCandidateName);
    }
    return ret;
}
void solve(int numberOfStuff, int capacity) {
    unordered_set<string> candidate;
    auto iter = stuff.begin();
    for (; iter != stuff.end(); ++iter) {
        candidate.insert(iter->first);
    }
    int maxDesp = getMaxDesp(capacity, 0, candidate);

    for (auto i = ans.begin(); i != ans.end(); ++i) {
        if (stuff.find(*i) != stuff.end()) {
            stuff.erase(*i);
        }
    }
    cout << maxDesp << " " << stuff.size() << endl;
    for (auto iter = stuff.begin(); iter != stuff.end(); ++iter) {
        cout << (*iter).first << endl;
    }
}