//gfg Count pairs in array divisible by K

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int k)
    {
        unordered_map<long long,long long> mp;
        long long ans = 0;
        for(int i=0;i<n;i++){
            int rem = A[i]%k;
            if(rem!=0){
                ans += mp[k-rem];
            }
            else{
                ans += mp[0];
            }
            mp[rem]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}

// } Driver Code Ends