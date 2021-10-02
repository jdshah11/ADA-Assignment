#include<bits/stdc++.h>
using namespace std;

// Time Complexity :- O(N*N)
// Space Complexity :- O(N)

class Solution
{
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int dp[n],ans = INT_MIN;
	    for(int i=0;i<n;i++)
	    {
	        dp[i] = arr[i];
	        for(int j=0;j<i;j++)
	        {
	            if(arr[j]<arr[i])
	            {
	                dp[i] = max(dp[i],dp[j]+arr[i]);
	            }
	        }
	        ans = max(ans,dp[i]);
	    }
	    return ans;
	}  
};