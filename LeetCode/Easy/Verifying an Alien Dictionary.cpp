class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> orderMap(26);
        //array to store the order of the words in the alien dictionary
        for(int i=0;i<order.length();i++)
        {
            orderMap[order[i]-'a']=i;
        }
        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                //if the current word is larger than the next word return false
                if(j>=words[i+1].length())
                    return false;
                //if the current word character does not match the next word character 
                //then compare the order of both the characters in the orderMap
                if(words[i][j]!=words[i+1][j])
                {
                    int currWordChar = words[i][j]-'a';
                    int nextWordChar = words[i+1][j]-'a';
                    if(orderMap[currWordChar]>orderMap[nextWordChar])
                    {
                        //the given word is lexicographically larger than the next word
                        return false;
                    }
                    else
                        break;
                }
            }
        }
        return true;
    }
};
