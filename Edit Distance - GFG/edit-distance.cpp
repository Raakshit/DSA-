//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int solve(int ind1 , int ind2 , string &s, string &t,vector<vector<int>> &dp){
      if(ind2 < 0) return(ind1+1);
      if(ind1< 0) return (ind2+1);
      
      if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
      
      if(s[ind1] == t[ind2]){
          return dp[ind1][ind2] =  solve(ind1-1,ind2-1,s,t,dp);
      }else{
          int insert =0, remove_char = 0, replace =0  ;
          insert = solve(ind1 , ind2-1,s,t,dp);
          remove_char =solve(ind1-1,ind2,s,t,dp);
          replace = solve(ind1-1,ind2-1,s,t,dp);
          
          return dp[ind1][ind2] =  1 + min(insert,min(remove_char,replace));
      }
  }
    int editDistance(string s, string t) {
        int n  =  s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1,s,t,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends