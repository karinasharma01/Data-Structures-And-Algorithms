//Method1 - using Recursion
//Time Complexity : O(2^(m*n))
class Solution {
public:
    int uniquePathsHelper(vector<vector<int>>& grid,int i,int j,int m,int n)
    {
        //out of bounds
        if(i==m||j==n)
            return 0;
        //if obstacle is present at the cell (i,j),then there is no path from that cell to reach the destination
        if(grid[i][j]==1)
            return 0;
        if(i==m-1 && j==n-1)
            return 1;
        int w1 = uniquePathsHelper(grid,i+1,j,m,n);//move right
        int w2 = uniquePathsHelper(grid,i,j+1,m,n);//move down
        return w1 + w2;//total number of ways
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //using recursion
      //calculating the number of paths to reach the cell (m-1,n-1) starting from the cell (0,0)
      return uniquePathsHelper(obstacleGrid,0,0,m,n);
    }
};

//Method 2 : Using Dynamic Programming
//Time Complexity : O(m*n)
//Space Complexity : O(m*n)
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m==0)
            return 0;
        int n = obstacleGrid[0].size();
        //using dynamic programming 
        vector<vector<int>> dp(m,vector<int> (n,0));
        //here dp[i][j] represents the number of paths to reach the cell (i,j) starting from (0,0) in the given grid
        if(obstacleGrid[0][0]==0)//no obstacle present
        {
            dp[0][0] = 1;
        }
        //first row of the matrix
        for(int j=1;j<n;j++)
        {
            if(obstacleGrid[0][j]==0)
            {
                dp[0][j] = dp[0][j-1];
            }
            else
            {
                dp[0][j] = 0;
            }
        }
        //first column of the matrix
        for(int i=1;i<m;i++)
        {
            if(obstacleGrid[i][0]==0)
            {
                dp[i][0] = dp[i-1][0];
            }
            else
            {
                dp[i][0] = 0;
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j]==0)
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
