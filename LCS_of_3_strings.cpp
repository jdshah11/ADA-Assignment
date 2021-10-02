#include<bits/stdc++.h>
using namespace std;

// Approach :- similar to longest common subsequence
// Time Complexity :- O(N1*N2*N3)
// Space Complexity :- O(N1*N2*N3)

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    int dp[n1+1][n2+1][n3+1];
    memset(dp,-1,sizeof(dp));
    
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            for(int k=0;k<=n3;k++)
            {
                if(i==0 || j==0 || k==0)
                {
                    dp[i][j][k] = 0;
                }
                else if(A[i-1] == B[j-1] and B[j-1] == C[k-1])
                {
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                }
                else
                {
                    int ans1 = dp[i][j-1][k];
                    int ans2 = dp[i][j][k-1];
                    int ans3 = dp[i-1][j][k];
                    int ans4 = dp[i][j-1][k];
                    int ans5 = dp[i-1][j][k];
                    int ans6 = dp[i][j][k-1];
                    
                    dp[i][j][k] = max({ans1,ans2,ans3,ans4,ans5,ans6});
                }
            }
        }
    }
    return dp[n1][n2][n3];
}