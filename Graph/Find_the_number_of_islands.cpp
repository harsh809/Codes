// gfg Find the number of islands

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isSafe(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        if((row>=0 && row<n)&& (col>=0 && col<m) && grid[row][col]!='0' && vis[row][col]!=1){
            return true;
        }
        return false;
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        vector<vector<int>> vis(grid.size(),vector<int> (grid[0].size(),0));
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[0].size();col++){
                if(grid[row][col]=='0' || vis[row][col]==1){
                    continue;
                }
                queue<pair<int,int>> q;
                q.push({row,col});
                vis[row][col] = 1;
                while(!q.empty()){
                    pair<int,int> front = q.front();
                    q.pop();
                    for(int i=-1;i<=1;i++){
                        for(int j=-1;j<=1;j++){
                            int u = front.first + i;
                            int v = front.second + j;
                            if(isSafe(u,v,grid,vis)){
                                q.push({u,v});
                                vis[u][v] = 1;
                            }
                        }
                    }
                 }
                 ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends