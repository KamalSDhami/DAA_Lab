// . Given a sorted array of positive integers, design an algorithm and implement it using a program to find three indices i, j, k such that arr[i] + arr[j] = arr[k].

#include<iostream>
#include<vector>

using namespace std;

bool find_triplet(vector<int> arr){
    for(int i = arr.size() - 1; i >= 0; i--){
        int low = 0, high = i - 1;
        while(low < high){
            if(arr[low] + arr[high] == arr[i]){
                cout << low + 1 << ", " << high + 1 << ", " << i + 1 << endl;
                return true;
            } else if(arr[low] + arr[high] < arr[i]){
                low++;
            } else {
                high--;
            }
        }
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
        if(!find_triplet(arr)){
            cout << "No sequence found" << endl;
        }
    }

    return 0;
}