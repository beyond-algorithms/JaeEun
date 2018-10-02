#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve(string str) {
    vector<string> ret;

    int prev = 0;
    for (int i = 0; i < str.size(); i++) {
        while ((i + 1) < str.size() && str[i] == str[i + 1]) {
            i++;
        }
        // cout << prev << "-" << i << endl;
        ret.push_back(str.substr(prev, i - prev + 1));
        prev = i + 1;
    }

    for (string str1 : ret) {
        cout << str1 << endl;
    }
}

int main(void) {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string str;
        cin >> str;

        solve(str);
    }

    return 0;
}