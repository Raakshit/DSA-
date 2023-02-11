//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i , int j ,vector<vector<int>> &dp ,int arr[]  ){
        if(i == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int k =i;k<=j-1;k++){
            int steps = arr[i-1]*arr[k]*arr[j] + solve(i,k,dp,arr) + solve(k+1,j,dp,arr);
            mini = min(steps, mini);
        }
        
        return dp[i][j] = mini;
    }
    
    int matrixMultiplication(int n, int arr[])
    {
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i = n-1;i>=1;i--){
            for(int j = i+1 ; j<=n-1;j++){
                int mini = INT_MAX;
                for(int k = i; k<= j-1; k++){
                
                int ans = dp[i][k]+ dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                
                mini = min(mini,ans);
                
            }
            dp[i][j] = mini;
            }
        }
        
        
        return dp[1][n-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends