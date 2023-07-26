//438. Find All Anagrams in a String

class Solution {
public:
    bool is_same(unordered_map<char,int>& ps,unordered_map<char,int>& ss){
        for(auto c:ps){
            if(ps[c.first]!=ss[c.first]){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.length()>s.length()){
            return ans;
        }
        unordered_map<char,int> ps,ss;
        int n = p.length();
        for(int i=0;i<n;i++){
            ps[p[i]]++;
            ss[s[i]]++;
        }
        int j = n;
        while(j<=s.length()){
            if(is_same(ps,ss)){
                ans.push_back(j-n);
            }
            char ch = s[j-n];
            ss[ch]--;
            ss[s[j]]++;
            j++;
        }
        return ans;
    }
};