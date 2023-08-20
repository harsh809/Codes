//1203. Sort Items by Groups Respecting Dependencies

class Solution {
public:
    vector<int> topo(vector<int> &indegree,vector<int> adj[]){
        queue<int> q;
        int n = indegree.size();
        for(int i=0;i<n;i++){
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
        return ans;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int j = m;
        for(int i=0;i<n;i++){
            if(group[i]==-1){
                group[i] = j++;
            }
        }
        vector<int> indgroup(j,0);
        vector<int> indbefore(n,0);
        vector<int> adjbefore[n];
        vector<int> adjgroup[j];
        for(int i=0;i<n;i++){
            for(auto it:beforeItems[i]){
                adjbefore[it].push_back(i);
                indbefore[i]++;
                if(group[i]!=group[it]){
                    adjgroup[group[it]].push_back(group[i]);
                    indgroup[group[i]]++;
                }
            }
        }
        vector<int> item = topo(indbefore,adjbefore);
        vector<int> grp = topo(indgroup,adjgroup);
        vector<vector<int>> res(j);
        for(auto it:item){
            int gr = group[it];
            res[gr].push_back(it);
        }
        vector<int> ans;
        for(auto it:grp){
            for(int i=0;i<res[it].size();i++){
                ans.push_back(res[it][i]);
            }
        }
        if(ans.size()<n) return {};
        return ans;
    }
};