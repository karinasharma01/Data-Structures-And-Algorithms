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

//Method-2:Using hashsets
//Time Complexity:O(n)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1;
        set<int> s2;
        for(int i=0;i<nums1.size();i++)
        {
            s1.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(s1.find(nums2[i])!=s1.end())
            {
                s2.insert(nums2[i]);
            }
        }
        int i = 0;
        vector<int> result(s2.size());
        for(int num:s2)
        {
            result[i++]=num;
        }
        return result;
    }
};
