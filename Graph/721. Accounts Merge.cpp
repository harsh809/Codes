//leetcode  721. Accounts Merge

class Solution {
public:
    class disjoint_set{
        public:
        vector<int> parent,size;
        disjoint_set(int n){
            parent.resize(n);
            size.resize(n);
            for(int i=0;i<n;i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
        int ult_par(int node){
            if(node==parent[node]){
                return node;
            }
            return parent[node] = ult_par(parent[node]);
        }
        void union_size(int u,int v){
            int ult_u = ult_par(u);
            int ult_v = ult_par(v);
            if(ult_u == ult_v) return;
            if(size[ult_u]<size[ult_v]){
                parent[ult_u] = ult_v;
                size[ult_v] += size[ult_u];
            }
            else{
                parent[ult_v] = ult_u;
                size[ult_u] += size[ult_v];
            }
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        disjoint_set ds(n);
        unordered_map<string,int> mailtoparent;
        for(int i=0;i<n;i++){
            int m = accounts[i].size();
            for(int j=1;j<m;j++){
                string mail = accounts[i][j];
                if(mailtoparent.find(mail) == mailtoparent.end()){
                    mailtoparent[mail] = i;
                }
                else{
                    ds.union_size(i,mailtoparent[mail]);
                }
            }
        }
        vector<string> mergemail[n];
        for(auto it:mailtoparent){
            string mail = it.first;
            int node = ds.ult_par(it.second);
            mergemail[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergemail[i].size()==0) continue;
            sort(mergemail[i].begin(),mergemail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergemail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};