class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        //if the array contains less than 3 elements break early
        //Time Complexity : O(n^2)
        if(nums.size()<=2)
            return 0;
        int res = 0;
        int n = nums.size();
        int diff;
        for(int i=0;i<=n-2;i++)
        {
            diff = nums[i+1]-nums[i];
            for(int j=i+2;j<=n-1;j++)
            {
                if(nums[j]-nums[j-1]==diff)
                {
                    res++;
                }
                else
                {
                    break;
                }
            }
        }
        return res;
    }
};

//Method - 2:
//using dynamic programming 
//Time Complexity : O(n), Space Complexity:O(n)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        if(n<=2)
            return 0;
        //here dp[i] represents the number of arithmetic subarrays ending at index i including the ith element
        vector<int> dp(n);
        dp[0] = 0;dp[1] = 0;
        //check if the first three numbers form an arithmetic subarray or not
        if((nums[2]-nums[1])==(nums[1]-nums[0]))
            dp[2] = 1;
        else
            dp[2] = 0;
         count = dp[2];
        for(int i=3;i<n;i++)
        {
            //check if (nums[i],nums[i-1],nums[i-2]) form an arithmetic subsequence or not
            if((nums[i]-nums[i-1])==(nums[i-1]-nums[i-2]))
            {
                //an arithmetic subarray is formed hence add it to the count of the previously encountered subarrays
                dp[i] = 1 + dp[i-1];
            }
            count+=dp[i];
        }
        return count;
    }
};
