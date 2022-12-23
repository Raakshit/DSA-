//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int total_sum =0 ;
	    
	    for(int i =0 ;i< n;i++) total_sum += arr[i];
	    int k = total_sum;
	    
	    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
	    for(int i =0;i<n;i++) dp[i][0] = true;
	    
	    if(arr[0] <= k) dp[0][arr[0]] = true;
	    
	    for(int i= 1;i<n;i++){
	        for(int sum = 1;sum<k;sum++){
	            bool not_take = dp[i-1][sum];
	            bool take = false;
	            if(sum >= arr[i]) take = dp[i-1][sum-arr[i]];
	            dp[i][sum] = take||not_take;
	        }
	    }
	    
	    int mini = 1e9;
	    for(int s1 = 0;s1<=k/2;s1++){
	        if(dp[n-1][s1] == true){
	            mini = min(mini , abs((k-s1) - s1));
	        }
	    }
	    
	    return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends