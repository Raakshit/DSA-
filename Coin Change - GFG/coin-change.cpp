//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define lli long long int
class Solution {
  public:
    long long int solve(int ind , int tar  , int coins[],vector<vector<lli>> &dp){
        if(ind == 0  ){
            return (tar%coins[0] == 0);
           
        }
        if(dp[ind][tar] != -1) return dp[ind][tar];
        lli not_take = solve(ind-1 , tar , coins,dp);
        lli take  = 0;
        if(tar >= coins[ind]) take = solve(ind , tar-coins[ind] , coins,dp);
        
        return dp[ind][tar] =  (take+not_take);
    }
    long long int count(int coins[], int n, int sum) {
        vector<vector<lli>> dp(n , vector<lli> (sum+1 , 0));
        for(int t =0 ;t <= sum ;t++){
            dp[0][t] = (t%coins[0] == 0);
        }
        
        for(int ind =1;ind<n;ind++){
            for(int t = 0;t<=sum;t++){
                lli not_take = dp[ind-1][t];
                lli take  = 0;
                if(t >= coins[ind]) take = dp[ind][t - coins[ind]];
            
                dp[ind][t] =  (take+not_take);
            }
        }
        
        
        return dp[n-1][sum];
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