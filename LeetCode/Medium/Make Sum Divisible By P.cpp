class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int len = INT_MAX;
        long sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        int target = sum % p;
        //we need to find the length of the smallest subarray whose sum of the elements will 
        //leave a remainder = target
        if(target==0)
            return 0;
        //map to store the current remainder & the most recent index where the current rem occured
        unordered_map<int,int> map;
        map.insert(make_pair(0,-1));
        long currRem = 0;
        for(int i=0;i<n;i++)
        {
            currRem=(currRem+nums[i]+p)%p;
            map[currRem]=i;
            int mod = (currRem-target+p)%p;
            if(map.find(mod)!=map.end())
            {
                len=min(len,i-map[mod]);
            }
            
        }
        if(len==INT_MAX||len==n)
            return -1;
        return len;
    }
};
