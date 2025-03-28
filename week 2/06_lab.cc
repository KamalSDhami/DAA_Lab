#include <bits/stdc++.h> 
using namespace std; 
int countPairsWithDifference(vector<int>& vec, int key) { 
    sort(vec.begin(), vec.end()); 
    int count = 0, i = 0, j = 1; 
    while (j < vec.size()) { 
        int diff = vec[j] - vec[i]; 
        if (diff == key) { 
            count++; 
            i++; 
            j++; 
        }else if (diff < key) j++; 
        else i++; 
        if (i == j) j++; 
    } 
    return count; 
} 
int main() { 
int T; 
cin >> T; 
while (T--) { 
int n, key; 
cin >> n; 
vector<int> vec(n); 
for (int i = 0; i < n; i++) cin >> vec[i]; 
cin >> key; 
cout << countPairsWithDifference(vec, key) << endl; 
} 
return 0; 
}