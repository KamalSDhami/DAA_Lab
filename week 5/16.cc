// . Given an unsorted array of integers, design an algorithm and implement it using a program to  find whether two elements exist such that their sum is equal to the given key element. (Time  Complexity = O(n log n)) 

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool find_sum(vector<int> arr, int key){
    sort(arr.begin(), arr.end());
    int low = 0, high = arr.size() - 1;
    while(low < high){
        if(arr[low] + arr[high] == key){
            cout << "Yes" << endl;
            return true;
        } else if(arr[low] + arr[high] < key){
            low++;
        } else {
            high--;
        }
    }
    cout << "No" << endl;
    return false;
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
        int key;
        cout << "Enter the key element: ";
        cin >> key;
        find_sum(arr, key);
    }

    return 0;
}