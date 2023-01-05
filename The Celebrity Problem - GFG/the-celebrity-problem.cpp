//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int ind =-1  ,count = 0;
        if(n == 1) return -1;
        for(int i =0 ;i < n;i++){
            int sum  = 0;
            for(int j =0 ;j<n;j++){
                sum += M[i][j];
            }
            if(sum == 0 ) {
                ind  = i;
                count ++;
            }
        }
        
        if(count > 1) return -1;
        return ind;
        
        // return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends