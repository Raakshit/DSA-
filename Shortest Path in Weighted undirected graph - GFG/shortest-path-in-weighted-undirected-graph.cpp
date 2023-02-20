//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<int> dist(n+1, 1e9);
        int prev_node[n+1];
        for(int i =0;i<=n;i++){
            prev_node[i] = i;
        }
        
        dist[1] = 0;
        
        pq.push({0,1});
        
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int distance = it.first;
            pq.pop();
            
            
            for(auto it : adj[node]){
                int newNode = it.first;
                int weight = it.second;
                if(dist[newNode] > weight + distance){
                    dist[newNode] = weight+distance;
                    prev_node[newNode] = node;
                    pq.push({dist[newNode],newNode});
                }
            }
        }
        
      if(dist[n] == 1e9) return {-1};
        
        vector<int> path;
        int node = n;
        
        while(prev_node[node] != node){
            path.push_back(node);
            node = prev_node[node];
        }
        
        path.push_back(1);
        
        reverse(path.begin() , path.end());
        
        return path;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends