//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(int row ,int col, vector<vector<int>> &Matrix,int n,vector<vector<int>> &dp ){
        if(col > n-1 || col < 0 ) return -1e8;
        if(row == 0) return Matrix[row][col];
        if(dp[row][col] != -1) return dp[row][col];
        
        return dp[row][col] = Matrix[row][col] + max(solve(row-1,col,Matrix,n,dp) , 
        max(solve(row-1,col-1,Matrix,n,dp) ,solve(row-1,col+1,Matrix,n,dp)));
        
        
    }
    int maximumPath(int n, vector<vector<int>> Matrix)
    {
        int maxi = INT_MIN;
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            maxi = max(maxi , solve(n-1,i,Matrix,n,dp));
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends