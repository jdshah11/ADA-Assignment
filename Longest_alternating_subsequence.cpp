#include<bits/stdc++.h>
using namespace std;

// Iterative Dp using two variables to optimize space
// Time Complexity :- O(N)
// Space Complexity :- O(1)

class Solution 
{
	public:
	
		int AlternatingaMaxLength(vector<int>&nums)
		{
		    int n = nums.size();
		    int increasing = 1;
		    int decreasing = 1;
		    
		    for(int i=1;i<n;i++)
		    {
		        if(nums[i]>nums[i-1]) increasing = decreasing + 1;
		        else if(nums[i]<nums[i-1]) decreasing = increasing + 1;
		    }
		    
		    return max(increasing,decreasing);
		}

};