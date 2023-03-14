//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    
        int solve(int i, int j , vector<int> &arr, vector<vector<int>> &dp){
            if( i > j) return 0;
        
        int maxi = INT_MIN;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        for(int ind = i;ind<=j;ind++){
            int cost = arr[ind]*arr[i-1]*arr[j+1] + solve(i,ind-1,arr,dp) + solve(ind+1,j,arr,dp);
            maxi = max(maxi , cost);
        }
        
        return dp[i][j] =  maxi;
        }
    
        int maxCoins(int n, vector <int> &arr)
        {
            arr.push_back(1);
            arr.insert(arr.begin() , 1);
            vector<vector<int>> dp(n+1 , vector<int> (n+1,-1));
            return solve(1,n,arr,dp);
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends