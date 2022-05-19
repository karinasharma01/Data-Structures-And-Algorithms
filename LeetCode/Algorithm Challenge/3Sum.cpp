class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> output;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            //the sum of the triplets must be equal to 0
            int target = -nums[i];
            int j = i+1;
            int k = n-1;
            while(j<k)
            {
                int currSum = nums[j]+nums[k];
                //finding triplet which starts from nums[i]
                if(currSum > target)
                {
                    k--;
                }
                else if(currSum < target)
                {
                    j++;
                }
                else
                {
                    vector<int> triplet(3,0);
                    triplet[0]=nums[i];
                    triplet[1]=nums[j];
                    triplet[2]=nums[k];
                    output.push_back(triplet);
                    
                    while(j < k && nums[j]==triplet[1])
                    {
                        j++;
                    }
                    while(j < k && nums[k]==triplet[2])
                    {
                        k--;
                    }
                }
            }
            while(i+1 <n && nums[i+1]==nums[i])
            {
                i++;
            }
        }
        return output;
        
    }
};
