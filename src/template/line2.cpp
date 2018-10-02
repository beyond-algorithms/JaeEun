#include <cassert>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

#define MIN_VALUE -2147483648;
#define MAX_VALUE 2147483647;

using namespace std;

char _prev = 'B';
vector<vector<string> > mat;
vector<vector<bool> > visited;

bool isEnd(int y, int x, char next) {
    if (_prev == 'F' && next == 'F') {
        return visited[y + 1][x];
    }
    if (_prev == 'F' && next == 'R') {
        return visited[y][x + 1];
    }
    if (_prev == 'F' && next == 'L') {
        return visited[y][x - 1];
    }
    if (_prev == 'F' && next == 'B') {
        return visited[y - 1][x];
    }

    if (_prev == 'R' && next == 'F') {
        return visited[y][x + 1];
    }
    if (_prev == 'R' && next == 'R') {
        return visited[y - 1][x];
    }
    if (_prev == 'R' && next == 'L') {
        return visited[y + 1][x];
    }
    if (_prev == 'R' && next == 'B') {
        return visited[y][x - 1];
    }

    if (_prev == 'L' && next == 'F') {
        return visited[y][x - 1];
    }
    if (_prev == 'L' && next == 'R') {
        return visited[y + 1][x];
    }
    if (_prev == 'L' && next == 'L') {
        return visited[y - 1][x];
    }
    if (_prev == 'L' && next == 'B') {
        return visited[y][x + 1];
    }

    if (_prev == 'B' && next == 'F') {
        return visited[y - 1][x];
    }
    if (_prev == 'B' && next == 'R') {
        return visited[y][x - 1];
    }
    if (_prev == 'B' && next == 'L') {
        return visited[y][x + 1];
    }
    if (_prev == 'B' && next == 'B') {
        return visited[y + 1][x];
    }
}

void solve(int y, int x) {
    string next = mat[y][x];

    char next = mat[0];
    int len = mat[1] - '0';

    if (isEnd(y, x)) {
        cout << x << " " << y << endl;
        return;
    }

    if (_prev == 'F' && next == 'F') {
        _prev = 'F';
        return solve(y + 1, x);
    }
    if (_prev == 'F' && next == 'R') {
        _prev = 'R';
        return solve(y, x + 1);
    }
    if (_prev == 'F' && next == 'L') {
        _prev = 'L';
        return solve(y, x - 1);
    }
    if (_prev == 'F' && next == 'B') {
        _prev = 'B';
        return solve(y - 1, x);
    }

    if (_prev == 'R' && next == 'F') {
        _prev = 'F';
        return solve(y, x + 1);
    }
    if (_prev == 'R' && next == 'R') {
        _prev = 'R';
        return solve(y - 1, x);
    }
    if (_prev == 'R' && next == 'L') {
        _prev = 'L';
        return solve(y + 1, x);
    }
    if (_prev == 'R' && next == 'B') {
        _prev = 'B';
        return solve(y, x - 1);
    }

    if (_prev == 'L' && next == 'F') {
        _prev = 'F';
        return solve(y, x - 1);
    }
    if (_prev == 'L' && next == 'R') {
        _prev = 'R';
        return solve(y + 1, x);
    }
    if (_prev == 'L' && next == 'L') {
        _prev = 'L';
        return solve(y - 1, x);
    }
    if (_prev == 'L' && next == 'B') {
        _prev = 'B';
        return solve(y, x + 1);
    }

    if (_prev == 'B' && next == 'F') {
        _prev = 'F';
        return solve(y - 1, x);
    }
    if (_prev == 'B' && next == 'R') {
        _prev = 'R';
        return solve(y, x - 1);
    }
    if (_prev == 'B' && next == 'L') {
        _prev = 'L';
        return solve(y, x + 1);
    }
    if (_prev == 'B' && next == 'B') {
        _prev = 'B';
        return solve(y + 1, x);
    }
}

int main(int argc, char **argv) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    int len = (n + 1) * (n + 1);
    mat = vector<vector<string> >(len, "");
    visited = vector<vector<bool> >(len, false);

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            string node;
            cin >> node;

            mat[y][x] = node;
        }
    }

    solve(0, 0);
    cout << endl;

    return 0;
}
