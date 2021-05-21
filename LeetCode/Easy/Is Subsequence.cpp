//Method-1 Recursion
class Solution {
public:
    bool helper(string str1,string str2,int m,int n)
    {
        if (m == 0) return true; 
        if (n == 0) return false; 
        // If last characters of two strings are matching 
        if (str1[m-1] == str2[n-1]) 
            return helper(str1, str2, m-1, n-1); 
        // If last characters are not matching 
            return helper(str1, str2, m, n-1); 
    }
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        return helper(s,t,m,n);
    }
};
//Method-2 Using Dynamic Programming
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m > n)
            return false;
        int dp[m+1][n+1];
        dp[0][0]=true;
        for(int i=1;i<=m;i++)
        {
            dp[i][0]=false;
        }
        for(int j=1;j<=n;j++)
        {
            dp[0][j]=true;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};

//Method-3 Two Pointers
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length();
        int n = t.length();
        int i = 0,j = 0;
        while(i<m && j<n)
        {
            if(s[i]==t[j])
            {
                i++;
            }
            j++;
        }
        if(i==m)
            return true;
        return false;
    }
};
