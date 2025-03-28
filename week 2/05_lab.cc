#include<iostream>
#include<vector>
using namespace std;

void findIndices(vector<int> &arr) { 
    int n = arr.size(); 
    bool found = false; 
    for (int k = 2; k < n; k++) { 
        int i = 0, j = k - 1; 
        while (i < j) { 
            int sum = arr[i] + arr[j]; 
            if (sum == arr[k]) { 
                cout << "Indices: " << i << ", " << j << ", " << k << endl; 
                found = true; 
                return; 
            } else if (sum < arr[k]) { 
                i++; 
            } else { 
                j--; 
            } 
        } 
    } 
    if (!found) { 
        cout << "No valid indices found" << endl; 
    } 
} 
 
int main() { 
    int T; 
    cin >> T; 
    while (T--) { 
int n; 
cin >> n; 
vector<int> arr(n); 
for (int i = 0; i < n; i++) { 
cin >> arr[i]; 
} 
findIndices(arr); 
} 
return 0; 
}