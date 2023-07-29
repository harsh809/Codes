//leetcode 1584. Min Cost to Connect All Points

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n==1) return 0;
        unordered_map<int,vector<pair<int,int>>> adj;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int manh = abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({j,manh});
                adj[j].push_back({i,manh});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,0});
        unordered_map<int,bool> vis;
        int sum = 0;
        while(!q.empty()){
            auto c = q.top();
            q.pop();
            int wt = c.first;
            int p1 = c.second;
            if(vis[p1]) continue;
            vis[p1] = true;
            sum += wt;
            for(auto it:adj[p1]){
                int edwt = it.second;
                int ed = it.first;
                if(!vis[ed]){
                    q.push({edwt,ed});
                }
            }
        }
        return sum;
    }
};
