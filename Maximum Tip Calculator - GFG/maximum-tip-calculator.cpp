//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  long long solve(int ind , int a[] ,int b[] ,int n ,int x ,int y){
      if(ind < 0) return 0;
      if(x!= 0 && y!= 0){
          return max(
              a[ind]+solve(ind-1,a,b,n,x-1,y),
              b[ind]+solve(ind-1,a,b,n,x,y-1)
              );
      }
      
      if(x!=0){
          return a[ind]+solve(ind-1,a,b,n,x-1,y);
      }
      
      else{
          return b[ind] + solve(ind-1,a,b,n,x,y-1);
      }
      
      
  }
  
    long long maxTip(int a[], int b[], int n, int x, int y) {
        vector<pair<long long ,long long>> arr;
        for(int i =0 ;i<n;i++){
            arr.push_back({abs(a[i]-b[i]) , i});
        }
        sort(arr.begin() , arr.end());
        reverse(arr.begin() , arr.end());
        long long ans =0;
        for(int i =0 ;i<n;i++){
            if(a[arr[i].second] > b[arr[i].second]){
                if(x!=0){
                    ans += a[arr[i].second];
                    x--;
                }else{
                    ans += b[arr[i].second];
                    y--;
                }
            }else{
                if(y!=0){
                    ans += b[arr[i].second];
                    y--;
                }else{
                    ans += a[arr[i].second];
                    x--;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        Solution obj;
        auto ans = obj.maxTip(a, b, n, x, y);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends