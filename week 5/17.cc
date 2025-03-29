// You have been given two sorted integer arrays of size m and n. Design an algorithm and implement it using a program to find list of elements which are common to both. (Time Complexity = O(m+n))


#include<iostream>
#include<vector>
#include<set>

using namespace std;

void common_elements(vector<int> arr1, vector<int> arr2){
    set<int> s;
    vector<int> common;
    for (int i = 0; i < arr1.size(); i++){
        s.insert(arr1[i]);
    }
    for (int i = 0; i < arr2.size(); i++){
        if (s.find(arr2[i]) != s.end()){
            common.push_back(arr2[i]);
        }
    }
    cout << "Common elements: ";
    for (int i = 0; i < common.size(); i++){
        cout << common[i] << " ";
    }
}

int main(){
    int test_case;
    cout << "Enter the number of test cases: ";
    cin >> test_case;
    for (int i = 0; i < test_case; i++){
        int m, n;
        cout << "Enter the size of first array: ";
        cin >> m;
        vector<int> arr1(m);
        cout << "Enter the elements of first array: ";
        for (int j = 0; j < m; j++){
            cin >> arr1[j];
        }
        cout << "Enter the size of second array: ";
        cin >> n;
        vector<int> arr2(n);
        cout << "Enter the elements of second array: ";
        for (int j = 0; j < n; j++){
            cin >> arr2[j];
        }
        common_elements(arr1, arr2);
    }

    return 0;
}