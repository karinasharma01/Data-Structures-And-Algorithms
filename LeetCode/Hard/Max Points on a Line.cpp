//Method - 1 : using three nested for loops Time Complexity : O(n^3)
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<3)
            return n;
        int res = 2;
        //O(n^3) solution 
        //fix the rwo points forming a line and check if a third point lies on the same line or not
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int count = 2;
                for(int k=0;k<n;k++)
                {
                    if(k==i||k==j)
                        continue;
                    else
                    {
                        if((points[j][1]-points[k][1])*(points[k][0]-points[i][0])==(points[k][1]-points[i][1])*(points[j][0]-points[k][0]))
                        {
                            count++;
                        }
                    }
                }
                res = max(res,count);
            }
            
        }
        return res;
    }
};

//Method 2 :
//Using hashmap
//Time complexity : O(n^2)
class Solution {
public:
    int gcd(int a,int b)
    {
        if(b==0)
            return a;
        return gcd(b,a%b);
    }
    int maxPoints(vector<vector<int>>& points) {
        /*
        We need to find the slope of all the lines connecting p to all other points and use a map to make a record of how many lines have the same slope. If two lines have the same slope and have a common point then they belong to the same line.
        vertical defines the points that are on a vertical line
        overlap indicates the same points with the same x & y coordinates
        */
        int n = points.size();
        if(n<3)
            return n;
        int res = 0;
        for(int i=0;i<n;i++)
        {
            map<pair<int,int>,int> mp;
            int vertical=0,overlap=0;
            int curr_max = 0;
            for(int j=i+1;j<n;j++)
            {
                if(points[i][0]==points[j][0] && points[i][1]==points[j][1])
                {
                    overlap++;
                }
                else if(points[i][0]==points[j][0])
                {
                    vertical++;
                }
                else
                {
                    int diff_x = points[i][0]-points[j][0];
                    int diff_y = points[i][1]-points[j][1];
                    int g = gcd(diff_x,diff_y);
                    diff_x/=g;
                    diff_y/=g;
                    mp[{diff_x,diff_y}]++;
                    curr_max = max(curr_max,mp[{diff_x,diff_y}]);
                }
                curr_max = max(curr_max,vertical);
            }
            res = max(res,curr_max+overlap+1);
        }
        return res;
    }
};
