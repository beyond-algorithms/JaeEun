#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printArr(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(vector<int>& arr, int lo, int hi) {
    // int pivot = arr[hi];

    // int i = lo;
    // for (int j = lo; j < hi; j++) {
    //     if (arr[j] > pivot) {
    //         continue;
    //     }

    //     swap(arr, i, j);
    //     i++;
    // }
    // swap(arr, i, hi);
    // return i;

    int mid = (lo + hi) / 2;
    int i = lo, j = hi, pivot = arr[mid];
    
    while (true) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i == j) return j;

        swap(arr, i, j);
    }
}

vector<int> quickSort(vector<int>& arr, int lo, int hi) {
    if (lo > hi) return vector<int>();

    int p = partition(arr, lo, hi);

    quickSort(arr, lo, p - 1);
    quickSort(arr, p + 1, hi);

    return arr;
}

vector<int> mergeSort(const vector<int>& arr, int lo, int hi) {
    if (arr.empty()) return arr;
    if (lo > hi) return vector<int>();
    if (lo == hi) return vector<int>(1, arr[lo]);

    int mid = (lo + hi) / 2;
    vector<int> left = mergeSort(arr, lo, mid);
    vector<int> right = mergeSort(arr, mid + 1, hi);

    vector<int> merged;
    int l = 0, r = 0;
    for (; l < left.size() && r < right.size();) {
        if (left[l] < right[r]) {
            merged.push_back(left[l]);
            l++;
            continue;
        }
        if (right[r] < left[l]) {
            merged.push_back(right[r]);
            r++;
            continue;
        }
    }
    for (int i = l; i < left.size(); i++) {
        merged.push_back(left[i]);
    }
    for (int i = r; i < right.size(); i++) {
        merged.push_back(right[i]);
    }

    return merged;
}

const char* a() {
    std::string mystr("abc");

    return mystr.c_str();
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> arr2 = {3, 2, 5, 6, 10};
    vector<int> arr3 = {};
    vector<int> arr4 = {5, 129, 122, 12, 6, 0, 9, 44, 41, 32, 17};

    vector<int> sorted = mergeSort(arr, 0, arr.size() - 1);

    printArr(mergeSort(arr, 0, arr.size() - 1));
    printArr(mergeSort(arr2, 0, arr2.size() - 1));
    printArr(mergeSort(arr3, 0, arr3.size() - 1));
    printArr(mergeSort(arr4, 0, arr4.size() - 1));

    printArr(quickSort(arr, 0, arr.size() - 1));
    printArr(quickSort(arr2, 0, arr2.size() - 1));
    printArr(quickSort(arr3, 0, arr3.size() - 1));
    printArr(quickSort(arr4, 0, arr4.size() - 1));

    return 0;
}
