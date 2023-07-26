//gfg   Longest Distinct characters in string

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    int ans = 0;
    unordered_map<char,int> mp;
    int i=0;
    int j=0;
    int n = s.length();
    while(j<n){
        mp[s[j]]++;
        if(mp[s[j]]==1){
            ans = max(ans,j-i+1);
            j++;
        }
        else if(mp[s[j]]>1){
            while(mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }
            j++;
        }
    }
    return ans;
}