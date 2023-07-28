//gfg Smallest subarray with all occurrences of a most frequent element

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    vector<int> smallestSubsegment(int a[], int n)
    {
    	vector<int> ans;
    	unordered_map<int,int> last;
    	unordered_map<int,int> count;
    	int mx = 0;
    	int mn = 0,str = 0;
    	for(int i=0;i<n;i++){
    	    int x = a[i];
    	    if(count[x]==0){
    	        last[x] = i;
    	        count[x] = 1;
    	    }
    	    else{
    	        count[x]++;
    	    }
    	    if(count[x]>mx){
    	        mx = count[x];
    	        mn = i-last[x]+1;
    	        str = last[x];
    	    }
    	    else if(count[x]==mx && i-last[x]+1<mn){
    	        mn = i-last[x]+1;
    	        str = last[x];
    	    }
    	}
    	for(int i=str;i<mn+str;i++){
    	    ans.push_back(a[i]);
    	}
    	return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; int a[n];
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    vector<int > v;
	    Solution ob;
	    v = ob.smallestSubsegment(a, n);
	    for(int i:v)
	        cout<< i << " ";
	    cout<<"\n";
	}
return 0;
}

// } Driver Code Ends