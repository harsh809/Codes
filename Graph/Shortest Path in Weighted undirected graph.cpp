//gfg   Shortest Path in Weighted undirected graph

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[N+1];
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
        vector<int> dist(N+1,1e9);
        dist[1] = 0;
        vector<int> parent(N+1);
        for(int i=1;i<=N;i++) parent[i] = i;
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int weight = it.second;
                int adjnode = it.first;
                if(dis + weight < dist[adjnode] ){
                    dist[adjnode] = dis + weight;
                    pq.push({dist[adjnode],adjnode});
                    parent[adjnode] = node;
                }
            }
        }
        if(dist[N]==1e9) return {-1};
        vector<int> ans;
        int node = N;
        
        while(parent[node] !=node){
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
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