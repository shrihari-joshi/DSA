#include <iostream>
#include <climits>
using namespace std;

void findMinMax(int arr[], int i, int j, int &min, int &max) {
    // If there is only one element
    if (i == j) {
        min = arr[i];
        max = arr[i];
        return;
    }

    // If there are two elements
    if (i + 1 == j) {
        if (arr[i] < arr[j]) {
            if (arr[i] < min) min = arr[i];
            if (arr[j] > max) max = arr[j];
            return;
        } 
        
        if (arr[j] < min) min = arr[j];
        if (arr[i] > max) max = arr[i];
        
        return;
    }

    // If there are more than two elements
    int mid = (i + j) / 2;
    findMinMax(arr, i, mid, min, max);
    findMinMax(arr, mid + 1, j, min, max);
}

int main() {
    int arr[] = {12, 3, 5, 7, 19, -10, 18, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int min = INT_MAX;
    int max = INT_MIN;

    findMinMax(arr, 0, n - 1, min, max);

    cout << "Minimum element is " << min << endl;
    cout << "Maximum element is " << max << endl;

    return 0;
}
