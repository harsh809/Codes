//gfg  Job Sequencing Problem

//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job a,Job b){
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);
        int max_deadline = 0;
        vector<int> result;
        for(int i=0;i<n;i++){
            int deadline = arr[i].dead;
            max_deadline = max(max_deadline,deadline);
        }
        int count = 0;
        int max_profit = 0;
        vector<int> jobsdone(max_deadline+1,-1);
        for(int i=0;i<n;i++){
            int profit = arr[i].profit;
            int deadline = arr[i].dead;
            int id = arr[i].id;
            while(deadline>0 && jobsdone[deadline]!=-1){
                deadline--;
            }
            if(deadline>0 && jobsdone[deadline]==-1){
                count++;
                max_profit += profit;
                jobsdone[deadline] = id;
            }
        }
        
        return {count,max_profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends