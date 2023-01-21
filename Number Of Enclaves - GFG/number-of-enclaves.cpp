//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
  void dfs(int row , int col ,vector<vector<int>> &grid){
      int n = grid.size();
      int m = grid[0].size();
      
      grid[row][col] = 0;
      
      int drow[] = {-1,0,1,0};
      int dcol[] = {0,1,0,-1};
      
      for(int i =0;i<4;i++){
          int nrow = row+drow[i];
          int ncol = col + dcol[i];
          
          if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1){
              dfs(nrow,ncol,grid);
          }
      }
  }
  
  
  public:
  
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n =grid.size();
        int m = grid[0].size();
        
        for(int i =0 ;i<n;i++){
            int j = 0;
            if(grid[i][j] == 1) dfs(i,j,grid);
            
            j = m-1;
            if(grid[i][j] == 1) dfs(i,j,grid);
        }
        
        for(int j =0;j<m;j++){
            int i =0 ;
            if(grid[i][j] == 1) dfs(i,j,grid);
            
           i = n-1;
            if(grid[i][j] == 1)dfs(i,j,grid);
        }
        
        int count = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 1) count++;
            }
        }
        
        return count;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends