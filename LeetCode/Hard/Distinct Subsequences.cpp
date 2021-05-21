class Solution {
public:
    int numDistinct(string s, string t) {
        int m=t.size();
        int n=s.size();
        if(m>n)
            return 0;
        vector<vector<unsigned long long>> dp(m+1,vector<unsigned long long> (n+1,0));
        for(int i=1;i<=m;i++)
        {
            dp[i][0]=0;
        }
        for(int j=0;j<=n;j++)
        {
            dp[0][j]=1;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i>j)
                    continue;
                if(t[i-1]!=s[j-1])
                {
                    dp[i][j]=dp[i][j-1];
                }
                else if(t[i-1]==s[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};
