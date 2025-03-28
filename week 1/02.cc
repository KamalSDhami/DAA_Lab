// Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether given key element is present in the array or not. Also, find total number of comparisons for each input case. (Time Complexity = O(nlogn), where n is the size of input), without stl

#include<iostream>
#include<vector>


using namespace std;

void search(vector<int> arr, int key){
    int comparisions = 0;
    int low = 0, high = arr.size() - 1;
    while(low <= high){
        comparisions++;
        int mid = low + (high - low) / 2;
        if(arr[mid] == key){
            cout << "Present " << comparisions << endl;
            return;
        } else if(arr[mid] < key){
            low = mid + 1;
        } else {
            high = mid - 1;
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
