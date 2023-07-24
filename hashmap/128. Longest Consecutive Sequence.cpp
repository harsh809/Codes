// 128. Longest Consecutive Sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashset;
        for(auto c:nums){
            hashset.insert(c);
        }
        int maxlen = 0;
        for(auto c:nums){
            if(!hashset.count(c-1)){
                int curnum = c;
                int curlen = 1;
                while(hashset.count(curnum+1)){
                    curnum += 1;
                    curlen += 1;
                }
                maxlen = max(maxlen,curlen);
            }
        }
        return maxlen;
    }
};