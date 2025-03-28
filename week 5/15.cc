// Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and implement it using a program to find which alphabet has maximum number of occurrences and print it. (Time Complexity = O(n)) (Hint: Use counting sort)

#include<iostream>
#include<vector>


using namespace std;

void max_occurrences(vector<char> arr){
    vector<int> count(26, 0);
    for(int i = 0; i < arr.size(); i++){
        count[arr[i] - 'a']++;
    }
    int max_index = 0;
    for(int i = 1; i < 26; i++){
        if(count[i] > count[max_index]){
            max_index = i;
        }
    }
    if (count[max_index] == 1){
        cout << "No duplicates found" << endl;
    } else {
        cout <<  char('a' + max_index )<<+ " - "<< count[max_index] <<endl;
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
        vector<char> arr(n);
        cout << "Enter the elements of array: ";
        for (int j = 0; j < n; j++){
            cin >> arr[j];
        }
         max_occurrences(arr) ;
    }

    return 0;
}
