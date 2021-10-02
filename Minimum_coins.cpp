#include<bits/stdc++.h>
using namespace std;

// Time Complexity :- O(N*Sum)
// Space Complexity :- O(Sum)

class Solution
{
	public:
	int MinCoin(vector<int>nums, int amount)
	{
	    int n = nums.size();
	    int dp[amount+1];
	    
	    memset(dp,-1,sizeof(dp));
	    dp[0] = 0;
	    
	    for(int i=1;i<=amount;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(nums[j] <= i)
	            {
	                int need = abs(i - nums[j]);
	       
	                if(dp[need] != -1)
	                {
	                    if(dp[i] == -1) dp[i] = 1 + dp[need];
	                    else dp[i] = min(dp[i], 1 + dp[need]);
	                }
	            }
	        }
	    }
	    
	   // for(int i=0;i<=amount;i++)
	   // cout << dp[i] << " ";
	    
	    return dp[amount];
	}
};