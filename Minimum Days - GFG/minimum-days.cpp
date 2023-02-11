//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int getMinimumDays(int n,string S, vector<int> &p) {
        unordered_map<int,int> mp;
        for(int i =0;i<n;i++){
            mp[p[i]] = i+1;
        }
        int ans = INT_MIN;
        
        for(int i =0 ;i<n-1;i++){
            int day =0 ;
            if(S[i] == S[i+1]){
                
                int curr = mp[i];
                int next = mp[i+1];
                if(curr > next){
                    day  = next; 
                    i++;
                }else{
                    day = curr;
                }
                
            }
             ans = max(ans,day);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        string S;cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N,S, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends