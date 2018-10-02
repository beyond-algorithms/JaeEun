#include <cassert>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define MIN_VALUE -2147483648;
#define MAX_VALUE 2147483647;

using namespace std;

// static auto const syncOff = []() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(nullptr);
// 	return nullptr;
// }();

int solve(void) {
    return 0;
}

int getcharges(int dis) {
    int ret = (dis - 1) / 8;

    if (dis < 5) return 720;

    return 720 + (ret - 4) * 80;
}

int main(int argc, char **argv) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int remain = 20000;
    
    while (cin.peek() != EOF) {
        int dis;
        cin >> dis;

        cout << dis << endl;
        if (dis < 4 || dis > 178) break;

        int minus = getcharges(dis);
        if (remain - minus < 0) break;
        // cout << minus << endl;
        // cout << endl;
        remain -= minus;
    }

    cout << remain;
    return 0;
}
