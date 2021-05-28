//Method-1:Binary Search
//Time Complexity:O(nlogn)
class Solution {
public:
    bool isPresent(vector<int>& nums,int target)
    {
        int left=0,right=nums.size()-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target)
                return true;
            if(nums[mid]>target)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return false;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        sort(nums2.begin(),nums2.end());
        //the second array is now sorted hence we can apply binary search 
        //on it to find if there exists an occurence of an element in nums1 in nums2
        for(int i=0;i<nums1.size();i++)
        {
            if(isPresent(nums2,nums1[i]))
                s.insert(nums1[i]);
        }
        vector<int> res(s.size());
        int i = 0;
        for(int a:s)
        {
            res[i++]=a;
        }
        return res;
    }
};
