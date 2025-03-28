#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void search(vector<int> arr, int key){
    auto result = find(arr.begin(), arr.end(), key);
    if (result != arr.end()){
        cout << "Present " << result - arr.begin() + 1 << endl;
    } else {
        cout << "Not Present " << arr.size() << endl;
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
        int key;
        cout << "Enter the key element: ";
        cin >> key;
        search(arr, key);
    }

    return 0;
}