//Using Binary Search
//Time Complexity : O(logn)
//Space Complexity: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int start=0,end=m*n-1;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            int val = matrix[mid/n][mid%n];
            if(val==target)
                return true;
            if(val>target)
                end=mid-1;
            else
                start=mid+1;
        }
        return false;
    }
};
