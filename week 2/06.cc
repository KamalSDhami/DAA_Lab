// Given an array of nonnegative integers, design an algorithm and a program to count the number of pairs of integers such that their difference is equal to a given key, K.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int count_pairs(vector<int> arr, int key){
    int count = 0;
    for(int i = 0; i < arr.size(); i++){
        for(int j = i + 1; j < arr.size(); j++){
            if(abs(arr[i] - arr[j]) == key){
                count++;
            }
        }
    }
    return count;
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
        cout << count_pairs(arr, key) << endl;
    }

    return 0;
}
