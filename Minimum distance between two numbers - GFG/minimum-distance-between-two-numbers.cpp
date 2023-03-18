//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        int cx = -1;
        int cy = -1;
        int mini = INT_MAX;
        
        for(int i =0;i<n;i++){
            if(a[i] == x){
                cx = i;
                if(cy != -1) mini = min(mini,abs(cy-cx));
            }
            if(a[i] == y){
                cy = i;
                if(cx != -1) mini = min(mini,abs(cy-cx));
            }
        }
        
        if(cx == -1 || cy == -1) return -1;
        
        return mini;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends