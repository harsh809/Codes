//gfg  Prerequisite Tasks

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    unordered_map<int,list<int>> adj;
	    int indegree[N] = {0};
	    for(int i=0;i<prerequisites.size();i++){
	        int u = prerequisites[i].first;
	        int v = prerequisites[i].second;
	        adj[u].push_back(v);
	        indegree[v]++;
	    }
	    queue<int> q;
	    for(int i=0;i<N;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    vector<int> ans;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    if(ans.size()==N){
	        return true;
	    }
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends