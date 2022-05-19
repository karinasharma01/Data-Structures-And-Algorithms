class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //O(n) time complexity
        int first = -1;
        int last = -1;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=target)
                continue;
            if(first==-1)
            {
                first = i;
            }
            last = i;
        }
        if(first==-1)
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        res.push_back(first);
        res.push_back(last);
        return res;
    }
};

//O(logn) time complexity using Binary Search
class Solution {
public:
    int findLast(vector<int>& nums,int n,int left,int right,int target)
    {
        if(left<=right)
        {
            int mid = left+(right-left)/2;
            if((mid==n-1||nums[mid+1]>target) && nums[mid]==target)
            {
                return mid;
            }
            if(nums[mid]<=target)
                return findLast(nums,n,mid+1,right,target);
            return findLast(nums,n,left,mid-1,target);
        }
        return -1;
    }
    int findFirst(vector<int>& nums,int n,int left,int right,int target)
    {
        if(left<=right)
        {
            int mid = left+(right-left)/2;
            if((mid==0 || nums[mid-1]<target) && nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
            {
                return findFirst(nums,n,mid+1,right,target);
            }
            return findFirst(nums,n,left,mid-1,target);
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int n = nums.size();
        //find the first and the last occurence of the element in the array using binary search
        int first = findFirst(nums,n,0,n-1,target);
        int last = findLast(nums,n,0,n-1,target);
        res.push_back(first);
        res.push_back(last);
        return res;
    }
};
