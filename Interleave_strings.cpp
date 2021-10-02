#include<bits/stdc++.h>
using namespace std;

// Time Complexity :- O(N*M)
// Space Complexity :- O(N*M)

class Solution
{
  public:
  
    int dp[1001][1001];
    /*You are required to complete this method */
    
    bool solve(string s1,string s2,string s3,int n,int m,int len)
    {
        if(len == 0) return 1;
        if(dp[n][m] != -1) return dp[n][m];
        
        int a=0,b=0;
        if(n-1>=0 and s1[n-1] == s3[len-1]) a = solve(s1,s2,s3,n-1,m,len-1);
        if(m-1>=0 and s2[m-1] == s3[len-1]) b = solve(s1,s2,s3,n,m-1,len-1);
        return dp[n][m] = a or b;
    }
    
    bool isInterleave(string A, string B, string C) 
    {
        int n = A.length();
        int m = B.length();
        int res = C.length();
        dp[n+1][m+1];
        memset(dp,-1,sizeof(dp));
        return solve(A,B,C,n,m,res);
    }

};