class Solution {
public:
    int percentageLetter(string s, char letter) {
        unordered_map<char,int> freq;
        if(s.size()==0)
            return 0;
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]]++;
        }
        if(freq.find(letter)==freq.end())
            return 0;
        return (100*freq[letter])/s.size();
    }
};
