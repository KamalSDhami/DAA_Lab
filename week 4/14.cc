// Given an unsorted array of integers, design an algorithm and implement it using a program to find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int kth_smallest(vector<int> arr, int k){
    sort(arr.begin(), arr.end());
    return arr[k - 1];
}

int main(){
    int test_case;
    cout<<"Enter the number of test cases: ";
    cin >> test_case;
    for (int i = 0; i < test_case; i++){
        int n;
        cout << "Enter the size of array: ";
        cin >> n;
        vector<int> arr(n);
        cout << "Enter the elements of array: ";
        for (int j = 0; j < n; j++){
            cin >> arr[j];
        }
        int k;
        cout << "Enter the value of k: ";
        cin >> k;
        cout << kth_smallest(arr, k) << endl;
    }

    return 0;
}