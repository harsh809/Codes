//gfg   Euler Circuit in an Undirected Graph

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isEularCircuitExist(int V, vector<int>adj[]){
	    vector<int> edges(V,0);
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            edges[it]++;
	        }
	    }
	    for(int i=0;i<V;i++){
	        if(edges[i]%2!=0){
	            return 0;
	        }
	    }
	    
	    return 1;
	}

};

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
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isEularCircuitExist(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends