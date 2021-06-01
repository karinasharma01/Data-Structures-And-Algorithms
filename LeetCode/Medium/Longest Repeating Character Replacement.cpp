class Solution {
public:
    int findLength(string s,int k,char ch)
    {
        int maxLen = 1;
        int n = s.size();
        int i=0,j=0;
        int count = 0;
        while(j < n)
        {
            if(s[j]!=ch)
                count++;
            while(count>k)
            {
                if(s[i]!=ch)
                    count--;
                i++;
            }
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
    int characterReplacement(string s, int k) {
        /*we need to find the maximum length of the substring that can be formed by each character
        and  whichever character will form the sub-string of maximum length then that length will          be our output*/
        int maxLen = 1;
        for(int i=0;i<26;i++)
        {
            maxLen = max(maxLen,findLength(s,k,i+'A'));
        }
        return maxLen;
    }
};
//Solution-2:
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26);
        int n = s.size();
        int i = 0,maxLen = 0;
        int maxCount = 0;
        for(int j=0;j<n;j++)
        {
            maxCount=max(maxCount,++count[s[j]-'A']);
            while(j-i+1-maxCount-k>0)
            {
                count[s[i]-'A']--;
                i++;
            }
            maxLen=max(maxLen,j-i+1);
        }
        return maxLen;
    }
};
