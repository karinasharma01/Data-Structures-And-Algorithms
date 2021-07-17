class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size()<=1)
            return intervals;
        //sort the intervals on the basis of start time
        sort(intervals.begin(),intervals.end());
        //insert the first interval into the resultant merged array
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            if(res.back()[1]<intervals[i][0])
            {
                res.push_back(intervals[i]);
            }
            //if the end time of the previous interval is greater than or equal to the start time of 
            //the current interval,then update the end time of the previous interval
            else if(res.back()[1]>=intervals[i][0])
            {
                res.back()[1]=max(intervals[i][1],res.back()[1]);
            }
        }
        return res;
    }
};
