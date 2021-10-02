#include<bits/stdc++.h>
using namespace std;

// Time Complexity :- O(N*N*N)
// Space Complexity :- O(N*N)

class Solution
{
public:
    
    int solve(int i,int j,int arr[],vector<vector<int>> &dp)
    {
        if(i==j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int min_value = INT_MAX;
        
        for(int k=i;k<j;k++)
        {
            int ans = solve(i,k,arr,dp) + solve(k+1,j,arr,dp) + (arr[i-1]*arr[j]*arr[k]);
            min_value = min(min_value,ans);
        }
        return dp[i][j] = min_value;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N,vector<int> (N,-1));
        return solve(1,N-1,arr,dp);
    }
};