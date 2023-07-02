//gfg    Path With Minimum Effort

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        dist[0][0] = 0;
        int deltarow[4] = {-1,0,1,0};
        int deltacol[4] = {0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row == n-1 && col == m-1){
                return diff;
            }
            for(int i=0;i<4;i++){
                int nrow = row + deltarow[i];
                int ncol = col + deltacol[i];
                if((nrow>=0 && nrow<n) && (ncol>=0 && ncol<m)){
                    int neweffort = max(abs(heights[row][col]-heights[nrow][ncol]),diff);
                    if(neweffort<dist[nrow][ncol]){
                        dist[nrow][ncol] = neweffort;
                        pq.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
            
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends