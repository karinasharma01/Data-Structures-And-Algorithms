class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)
            return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        //The given problem can be solved using Binary Search(index-based) since integers in each 
        //row are sorted from left to right & first integer of each row is greater than the last           //integer of the previous row.
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
