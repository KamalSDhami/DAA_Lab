#include <bits/stdc++.h> 

using namespace std; 
int lowerBound(vector<int> arr, int n, int x) { 
    int low = 0, high = n - 1, ans = n, mid; 
    while (low <= high) { 
        mid = (low + high) / 2; 
        if (arr[mid] >= x) { 
            ans = mid; 
            high = mid - 1; 
        }else { 
            low = mid + 1; 
        } 
    } 
    return ans; 
} 
int upperBound(vector<int> &arr, int n, int x) { 
    int low = 0, high = n - 1, ans = n, mid; 
    while (low <= high) { 
        mid = (low + high) / 2; 
        if (arr[mid] > x) { 
            ans = mid; 
            high = mid - 1; 
        } else { 
            low = mid + 1; 
        } 
    } 
    return ans; 
}
int searchRange(vector<int> &nums, int target) { 
    int n = nums.size(), lb = lowerBound(nums, n, target), ub = upperBound(nums, n, target); 
    if (lb == n || nums[lb] != target) return 0; 
        return (ub - lb); 
} 
int main() { 
    int T; 
    cin >> T; 
    while (T--) { 
        int n, key; 
        cin >> n; 
        vector<int> vec(n); 
        for (int i = 0; i < n; i++) { 
            cin >> vec[i]; 
        } 
        cin >> key; 
        int occurrences = searchRange(vec, key); 
        if (occurrences > 0) { 
            cout << key << "-" << occurrences << endl; 
        } else { 
             cout << "Key not present" << endl; 
        } 
    } 
    return 0; 
    } 