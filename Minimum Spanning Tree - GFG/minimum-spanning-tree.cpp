//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int> rank , parent , size;
public: 
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i =0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findUparent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUparent(parent[node]);
    }
    
    void unionByrank(int u , int v){
        int p_u = parent[u];
        int p_v = parent[v];
        
        if(p_u == p_v) return;
        if(size[p_u] < size[p_v]){
            parent[p_u] = p_v;
            size[p_v] += size[p_u];
        }else{
            parent[p_v] = p_u;
            size[p_u] += size[p_v];
        }
    }
    
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                int wt = it[1];
                int node = i ;
                int adjnode = it[0];
                
                edges.push_back({wt , {node , adjnode}});
            }
        }
        
        DisjointSet ds(V);
        sort(edges.begin() , edges.end());
        
        int ans = 0;
        for(auto it: edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUparent(u) != ds.findUparent(v)){
                ans += wt;
                ds.unionByrank(u,v);
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends