#include<bits/stdc++.h>
using namespace std;

// Time Complexity :- O(N*N)
// Space Complexity :- O(N*N)

long long dp[1001][1001];

long long solve(int i,int j,int arr[])
{
    if(i>j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    int op1 = arr[i] + min(solve(i+2,j,arr),solve(i+1,j-1,arr));
    int op2 = arr[j] + min(solve(i+1,j-1,arr),solve(i,j-2,arr));
    
    return dp[i][j] = max(op1,op2);
}

//Function to find the maximum possible amount of money we can win.
long long maximumAmount(int arr[], int n) 
{
    dp[n][n];
    memset(dp,-1,sizeof(dp));
    return solve(0,n-1,arr);
}