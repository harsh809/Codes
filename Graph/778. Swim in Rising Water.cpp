//778. Swim in Rising Water

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int> (n,0));
        int delta_row[4] = {1,0,-1,0};
        int delta_col[4] = {0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int row = it.second.first;
            int col = it.second.second;
            int maxi = it.first;
            if(row==n-1 && col==n-1){
                return maxi;
            }
            if(vis[row][col]==1){
                continue;
            }
            vis[row][col] = 1;
            for(int i=0;i<4;i++){
                int adjr = row + delta_row[i];
                int adjc = col + delta_col[i];
                if((adjr>=0 && adjr<n) && (adjc>=0 && adjc<n) && vis[adjr][adjc]==0){
                    pq.push({max(maxi,grid[adjr][adjc]),{adjr,adjc}});
                }
                
            }
        }
        return 1;
    }
};