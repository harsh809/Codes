//leetcode  218. The Skyline Problem

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<pair<int,int>> v;
        multiset<int,greater<int>> ht;
        ht.insert(0);
        for(auto c:buildings){
            v.push_back({c[0],-c[2]});
            v.push_back({c[1],c[2]});
        }
        sort(v.begin(),v.end());
        int n = v.size();
        int premax = 0;
        for(auto it:v){
            if(it.second<0){
                ht.insert(-it.second);
            }
            else{
                ht.erase(ht.find(it.second));
            }
            int curmax = *ht.begin();
            if(curmax!=premax){
                ans.push_back({it.first,curmax});
                premax = curmax;
            }
        }
        return ans;
    }
};
