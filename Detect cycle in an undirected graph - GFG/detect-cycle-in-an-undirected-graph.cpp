//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detect(int  src,int parent , vector<int> adj[] , int vist[] ){
        vist[src] = 1;
        for(auto it: adj[src]){
            if(!vist[it]){
                if(detect(it,src,adj,vist) == true) return true;
            }
            else if(parent != it) return true;
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        int vist[V] = {0};
        
        for(int i =0 ;i<V;i++){
            if(!vist[i]){
                if(detect(i,-1,adj , vist) == true){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends