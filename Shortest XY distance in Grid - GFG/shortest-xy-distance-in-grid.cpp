//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        queue<pair<int,int>> q;
        
        vector<vector<bool>> vist(N,vector<bool> (M,false));
        
        for(int i =0;i<N;i++){
            for(int j =0;j<M;j++){
                if(grid[i][j] == 'Y'){
                    q.push({i,j});
                    vist[i][j] = true;
                } 
            }
        }
        
        int steps= 0 ;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int row = q.front().first;
                int col = q.front().second;
                if(grid[row][col] == 'X') return steps;
                q.pop();
                for(int i =0;i<4;i++){
                int nr = dr[i]+row;
                int nc = dc[i]+col;
                if(nr>=0  && nc >=0 && nr<N && nc<M && !vist[nr][nc]){
                    q.push({nr,nc});
                    vist[nr][nc] = true;
                }
            }
            }
            steps++;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends