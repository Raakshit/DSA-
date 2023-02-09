//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str){
    int n = str.size();
    
    string a = str;
    string b = str;
    
    reverse(b.begin() , b.end());
    
    vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    
    for(int i =1 ;i<=n;i++){
        for(int j =1;j<=n;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    
    int lcs = dp[n][n];
    
    return n-lcs;
    
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends