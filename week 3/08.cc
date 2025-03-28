// Given an unsorted array of integers, design an algorithm and implement a program to sort this array using selection sort. Your program should also find number of comparisons and number of swaps required.

#include<iostream>
#include<vector>

using namespace std;

void selection_sort(vector<int> &arr){
    int comparisons = 0, swaps = 0;
    for(int i = 0; i < arr.size() - 1; i++){
        int min_index = i;
        for(int j = i + 1; j < arr.size(); j++){
            comparisons++;
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        swaps++;
        swap(arr[i], arr[min_index]);

    }
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
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
        selection_sort(arr);
    }

    return 0;
}