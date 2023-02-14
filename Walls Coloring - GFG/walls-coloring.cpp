//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int solve(int row, int prev ,vector<vector<int>> &colors ,vector<vector<int>> &dp){
        // base case 
        if(row == 0){
            int mini = INT_MAX;
            for(int i =0;i<3;i++){
                if(i != prev){
                    mini = min(mini , colors[row][i]);
                }
            }
            
            return dp[row][prev] =  mini;
        }
        
        if(dp[row][prev] != -1) return dp[row][prev];
        
        // normal conditons
        int mini = INT_MAX;
        for(int i =0 ;i<3;i++){
            if(i != prev){
                int cost = colors[row][i] + solve(row-1,i,colors,dp);
                mini = min(mini , cost);
            }
        }
        return dp[row][prev] = mini;
    }

    int minCost(vector<vector<int>> &colors, int n) {
        vector<vector<int>> dp(n,vector<int> (4,-1));
        return solve(n-1,3,colors,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends