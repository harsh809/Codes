//49. Group Anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for(auto c:strs){
            string str = c;
            sort(str.begin(),str.end());
            mp[str].push_back(c);
        }
        for(auto c:mp){
            ans.push_back(c.second);
        }
        return ans;
    }
};