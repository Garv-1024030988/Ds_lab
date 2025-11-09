#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i, bool ascending) {
    int extreme = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (ascending) {
        if (left < n && arr[left] > arr[extreme]) extreme = left;
        if (right < n && arr[right] > arr[extreme]) extreme = right;
    } else {
        if (left < n && arr[left] < arr[extreme]) extreme = left;
        if (right < n && arr[right] < arr[extreme]) extreme = right;
    }

    if (extreme != i) {
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, ascending);
    }
}

void heapSort(vector<int>& arr, bool ascending = true) {
    int n = arr.size();

    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, ascending);

    
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, ascending);
    }

    if (!ascending)
        reverse(arr.begin(), arr.end());
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

  
    for (int x : arr) cout << x << " ";
    cout << endl;

    heapSort(arr, true);
   
    for (int x : arr) cout << x << " ";
    cout << endl;

    arr = {12, 11, 13, 5, 6, 7};
    heapSort(arr, false);
   
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
