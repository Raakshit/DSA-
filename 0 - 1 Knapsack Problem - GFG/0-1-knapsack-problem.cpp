//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int ind , int w , int wt[] , int val[] ,vector<vector<int>> &dp){
        //  base cases
        if(ind ==0 ){
            if(wt[0] <= w) return val[0];
            else return 0;
        }
        if(dp[ind][w] != -1) return dp[ind][w];
        int not_take = solve(ind-1 , w , wt ,val,dp);
        int take = INT_MIN;
        if(w>= wt[ind]) take = val[ind] + solve(ind -1 , w-wt[ind] , wt , val,dp);
        
        return dp[ind][w] = max(take,not_take);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<int> prev(W+1, 0);
        // base case for tabulation Process
        for(int w = wt[0] ; w <= W;w++) prev[w] = val[0];
        
        for(int ind =1 ;ind< n;ind++){
            vector<int> curr(W+1);
            for(int w = 0;w <=W;w++){
                int not_take = prev[w];
                int take = INT_MIN;
                if(w >= wt[ind]) take = val[ind] + prev[w-wt[ind]];
                curr[w] = max(not_take  ,take);
            }
            prev = curr;
        }
       return prev[W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends