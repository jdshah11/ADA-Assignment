#include<bits/stdc++.h>
using namespace std;

// Time Complexity :- O(N*N)
// Space Complexity :- O(N*N)  

class Solution
{
    public:
    /*You are required to complete below method */
    long long int dp[1001][1001];
    long long int mod = 1e9+7;
    
    long long int solve(int i,int j,string &str) // here we are passing string by reference to avoid TLE
    {
        if(i==j) return 1;
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(str[i]==str[j])
        {
            return dp[i][j] = (solve(i+1,j,str)%mod + solve(i,j-1,str)%mod + 1 + mod)%mod;
        }
        else
        {
            return dp[i][j] = (solve(i+1,j,str)%mod + solve(i,j-1,str)%mod - solve(i+1,j-1,str)%mod + mod)%mod;
        }
    }
    
    long long int  countPS(string str)
    {
        int n = str.length();
        memset(dp,-1,sizeof(dp));
        long long int ans = solve(0,n-1,str);
        return ans%mod;
    }
     
};