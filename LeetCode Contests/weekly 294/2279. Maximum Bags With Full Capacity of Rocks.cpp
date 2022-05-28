class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        int res = 0;
        vector<int> diff;
        for(int i=0;i<n;i++)
        {
            diff.push_back(capacity[i]-rocks[i]);
        }
        sort(diff.begin(),diff.end());
        for(int i=0;i<diff.size() && additionalRocks>=diff[i];i++)
        {
            if(additionalRocks>=diff[i])
            {
                res++;
                additionalRocks-=diff[i];
            }
            else
            {
                break;
            }
        }
        return res;
    }
};
