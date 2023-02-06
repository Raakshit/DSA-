//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	int mod = 1e9+7;
	
	ll solve(int ind , vector<ll> &dp ){
        // base case
        if(ind < 0 ) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        ll not_take = solve(ind-1,dp)%mod;
        ll take = 1+solve(ind-2,dp)%mod;
        
        return  dp[ind] =  (take + not_take)%mod;
        
	}
	
	ll countStrings(int n) {
	    vector<ll> dp(n,-1);
	     return solve(n-1,dp)+1;    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends