//Method-1 Brute Force
//Time Complexity:O((n^2)*m) where n is the number of words given and m is the average length of each word
class Solution {
public:
    bool noCommonChar(string& s1,string& s2)
    {
        for(auto ch1:s1)
        {
            for(auto ch2:s2)
            {
                if(ch1==ch2)
                    return false;
            }
        }
        return true;
    }
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int maxProd = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(words[i].size()*words[j].size()<=maxProd)
                    continue;
                if(noCommonChar(words[i],words[j]))
                {
                    int currProd = words[i].size()*words[j].size();
                    maxProd=max(currProd,maxProd);
                }
            }
        }
        return maxProd;
    }
};


//Method-2:Using Bit Manipulation
//O(26*n^2)=O(n^2) where n is the number of words in the given array
class Solution {
public:
    int maxProduct(vector<string>& words) {
        //using Bit Manipulation
        
        int n = words.size();
        int maxProd = 0;
        vector<int> encode(n);
        for(int i=0;i<n;i++)
        {
            string word = words[i];
            for(int j=0;j<word.size();j++)
            {
                char ch = word[j];
                encode[i]|=1<<(ch-'a');
            }
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if((encode[i] & encode[j]) == 0)
                {
                    int currP=words[i].size()*words[j].size();
                    maxProd=max(maxProd,currP);
                }
            }
        }
        return maxProd;
    }
};
