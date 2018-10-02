#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<double> vec;
double getDeviation(int start, int K) {
    double sum = 0.0;

    for (int i = start; i < start + K; ++i) {
        sum += vec[i];
    }
    double average = (sum / K);
    double devi = 0.0;
    for (int i = start; i < start + K; ++i) {
        devi += std::pow(vec[i] - average, 2.0);
    }

    return std::sqrt(devi / K);
}

int main(void) {
    int t;
    int N, K;
    cin >> N >> K;
    vec.clear();
    cout.precision(15);

    for (int j = 0; j < N; ++j) {
        double p;
        cin >> p;
        vec.push_back(p);
    }

    double ret = 987654321.0;
    for (int i = 0; i + K <= N; ++i) {
        for (int j = K; j + i <= N; ++j) {
            double next = getDeviation(i, j);
            if (next < ret) {
                ret = next;
            }
        }
    }

    cout << ret << endl;
    return 0;
}
