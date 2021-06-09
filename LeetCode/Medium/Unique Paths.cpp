//Method-1:
//Time Complexity:O(m*n)
//Space Complexity:O(m*n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        //here dp[i][j] is the number of unique paths to reach the point (i,j)
        for(int i=0;i<m;i++)
        {
            dp[i][0]=1;
        }
        for(int j=0;j<n;j++)
        {
            dp[0][j]=1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};
//Method-2:
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> pre(n,1),curr(n,1);
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                curr[j]=pre[j]+curr[j-1];
            }
            swap(pre,curr);
        }
        return pre[n-1];
    }
};
