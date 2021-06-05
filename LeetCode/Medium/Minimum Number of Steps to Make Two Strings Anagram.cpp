class Solution {
public:
    int minSteps(string s, string t) {
        int count = 0;
        //array to store the frequencies of characters
        vector<int> freq(26,0);
        //store the frequencies of the characters in string s
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]-'a']++;
        }
        //iterate over the string t & decrement the frequencies of the characters
        for(int i=0;i<t.size();i++)
        {
            freq[t[i]-'a']--;
        }
        //calculate the sum of the absolute frequency of the 26 letters
        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0)
            {
                count+=abs(freq[i]);
            }
        }
        return count/2;
    }
};
