//gfg Check if any anagram of a string is palindrome or not

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int isPossible (string s);

int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		if (isPossible (s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int isPossible (string S)
{
    unordered_map<char,int> mp;
    for(auto c:S){
        mp[c]++;
    }
    int count = 0;
    for(auto c:mp){
        if(c.second%2==1){
            count++;
        }
    }
    return count<=1;
}