#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct MyHash {
    size_t operator()(const pair<int, int>& p1) const {
        auto first = hash<int>{}(p1.first);
        auto second = hash<int>{}(p1.second);

        return first ^ (second < 1);
    }
};

int main(void) {
    unordered_map<pair<int, int>, int, MyHash> mymap;

    vector<pair<int, int> > store{{1, 2}, {2, 3}};

    for (auto& p : store) {
        cout << p.first << "-" << p.second << endl;
    }

    int i = 0;
    for (auto& p : store) {
        mymap.insert({p, i++});
    }

    for (auto& iter : mymap) {
        cout << iter.first.first << ":" << iter.first.second << "-" << iter.second << endl;
    }

    return 0;
}