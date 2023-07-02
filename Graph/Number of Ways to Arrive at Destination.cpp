//gfg   Number of Ways to Arrive at Destination

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>> pq;
        pq.push({0,0});
        vector<long> dist(n,1e10);
        dist[0] = 0;
        vector<int> ways(n,0);
        ways[0] = 1;
        int mod = 1e9 + 7;
        while(!pq.empty()){
            long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                long wt = it.second;
                int adjnode = it.first;
                if(dis+wt<dist[adjnode]){
                    dist[adjnode] = dis+wt;
                    pq.push({dis+wt,adjnode});
                    ways[adjnode] = ways[node]%mod;
                }
                else if(dis+wt==dist[adjnode]){
                    ways[adjnode] = (ways[adjnode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
    
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends