// codechef   Mode of Frequencies

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t){
	    int n;
	    cin>>n;
	    int* arr = new int[n];
	    unordered_map<int,int> mp;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        mp[arr[i]]++;
	    }
	    unordered_map<int,int> mod;            // 2->3   1->3
	    int maxi = INT_MIN;
	    for(auto c:mp){
	        mod[c.second]++;
	        maxi = max(maxi,mod[c.second]);        //3
	    }
	    int mini = INT_MAX;
	    for(auto c:mod){
	        if(c.second==maxi){
	            mini = min(mini,c.first);
	        }
	    }
	    cout<<mini<<endl;
	    t--;
	}
	return 0;
}
