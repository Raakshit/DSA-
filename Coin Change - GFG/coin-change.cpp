//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define lli long long int
class Solution {
  public:
  
    lli solve(int ind, int coins[] , int sum,vector<vector<lli>> &dp){
        if(sum == 0) return 1;
        if(ind == 0){
            return (sum%coins[ind] == 0);
        }
        
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        lli not_take = solve(ind-1,coins,sum,dp);
        lli take =0;
        if(sum >= coins[ind]){
            take =solve(ind,coins,sum-coins[ind],dp);
        }
        
        return dp[ind][sum] = take+not_take;
    }
  
    long long int count(int coins[], int N, int sum) {
        vector<vector<lli>> dp(N+1,vector<lli>(sum+1,-1));
        return solve(N-1,coins,sum,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends