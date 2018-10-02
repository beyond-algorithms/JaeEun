#include <iostream>
#include <vector>

using namespace std;

int getFirstPrize(int rank) {
    if (rank == 0 || rank > 21) {
        return 0;
    } 
    if (rank == 1) {
        return 500;
    } else if (rank <= 3) {
        return 300;
    } else if (rank <= 6) {
        return 200;
    } else if (rank <= 10) {
        return 50;
    } else if (rank <= 15) {
        return 30;
    }
    return 10;
}

int getSecondPrize(int rank) {
    if (rank == 0 || rank > 31){
        return 0;
    }
    
    if (rank == 1) {
        return 512;
    } else if (rank <= 3) {
        return 256;
    } else if (rank <= 7) {
        return 128;
    } else if (rank <= 15) {
        return 64;
    } else if (rank <= 31) {
        return 32;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int a, b;
        cin >> a >> b;

        cout << (getFirstPrize(a) + getSecondPrize(b)) * 10000 << endl;
    }
}