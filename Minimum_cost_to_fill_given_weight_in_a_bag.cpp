#include<bits/stdc++.h>
using namespace std;

// Time Complexity :- O(N*W)
// Space Complexity :- O(N*W)

class Solution
{
    int dp[1001][1001];
    
    int solve(int arr[],int n,int w)
    {
        if(n==-1)
        {
            if(w==0)
            return 0;
            else
            return 1e9;
        }
        if(w==0) return 0;
        if(dp[n][w] != -1) return dp[n][w];
        
        if(arr[n]==-1 or n+1>w) return dp[n][w] = solve(arr,n-1,w);
        
        int x = solve(arr,n-1,w);
        int y = arr[n] + solve(arr,n,w-(n+1));
        
        return dp[n][w] = min(x,y);
    }
    
	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
        memset(dp,-1,sizeof(dp));
        int ans = solve(cost,N-1,W);
        if(ans == 1e9) return -1;
        else return ans;
	} 
};