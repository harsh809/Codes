// 954. Array of Doubled Pairs

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int> mp;
        
        for(auto c:arr){
            mp[c]++;
        }
        for(auto c:arr){
            if(mp[c]==0) continue;
            if(mp[c*2]>0){
                mp[c*2]--;
                mp[c]--;
            }
        }
        for(auto c:mp){
            if(c.second!=0) return false;
        }
        return true;
    }
};class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int> mp;
        
        for(auto c:arr){
            mp[c]++;
        }
        for(auto c:arr){
            if(mp[c]==0) continue;
            if(mp[c*2]>0){
                mp[c*2]--;
                mp[c]--;
            }
        }
        for(auto c:mp){
            if(c.second!=0) return false;
        }
        return true;
    }
};