// Given an unsorted array of integers, design an algorithm and a program to sort the array using insertion sort. Your program should be able to find number of comparisons and shifts ( shifts  total number of times the array elements are shifted from their place) required for sorting the array.
// Input Format
#include<iostream>
#include<vector>
using namespace std;

void insertion_sort(vector<int> &arr){
    int comparisons = 0, shifts = 0;
    for(int i = 1; i < arr.size(); i++){
        int key = arr[i], j = i - 1;
        while(j >= 0 && arr[j] > key){
            comparisons++;
            shifts++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        shifts++;
    }
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Shifts: " << shifts << endl;
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
        insertion_sort(arr);
    }

    return 0;
}