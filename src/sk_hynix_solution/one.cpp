#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(vector<int> &A, int max_diff) {
    sort(A.begin(), A.end());

    int ret = 0;
    int lo = 0, hi = 0;
    unordered_set<int> bucket;
    
    while (lo <= hi && hi < A.size()) {
        if (A[hi] - A[lo] <= max_diff) {
            bucket.insert(A[hi]);
            hi++;
            continue;
        }

        ret = max(ret, bucket.size());
        bucket.erase(A[lo]);
        lo++;        
    }

    return ret;
}