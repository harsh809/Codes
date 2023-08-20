//332. Reconstruct Itinerary

class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> adj;
    void dfs(string src,stack<string> &st){
        auto &dst = adj[src];
        while(!dst.empty()){
            string airport = dst.top();
            dst.pop();
            dfs(airport,st);
        }
        st.push(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ans;
        stack<string> st;
        for(auto it:tickets){
            adj[it[0]].push(it[1]);
        }
        dfs("JFK",st);
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};