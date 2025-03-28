// Given an unsorted array of positive integers, design an algorithm and implement it using a program to find whether there are any duplicate elements in the array or not. (use sorting) (Time Complexity = O(n log n))

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

bool hasDuplicate(vector<int> arr) { 
    unordered_set<int> s; 
    for (int i = 0; i < arr.size(); i++) { 
        if (s.find(arr[i]) != s.end()) 
            return true; 
        s.insert(arr[i]); 
    } 
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
        if(hasDuplicate(arr)){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
