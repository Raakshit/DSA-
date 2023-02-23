//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int mod= 1e9+7;
  
    int solve(int row ,int col, vector<vector<int>> &grid,vector<vector<int>> &dp){
        int n = grid.size();
        int m = grid[0].size();
        if(row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 0 ) return 0;
        
        
        if(row == 0 && col == 0) return 1;
        if(dp[row][col] != -1) return dp[row][col];
        
        int up = solve(row-1,col , grid,dp)%mod;
        int right = solve(row , col-1, grid,dp)%mod;
        
        return dp[row][col] =  (up+right)%mod;
    }
  
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1,grid,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends