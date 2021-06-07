class Solution {
public:
    int helper(string& s,char startC)
    {
        int swaps = 0;
        //count all the wrongly placed characters
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=startC)
                swaps++;
            startC^=1;
        }
        return swaps/2;
    }
    int minSwaps(string s) {
        int n = s.size();
        int count0=0,count1=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
                count1++;
            else
                count0++;
        }
        //if the absolute difference between count0 & count1 is greater than one then it is
        //impossible to obtain an alternating binary string
        if(abs(count0-count1)>1)
            return -1;
        //if the length of the string is odd then two cases are possible
        //if the count of zeros is greater than the count of ones,then string must start with 0
        if(count0>count1)
            return helper(s,'0');
        if(count1>count0)
            return helper(s,'1');
        //if the string is of even length then there are two possibilities,in that case weneed to return the minimum of the two
        return min(helper(s,'0'),helper(s,'1'));
            
    }
};
