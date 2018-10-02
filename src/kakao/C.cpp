#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int t;
    int N, K;
    cin >> N >> K;
    vec.clear();
    cout.precision(15);

    for (int j = 0; j < N; ++j) {
        int p;
        cin >> p;
        vec.push_back(p);
    }

    double ret = 987654321.0;
    for (int i = 0; i + K <= N; ++i) {
        double next = getDeviation(i, i + K, K);
        if (abs(ret - next) > 1e-8) {
            ret = next;
        }
    }

    cout << ret << endl;
    return 0;
}
