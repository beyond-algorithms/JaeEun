#include <iostream>

using namespace std;

int main(void) {
    int i;
    while (cin.peek() != EOF) {
        int num;
        cin >> num;

        cout << num << " ";
    }

    return 0;
}