#include <stdio.h> 
#include <stdlib.h> 
 
void findMaxOccurrence(int n, char arr[]){ 
    int freq[26] = {0};     
    char maxChar = '\0'; 
    int maxFreq = 0; 
     
    for (int i = 0; i < n; i++){ 
        char ch = tolower(arr[i]); 
        freq[ch - 'a']++; 
 
        if (freq[ch - 'a'] > maxFreq){ 
            maxFreq = freq[ch - 'a']; 
            maxChar = ch; 
        } 
    } 
     
    if (maxFreq == 1){ 
        printf("No Duplicates Present\n"); 
    } 
    else{ 
        printf("%c - %d\n", maxChar, maxFreq); 
    } 
} 
 
int main() { 
    int T; 
    printf("Enter the no. of test cases: "); 
    scanf("%d", &T); 
    for(int j=0; j<T; j++){ 
        int n; 
        printf("Enter the size: "); 
        scanf("%d", &n); 
        char arr[n]; 
        printf("Enter the elements: "); 
        for (int i = 0; i < n; i++) { 
            scanf(" %c", &arr[i]); 
        } 
         
        findMaxOccurrence(n, arr); 
        
    } 
    return 0; 
} 