// Given a sorted array of positive integers containing few duplicate elements, design an algorithm and implement it using a program to find whether the given key element is present in the array or not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))

#include<iostream>
#include<vector>

using namespace std;

int first_occurence(vector<int> arr, int key){
    int low = 0, high = arr.size() - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == key && (mid == 0 || arr[mid - 1] != key)){
            return mid;
        } else if(arr[mid] < key){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int last_occurence(vector<int> arr, int key){
    int low = 0, high = arr.size() - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == key && (mid == arr.size() - 1 || arr[mid + 1] != key)){
            return mid;
        } else if(arr[mid] <= key){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}


int search(vector<int> arr, int key){
    int first = first_occurence(arr, key);
    if(first == -1){
        return 0;
    }
    int last = last_occurence(arr, key);
    return last - first + 1;
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
        int count = search(arr, key);
        if(count == 0){
            cout << "Not Present" << endl;
        } else {
            cout << key << " - " << count << endl;
        }
    }

    return 0;
}