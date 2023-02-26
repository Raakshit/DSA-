//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int src,vector<int> &vist , vector<int> &v ,vector<vector<int>>& adj ){
        vist[src] = 1;
        v.push_back(src);
        for(auto it: adj[src]){
            if(!vist[it]){
                dfs(it,vist,v,adj);
            }
        }
    }
  
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        vector<vector<int>> arr;
        vector<int> vist(V+1,0);
        
        for(int i =1;i<=V;i++){
            if(!vist[i]){
                vector<int> v;
                dfs(i,vist,v,adj);
                arr.push_back(v);
            }
        }
        int ans =0 ;
        
        for(auto it: arr){
            int n = it.size();
            int count = 0;
            for(auto j :it){
                if(adj[j].size()  == (n-1)) count++;
            }
            if(count == n)ans++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends