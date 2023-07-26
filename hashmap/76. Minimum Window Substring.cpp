//76. Minimum Window Substring

class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        int n = s.length();
        int m = t.length();
        if(n==0 || m==0 || n<m){
            return ans;
        }
        vector<int> v(256,0);
        for(int i=0;i<m;i++){
            v[t[i]]++;
        }
        int end = 0;
        int start = 0;
        int ans_start = 0;
        int count = 0;
        int min_length = INT_MAX;
        while(end<n){
            if(v[s[end]]>0){
                count++;
            }
            v[s[end]]--;
            while(count==m){
                if(min_length>end-start+1){
                    min_length = end-start+1;
                    ans_start = start;
                }
                v[s[start]]++;
                if(v[s[start]]>0){
                    count--;
                }
                start++;
            }
            end++;
        }
        if(min_length==INT_MAX){
            return "";
        }
        ans = s.substr(ans_start,min_length);      
        return ans;
    }
};