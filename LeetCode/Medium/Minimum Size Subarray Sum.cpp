class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int currSum = 0,start=0,end=0;
        int n = nums.size();
        while(end<n)
        {
            while(currSum < target && end<n)
            {
                currSum+=nums[end++];
            }
            while(currSum >= target && start<n)
            {
                minLen=min(minLen,end-start);
                currSum-=nums[start];
                start++;
            }
        }
        if(minLen==INT_MAX)
            return 0;
        return minLen;
    }
};
