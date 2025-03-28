#include<iostream>
#include<vector>

using namespace std;
// Given an array of nonnegative integers, design a linear algorithm and implement it using a program to find whether given key element is present in the array or not. Also, find total number of comparisons for each input case. (Time Complexity = O(n), where n is the size of input).

void search(vector<int> arr, int key){
    int comparisions = 0;
    for(int i = 0; i < arr.size(); i++){
        comparisions++;
        if(arr[i] == key){
            cout << "Present " << comparisions << endl;
            return;
        }
    }
    cout << "Not Present " << comparisions << endl;
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
        search(arr, key);
    }

    return 0;
}