#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char** grid;
char** block;
int** cache;
int H, W, R, C;
bool isEnd(int y, int x) {
    return y == H && x == 0;
}
bool isValid(int y, int x) {
    return 0 <= y < H && 0 <= x < W;
}
bool isBlack(int y, int x) {
    return grid[y][x] == '#' || grid[y][x] == 'x';
}

bool isFitBlock(int y, int x) {
    for (int ny = 0; ny < R; ++ny) {
        for (int nx = 0; nx < C; ++nx) {
            if (!isValid(y + ny, x + nx)) {
                return false;
            }

            if (grid[y + ny][x + nx] != block[ny][nx]) {
                return false;
            }
        }
    }
    return true;
}
void setBlock(int y, int x, char mode) {
    for (int ny = 0; ny < R; ++ny) {
        for (int nx = 0; nx < C; ++nx) {
            grid[y + ny][x + nx] = mode;
        }
    }
}
int getMaxBlocks(int y, int x) {
    int newY = y + ((x + 1) / W);
    int newX = (x + 1) % W;

    if (isEnd(y, x)) return 0;
    int& ret = cache[y][x];
    if (ret != -1) return ret;
    if (!isValid(y, x) || isBlack(y, x)) return getMaxBlocks(newY, newX);
    if (isFitBlock(y, x)) {
        setBlock(y, x, 'x');
        ret = getMaxBlocks(newY, newX) + 1;
        setBlock(y, x, '.');
        return ret;
    }
    cout << y << " " << x << endl;
    return getMaxBlocks(newY, newX);
}

int main(void) {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> H >> W >> R >> C;
        cache = new int*[H + 1];
        for (int i = 0; i < H + 1; ++i) {
            cache[i] = new int[W + 1];
            for (int j = 0; j < W + 1; ++j) {
                cache[i][j] = -1;
            }
        }
        grid = new char*[H];
        for (int i = 0; i < H; ++i) {
            string lines;
            cin >> lines;
            grid[i] = new char[W];
            for (int j = 0; j < W; ++j) {
                grid[i][j] = lines[j];
            }
        }

        block = new char*[R];
        for (int i = 0; i < R; ++i) {
            string line;
            cin >> line;
            block[i] = new char[C];
            for (int j = 0; j < C; ++j) {
                block[i][j] = line[j];
            }
        }
        cout << getMaxBlocks(0, 0) << endl;
    }
}

/////

vector<vector<pair<int, int> > > rotations;
int blockSize;
vector<string> rotate(const vector<string>& arr) {
    vector<string> ret(arr[0].size(), string(arr.size(), ' '));
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr[0].size(); ++j) {
            ret[j][arr.size() - i - 1] = arr[i][j];
        }
    }
    return ret;
}

void generateRotations(vector<string> block) {
    rotations.clear();
    rotations.resize(4);

    for (int rot = 0; rot < 4; ++rot) {
        int originY = -1, originX = -1;
        for (int i = 0; i < block.size(); ++i) {
            for (int j = 0; j < block[i].size(); ++j) {
                if (block[i][j] == '#') {
                    if (originY == -1) {
                        originY = i;
                        originX = j;
                    }
                    rotations[rot].push_back(make_pair(i - originY, j - originX));
                }
            }
        }
        block = rotate(block);
    }

    sort(rotations.begin(), rotations.end());
    rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
    blockSize = rotations[0].size();
}

int boardH, boardW;
vector<string> board;
int covered[10][10];
int best;

bool set(int y, int x, const vector<pair<int, int> >& block, int delta);
void search(int placed) {
    int y = -1, x = -1;
    for (int i = 0; i < boardH, ++i) {
        for (int j = 0; < boardW; ++j) {
            if (covered[i][j] == 0) {
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1) {
            break;
        }
    }

    if (y == -1) {
        best = max(best, placed);
        return;
    }

    for (int i = 0; i < rotations.size(); ++i) {
        if (set(y, x, rotations[i], 1)) {
            search(placed + 1);
        }
        set(y, x, rotations[i], -1);
    }
    covered[y][x] = 1;
    search(placed);
    covered[y][x] = 0;
}
int solve() {
    best = 0;
    for (int i = 0; i < boardH; ++i) {
        for (int j = 0; j < boardW; ++j) {
            covered[i][j] = (board[i][j] == '#' ? 1 : 0);
        }
    }
    search(0);
    return best;
}

void cyclic_roll(int& a, int& b, int& c, int& d) {
    int temp = a;
    a = b;
    b = c;
    c = d;
    d = temp;
}
void rotate(char** m) {
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < (n + 1) / 2; j++)
            cyclic_roll(m[i][j], m[n - 1 - j][i], m[n - 1 - i][n - 1 - j], m[j][n - 1 - i]);
}