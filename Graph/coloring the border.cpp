//leetcode coloring the border

class Solution {
public:
    void dfs(int row,int col,int& old_clr,int& color,vector<vector<int>>& grid,vector<vector<int>>& ans,vector<vector<int>>& vis){
        vis[row][col] = 1;
        int count = 0;
        int delta_row[4] = {1,0,-1,0};
        int delta_col[4] = {0,1,0,-1};
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<4;i++){
            int adjr = row + delta_row[i];
            int adjc = col + delta_col[i];
            if((adjr>=0 && adjr<n) && (adjc>=0 && adjc<m) && grid[adjr][adjc]==old_clr){
                count++;
                if(vis[adjr][adjc]==0){
                    dfs(adjr,adjc,old_clr,color,grid,ans,vis);
                }
            }   
        }
        if(count<4){
                ans[row][col] = color;
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans = grid;
        vector<vector<int>> vis(n,vector<int> (m,0));
        int old_clr = grid[row][col];
        dfs(row,col,old_clr,color,grid,ans,vis);
        return ans;
    }
};