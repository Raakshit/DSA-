//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
    // 1.Whats is MIN frequency --> map store --> travel keya 
    // 2.greatest element in that MIN frequnecy
    unordered_map<int,int> mp;
    int freq = INT_MAX;
    for(int i =0;i<n;i++){
        mp[arr[i]]++;
    }
    int ans = INT_MIN;
    for(auto it: mp){
        freq = min(freq , it.second);
    }
    
    for(auto it: mp){
        if(freq == it.second){
            ans = max(ans , it.first);
        }
    }
    
    return ans;
    
    
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends