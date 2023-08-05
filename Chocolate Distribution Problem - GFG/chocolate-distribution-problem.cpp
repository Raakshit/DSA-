//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin() , a.end());
        ll maxi = INT_MIN;
        ll mini = INT_MAX;
        ll ans = INT_MAX;
        
        for(int i=0;i<m;i++){
            maxi = max(maxi,a[i]);
            mini = min(mini,a[i]);
        }
        
        ans = min(ans,maxi-mini);
        ll j = m , i = 0;
        
        while(j<n){
           maxi = a[j++];
           mini = a[++i];
           ans = min(ans,maxi-mini);
        }
        return ans;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends