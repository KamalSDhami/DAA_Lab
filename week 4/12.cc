// Given an unsorted array of integers, design an algorithm and implement it using a program to sort an array of elements by dividing the array into two subarrays and combining these subarrays after sorting each one of them. Your program should also find number of comparisons and inversions during sorting the array

#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &arr, int low, int mid, int high, int &comparisons, int &inversions){
    int n1 = mid - low + 1;
    int n2 = high - mid;
    vector<int> left(n1), right(n2);
    for(int i = 0; i < n1; i++){
        left[i] = arr[low + i];
    }
    for(int i = 0; i < n2; i++){
        right[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = low;
    while(i < n1 && j < n2){
        comparisons++;
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
            inversions += (n1 - i);
        }
        k++;
    }
    while(i < n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int> &arr, int low, int high, int &comparisons, int &inversions){
    if(low < high){
        int mid = low + (high - low) / 2;
        merge_sort(arr, low, mid, comparisons, inversions);
        merge_sort(arr, mid + 1, high, comparisons, inversions);
        merge(arr, low, mid, high, comparisons, inversions);
    }
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
        int comparisons = 0, inversions = 0;
        merge_sort(arr, 0, n - 1, comparisons, inversions);
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "Comparisons: " << comparisons << endl;
        cout << "Inversions: " << inversions << endl;
    }

    return 0;
}
