// 4 3 7 6 9
// 4   7 6
//   3   6 9

#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>

using namespace std;

map<int, vector<int> > cache;
vector<int> getPartialLIS(int idx, const vector<int> &vec) {
    if (cache.find(idx) != cache.end()) {
        return cache[idx];
    }
    cout << "T ";
    vector<int> res;
    int last = -1;

    for (int i = idx; i < vec.size(); ++i) {
        if (vec[i] > last) {
            res.push_back(vec[i]);
            last = vec[i];
        }
    }

    return cache[idx] = res;
}

void insertAllToSet(vector<int> &A, unordered_set<int> &set) {
    for (int i = 0; i < A.size(); ++i) {
        set.insert(A[i]);
    }
}

int solve(vector<int> &A, vector<int> &B) {
    int ret = -1;

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); ++j) {
            vector<int> ALIS = getPartialLIS(i, A);
            vector<int> BLIS = getPartialLIS(j, B);

            unordered_set<int> set;

            insertAllToSet(A, set);
            insertAllToSet(B, set);

            ret = max(ret, (int)set.size());
        }
    }

    return ret;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, m;
        cin >> n >> m;
        cache.clear();

        vector<int> A, B;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            A.push_back(num);
        }
        for (int i = 0; i < m; ++i) {
            int num;
            cin >> num;
            B.push_back(num);
        }

        cout << solve(A, B) << endl;
    }
}