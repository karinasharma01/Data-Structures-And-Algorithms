class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        int lastNegative = n-1;
        //if the first element of a row is negative then the entire row contains -ve nos
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]<0)
            {
                count+=n;
                continue;
            }
            //if the last element in a row is positive then row doesn't contain any 
            //negative numbers
            if(grid[i][n-1]>0)
                continue;
            int start=0,end=lastNegative;
            while(start<=end)
            {
                int mid=start+(end-start)/2;
                if(grid[i][mid]<0)
                {
                    end=mid-1;
                }
                else
                {
                    start=mid+1;
                }
                
            }
            //here start points to the first negative element in the row 
            //all the other elements in that row after l would be negative since array
            //is sorted int decreasing order
            //Number of -ve elements in the row are columns-start
            count+=n-start;
            lastNegative = start;
        }
        return count;
    }
};
