//gfg Mother Vertex

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    void dfs(int node,vector<int> adj[],stack<int> &st,vector<int>& vis){
        vis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,st,vis);
            }
        }
        st.push(node);
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    int mvertex = INT_MAX;
	    for(int i=0;i<V;i++){
	        stack<int> st;
	        vector<int> vis(V,0);
	        dfs(i,adj,st,vis);
	        if(st.size()==V){
	            mvertex = min(mvertex,i);
	        }
	    }
	    if(mvertex==INT_MAX) return -1;
	    return mvertex;
	}

};
// optimized code
// public:
//     void dfs(int node,vector<int> adj[],stack<int> &st,vector<int>& vis){
//         vis[node] = 1;
//         for(auto it:adj[node]){
//             if(!vis[it]){
//                 dfs(it,adj,st,vis);
//             }
//         }
//         st.push(node);
//     }
// 	int findMotherVertex(int V, vector<int>adj[])
// 	{
// 	    stack<int> st;
// 	    vector<int> vis(V,0);
// 	    for(int i=0;i<V;i++){
// 	        if(!vis[i]){
// 	            dfs(i,adj,st,vis);
// 	        }
// 	    }
// 	    int node = st.top();
// 	    stack<int> str;
// 	    vector<int> visited(V,0);
// 	    dfs(node,adj,str,visited);
// 	    if(str.size()==V) return node;
// 	    return -1;
// 	}

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends