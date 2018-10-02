#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

static const auto syncOff = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    return nullptr;
}();

int solution(vector<int> &A) {
    unordered_set<int> seen;

    for (int num : A) {
        seen.insert(num);
    }
    int MAX = 1000000;
    for (int i = 1; i <= MAX; i++) {
        if (seen.count(i)) continue;

        return i;
    }

    return MAX;
}
