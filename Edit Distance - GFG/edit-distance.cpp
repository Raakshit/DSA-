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
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i =0 ;i<=n;i++){
            dp[i][0] =i;
        }
        for(int j =0;j<=m;j++){
            dp[0][j] =j;
        }
        
        for(int i =1;i<=n;i++){
            for(int j =1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else {
                    dp[i][j] = 1 + min(dp[i-1][j] , min(dp[i-1][j-1] , dp[i][j-1]));
                }
            }
        }
        
        return dp[n][m];
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