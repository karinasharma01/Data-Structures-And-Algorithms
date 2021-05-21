class Solution {
public:
    bool match(string word,string pattern)
    {
        unordered_map<char,char> hMap1;
        unordered_map<char,char> hMap2;
        for(int i=0;i<word.length();i++)
        {
            char ch1=word[i];
            char ch2=pattern[i];
            if(hMap1.find(ch1)==hMap1.end())
            {
                hMap1[ch1]=ch2;
            }
            if(hMap2.find(ch2)==hMap2.end())
            {
                hMap2[ch2]=ch1;
            }
            if(hMap1[ch1]!=ch2||hMap2[ch2]!=ch1)
            {
                return false;
            }
            
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(int i=0;i<words.size();i++)
        {
            if(match(words[i],pattern))
            {
                res.push_back(words[i]);
            }
        }
        return res;
    }
};
