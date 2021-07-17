//Method-1:O(nlogn)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        intervals.push_back(newInterval);
        if(intervals.size()<=1)
            return intervals;
        sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            if(res.back()[1]>=intervals[i][0])
            {
                res.back()[1]=max(res.back()[1],intervals[i][1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
//Method-2:O(n) solution
class Solution {
public:
    vector<int> mergeIntervals(vector<int>& i1,vector<int>& i2)
    {
        int startTime = min(i1[0],i2[0]);
        int endTime = max(i1[1],i2[1]);
        vector<int> merged(2);
        merged[0]=startTime;
        merged[1]=endTime;
        return merged;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        for(int i=0;i<n;i++)
        {
            if(intervals[i][1]<newInterval[0])
                res.push_back(intervals[i]);
            else if(newInterval[1]<intervals[i][0])
            {
                res.push_back(newInterval);
                for(int j=i;j<n;j++)
                {
                    res.push_back(intervals[j]);
                }
                return res;
            }
            //if the end time of the previous interval is greater than the start time of the new Interval
            else
            {
                newInterval = mergeIntervals(newInterval,intervals[i]);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};
