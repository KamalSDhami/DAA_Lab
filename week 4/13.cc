//Given an unsorted array of integers, design an algorithm and implement it using a program to sort an array of elements by partitioning the array into two subarrays based on a pivot element such that one of the sub array holds values smaller than the pivot element while another sub array holds values greater than the pivot element. Pivot element should be selected randomly from the array. Your program should also find number of comparisons and swaps required for sorting the array.

#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

int partition(vector<int> &arr, int low, int high, int &comparisons, int &swaps){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        comparisons++;
        if(arr[j] < pivot){
            i++;
            swaps++;
            swap(arr[i], arr[j]);
        }
    }
    swaps++;
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort(vector<int> &arr, int low, int high, int &comparisons, int &swaps){
    if(low < high){
        int pi = partition(arr, low, high, comparisons, swaps);
        quick_sort(arr, low, pi - 1, comparisons, swaps);
        quick_sort(arr, pi + 1, high, comparisons, swaps);
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
        int comparisons = 0, swaps = 0;
        quick_sort(arr, 0, n - 1, comparisons, swaps);
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "Comparisons: " << comparisons << endl;
        cout << "Swaps: " << swaps << endl;
    }

    return 0;
}
