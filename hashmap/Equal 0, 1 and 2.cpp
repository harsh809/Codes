//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
        long long zero = 0;
        long long one = 0;
        long long two = 0;
        map<pair<long long, long long>, long long> mp;
        int cnt = 0;
        mp[{0,0}] = 1;
        for(auto c:str){
            long long index = c-'0';
            if(index == 0){
                zero++;
            }
            else if(index == 1){
                one++;
            }
            else{
                two++;
            }
            pair<long long, long long> key = {one-zero,two-one};
            if(mp.find(key)!=mp.end()){
                cnt += mp[key];
            }
            mp[key]++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	}
    return 0;
}

// } Driver Code Ends