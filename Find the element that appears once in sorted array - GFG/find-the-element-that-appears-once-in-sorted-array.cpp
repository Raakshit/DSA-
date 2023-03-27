//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        int low = 0;
        int high = n-1;
        
        while(low <= high){
            int mid =low+(high-low)/2;
            if(mid%2 == 0){
                if(arr[mid] == arr[mid+1]){
                    low = mid+1;
                }else if(arr[mid-1] == arr[mid]){
                    high = mid-1;
                }else{
                    return arr[mid];
                }
            }else{
                if(arr[mid] == arr[mid-1]) low=  mid+1;
                else if(arr[mid+1] == arr[mid]) high = mid-1;
                else return arr[mid];
            }
        }
        
        return -1;
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
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends