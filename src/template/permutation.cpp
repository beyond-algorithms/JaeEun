#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> p_numbers;

void makeNumber(vector<int>& numbers, vector<bool>& selected, int num) {
    if (num > 0) {
        p_numbers.push_back(num);
    }

    for (int i = 0; i < numbers.size(); i++) {
        if (selected[i]) continue;
        
        selected[i] = true;
        makeNumber(numbers, selected, num * 10 + numbers[i]);
        selected[i] = false;
    }
}

void solve(string numbers) {
    vector<int> vec;
    for_each(numbers.begin(), numbers.end(), [&vec](char ch) { vec.push_back(ch - '0'); });

    vector<bool> selected(vec.size(), false);
    makeNumber(vec, selected, 0);

    for_each(p_numbers.begin(), p_numbers.end(), [](int i) { cout << i << endl; });
}

int main(void) {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string numbers;
        cin >> numbers;
        
        solve(numbers);
        cout << endl;
    }

    return 0;
}