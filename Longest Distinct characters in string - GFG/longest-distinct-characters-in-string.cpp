//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    int n = s.size();
    int j =0 ;
    int ans = 1;
    unordered_set<char> st;
    st.insert(s[0]);    
    
    for(int i =1 ;i<n;i++){
        while(st.find(s[i]) != st.end() && !st.empty()){
            st.erase(s[j]);
            j++;
        }
        
        st.insert(s[i]);
        int size_st = st.size();
        ans = max(ans ,size_st);
    }
    
    return ans;
}