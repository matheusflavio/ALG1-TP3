#include <bits/stdc++.h>
using namespace std;
 
vector<int> res;
 
// utility Binary search
int ceilBinarySearch(vector<int> arr, vector<int>& T, int l, int r, int key) {
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (arr[T[m]] >= key)
            r = m;
        else
            l = m;
    }
    return r;
}
 
// function to find LIS in reverse form
void longestIncreaseSubArray(vector<int> arr, int n) {
    // Add boundary case, when array n is zero
    // Depend on smart pointers
    vector<int> tailIndices(n, 0); // Initialized with 0
    vector<int> prevIndices(n, -1); // initialized with -1
 
    int len = 1; // it will always point to empty location
    for (int i = 1; i < n; i++) {
 
        // new smallest value
        if (arr[i] < arr[tailIndices[0]])            
            tailIndices[0] = i;
 
        // arr[i] wants to extend largest subsequence
        else if (arr[i] > arr[tailIndices[len - 1]]) {           
            prevIndices[i] = tailIndices[len - 1];
            tailIndices[len++] = i;
        }
          
        // arr[i] wants to be a potential candidate of
        // future subsequence
        // It will replace ceil value in tailIndices
        else {
            int pos = ceilBinarySearch(arr, tailIndices, -1,
                                        len - 1, arr[i]);
            prevIndices[i] = tailIndices[pos - 1];
            tailIndices[pos] = i;
        }
    }
 
    // put LIS into vector
    for (int i = tailIndices[len - 1]; i >= 0; i = prevIndices[i])
        res.push_back(arr[i]);
}
 
// function for finding longest bitonic seq
void longestBitonic(vector<int> arr1, int n1, vector<int>arr2, int n2) {
    // find LIS of array 1 in reverse form
    longestIncreaseSubArray(arr1, n1);
 
    // reverse res to get LIS of first array
    reverse(res.begin(), res.end());
 
    // reverse array2 and find its LIS
    reverse(arr2.begin(), arr2.end());
    longestIncreaseSubArray(arr2, n2);
 
    // print result
    cout << res.size() + 1 << endl;
}
 
// driver preogram
int main()
{
    vector<int>arr1 = { 13, 4, 9, 8, 12, 6, 14, 5 };
    vector<int>arr2 = { 1 };
    //int arr1[] = { 1, 2, 4, 3, 2 };
    //int arr2[] = { 8, 6, 4, 7, 8, 9 };
    int n1 = arr1.size();
    int n2 = arr2.size();
    longestBitonic(arr1, n1, arr2, n2);
    return 0;
}