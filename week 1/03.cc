// Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether a given key element is present in the sorted array or not. For an array arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k] and so on. Once the interval (arr[2k] <key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k to find the element key. (Complexity < O(n), where n is the number of elements need to be scanned for searching): Jump Search

#include<iostream>
#include<vector>

using namespace std;

void search(vector<int> arr, int key){
    int comparisions = 0;
    int n = arr.size();
    int jump = 2;
    int low = 0, high = jump;
    while(high < n){
        comparisions++;
        if(arr[high] >= key){
            break;
        }
        low = high;
        high += jump;
    }
    if(high >= n){
        high = n - 1;
    }
    for(int i = low; i <= high; i++){
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