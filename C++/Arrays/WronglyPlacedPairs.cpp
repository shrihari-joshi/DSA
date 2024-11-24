#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& v, int start, int mid, int end) {
    int count = 0;
    vector<int> temp (end - start + 1);
    int i = start, j= mid+1, k=0;
   

    while (i<=mid && j<=end)
    {
        if(v[i] <= v[j])
            temp[k++] = v[i++];
        else
        {
            temp[k++] = v[j++];
            count+= mid-i+1;
        }
    }

    while(i<=mid) temp[k++] = v[i++];
    while(j<=end) temp[k++] = v[j++];

    for(int i=start, k=0;i<=end; ++i,++k)
        v[i] = temp[k];

    return count;
}

int mergeSort(vector<int>& v, int start, int end) {
    int count = 0;
    if (start < end) {
        int mid = start + (end - start) / 2;
        count += mergeSort(v, start, mid);
        count += mergeSort(v, mid + 1, end);
        count += merge(v, start, mid, end);
    }
    return count;
}

int main() {
    vector<int> v = {5,4,3,2,1};
    int count = mergeSort(v, 0, v.size() - 1);
    
    if (count == 0) {
        cout << "Array elements are already placed at the right positions." << endl;
    } else {
        cout << "The array is not correctly sorted by " << count << " pairs." << endl;
    }
    
    return 0;
}
