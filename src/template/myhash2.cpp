#include <iostream>
#include <unordered_map>
#include <vector>

template <class T1, class T2>
struct Cordination {
    T1 x;
    T2 y;

    friend bool operator == (const Cordination &c1, const Cordination &c2) {
        return (c1.x == c2.x) && (c1.y == c2.y);
    }

    Cordination(T1 _x, T2 _y) {
       x = _x;
       y = _y;
    }
};

using namespace std;
using Coords = Cordination<int, int>;

struct CoordsHash {
    size_t operator() (const Coords &c) const {
        auto first = hash<int>{}(c.x);
        auto second = hash<int>{}(c.y);

        return first ^ (second < 1);
    }
};

static const auto syncoff = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    return nullptr;
}();

int main(void) {
    vector<Coords> store {{1, 2}, {1, 4}, {1, 5}, {1, 6}, {1, 4}, {1, 4}, {1, 4}, {1, 4}};

    for (Coords& c : store) {
        cout << c.x << "-" << c.y << endl;
    }

    unordered_map<Coords, vector<int>, CoordsHash> mm;
    
    int idx = 0;
    for (auto c : store) {
        mm[c].push_back(idx++);
    }

    for (auto& iter : mm) {
        cout << "x: " << iter.first.x << " - "
             << "y: " << iter.first.y << endl;

        for (int i : iter.second) {
            cout << "val: " << i << endl;
        }
    }
    (void)0;
    (void)0;
    (void)0;
    (void)0;
    (void)0;
    cout << __FILE__ << endl;
    cout << __LINE__ << endl;
    return 0;
}