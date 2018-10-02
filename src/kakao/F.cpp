// #include <iostream>
// #include <vector>

// using namespace std;

// int getMiddleArea(int left, int right, vector<int> &vec) {
//     int m = (left + right) / 2;

//     int _max = vec[m];
//     int len = 1;
//     int l = m;
//     int r = m + 1;

//     int height = min(vec[l], vec[r]);
//     _max = max(_max, height * 2);
//     while (left < l || r < right) {
//         int rightMax = 0;
//         int leftMax = 0;
//         if (r < right && (l == left || vec[l - 1] < vec[r + 1])) {
//             r++;
//             height = min(height, vec[r]);

//             for (int i = r + 1; i < right; ++i) {
//                 rightMax = max(rightMax, vec[i] * (i-r);
//             }

//         } else {
//             l--;
//             height = min(height, vec[l]);

//             for (int i = l - 1; i > left; --i) {
//                 leftMax = max(leftMax, vec[i] * (i-l);
//             }
//         }
//         int curMax = height * (r - l + 1);
//         _max = max(_max, curMax + rightMax);
//         _max = max(_max, curMax + leftMax);
//     }

//     return _max;
// }

// int getMaxCuttingSquare(int left, int right, vector<int> &vec) {
//     if (left == right) {
//         return vec[left];
//     }

//     int m = (left + right) / 2;
//     int leftArea = getMaxCuttingSquare(left, m, vec);
//     int rightArea = getMaxCuttingSquare(m + 1, right, vec);
//     int middleArea = getMiddleArea(left, right, vec);

//     int ret = 0;
//     ret = max(ret, leftArea);
//     ret = max(ret, rightArea);
//     ret = max(ret, middleArea);

//     return ret;
// }

// int main(void) {
//     int N;
//     cin >> N;
//     vector<int> vec;
//     for (int j = 0; j < N; ++j) {
//         int num;
//         cin >> num;
//         vec.push_back(num);
//     }

//     int ret = getMaxCuttingSquare(0, vec.size() - 1, vec);
//     cout << ret << endl;
// }