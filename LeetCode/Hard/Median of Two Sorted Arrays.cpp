//Method-1:
//Time Complexity:O(m+n)
//Space Complexity : O(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        //since both the arrays are sorted we can merge both the arrays
        vector<int> res(m+n);
        int i=0,j=0,k=0;
        //merging process
        while(i<m && j<n)
        {
            if(nums1[i]>=nums2[j])
            {
                res[k++]=nums2[j++];
            }
            else
            {
                res[k++]=nums1[i++];
            }
        }
        while(i!=m)
        {
            res[k++]=nums1[i++];
        }
        while(j!=n)
        {
            res[k++]=nums2[j++];
        }
        //if the length of the resultant array is odd then the element at index (m+n) is median
        if(res.size()%2)
            return res[res.size()/2];
        //if the length of array is even then average of elements at index (m+n)/2-1 & (m+n)/2
        return (res[res.size()/2-1]+res[res.size()/2])/2.0;
    }
};
