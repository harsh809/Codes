//gfg

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    bool is_same(unordered_map<char,int>& mp){
        int same;
        for(auto c:mp){
            if(c.second>0){
                same = c.second;
                break;
            }
        }
        for(auto c:mp){
            if(c.second>0 && same!=c.second){
                return false;
            }
        }
        return true;
    }
	bool sameFreq(string s)
	{
	    unordered_map<char,int> mp;
	    for(auto c:s){
	        mp[c]++;
	    }
	    if(is_same(mp)){
	        return true;
	    }
	    for(auto c:mp){
	        mp[c.first]--;
	        if(is_same(mp)){
	            return true;
	        }
	        mp[c.first]++;
	    }
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends