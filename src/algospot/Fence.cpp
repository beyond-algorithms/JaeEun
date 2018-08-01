#include <iostream>
#include <vector>

using namespace std;
bool isValid(int left, int right, vector<int> &vec) {
    return 0 <= left && right <= vec.size();
}
int getMiddleArea(int left, int right, vector<int> &vec) {
    int m = (left + right) / 2;

    int _max = vec[m];
    int len = 1;
    int l = m;
    int r = m + 1;

    int height = min(vec[l], vec[r]);
    _max = max(_max, height * 2);
    while (left < l || r < right) {
        if (r < right && (l == left || vec[l - 1] < vec[r + 1])) {
            r++;
            height = min(height, vec[r]);
        } else {
            l--;
            height = min(height, vec[l]);
        }
        _max = max(_max, height * (r - l + 1));

        // int l_height = min(height, vec.at(l - 1));
        // int r_height = min(height, vec.at(r + 1));
        // int both_height = min(l_height, r_height);

        // int l_max = l_height * (len + 1);
        // int r_max = r_height * (len + 1);
        // int both_max = both_height * (len + 2);

        // if (l_max > _max) {
        //     len++;
        //     l--;
        //     _max = l_max;
        //     height = l_height;
        // } else if (r_max > _max) {
        //     len++;
        //     r++;
        //     _max = r_max;
        //     height = r_height;
        // } else if (both_max > _max) {
        //     len += 2;
        //     l--;
        //     r++;
        //     _max = both_max;
        //     height = both_height;
        // } else {
        //     break;
        // }
    }
    return _max;
}
int getMaxCuttingSquare(int left, int right, vector<int> &vec) {
    if (left == right) {
        return vec[left];
    }

    int m = (left + right) / 2;
    int leftArea = getMaxCuttingSquare(left, m, vec);
    int rightArea = getMaxCuttingSquare(m + 1, right, vec);
    int middleArea = getMiddleArea(left, right, vec);

    int ret = 0;
    ret = max(ret, leftArea);
    ret = max(ret, rightArea);
    ret = max(ret, middleArea);

    return ret;
}

int main(void) {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int N;
        cin >> N;
        vector<int> vec;
        for (int j = 0; j < N; ++j) {
            int num;
            cin >> num;
            vec.push_back(num);
        }

        int ret = getMaxCuttingSquare(0, vec.size() - 1, vec);
        cout << ret << endl;
    }
}