//coding ninja    Ninja’s Training

//  approach 1    TC = Q(n*4*3)    SC = O(N*4) + O(n)
int f(int ind,int last,vector<vector<int>> &points,vector<vector<int>> &dp){
    if(ind==0){
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi = max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    if(dp[ind][last]!=-1) return dp[ind][last];
    int maxi = 0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int point = points[ind][i] + f(ind-1,i,points,dp);
            maxi = max(maxi,point);
        }

    }
    return dp[ind][last] = maxi;

}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int> (4,-1));
    int last = 3;
    return f(n-1,3,points,dp);
}

//approach 2     TC = Q(n*4*3)    SC = O(N*4)

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int> (4,0));
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][2],points[0][0]);
    dp[0][2] = max(points[0][1],points[0][0]);
    dp[0][3] = max(points[0][0],max(points[0][1],points[0][2]));
    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            for(int task=0;task<3;task++){
                if(task!=last){
                    dp[day][last] = max(points[day][task] + dp[day-1][task],dp[day][last]);
                }
            }
        }
    }
    return dp[n-1][3];
}


//approach 2     TC = Q(n*4*3)    SC = O(4)

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4,0);
    prev[0] = max(points[0][1],points[0][2]);
    prev[1] = max(points[0][2],points[0][0]);
    prev[2] = max(points[0][1],points[0][0]);
    prev[3] = max(points[0][0],max(points[0][1],points[0][2]));
    for(int day=1;day<n;day++){
        vector<int> temp(4,0);
        for(int last=0;last<4;last++){
            for(int task=0;task<3;task++){
                if(task!=last){
                    temp[last] = max(points[day][task] + prev[task],temp[last]);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}