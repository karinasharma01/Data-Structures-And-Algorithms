class Solution {
public:
    vector<string> findNbrs(string code)
    {
        vector<string> res;
        for(int i=0;i<4;i++)
        {
            for(int diff=-1;diff<=1;diff+=2)
            {
                string temp = code;
                temp[i] = (temp[i] - '0' + diff + 10) % 10 + '0';
                res.push_back(temp);
            }
        }
        return res;
    }
    int openLock(vector<string>& deadends, string target) {
        if(target=="0000")
            return 0;
        unordered_set<string> deadendsSet(deadends.begin(),deadends.end());
        if(deadendsSet.find("0000")!=deadendsSet.end())
            return -1;
        int moves = 0;
        unordered_set<string> visited;
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        while(!q.empty())
        {
            int levelSize = q.size();
            while(levelSize--)
            {
                string currCode = q.front();
                q.pop();
                vector<string> neighbours = findNbrs(currCode);
                for(auto n : neighbours)
                {
                    if(n == target)
                        return ++moves;
                    if(visited.find(n)!=visited.end())
                        continue;
                    if(deadendsSet.find(n)==deadendsSet.end())
                    {
                        q.push(n);
                        visited.insert(n);
                    }
                }
            }
            ++moves;
        }
        return -1;
    }
};
