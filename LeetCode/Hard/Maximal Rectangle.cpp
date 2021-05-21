class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int n = heights.size();
        stack<int> st;
        int area,currI;
        int i=0;
        while(i<n)
        {
            if(st.empty()||heights[i]>=heights[st.top()])
            {
                st.push(i);
                i++;
            }
            else
            {
                //if heights[i]<st.top()
                currI = st.top();
                st.pop();
                //find the area of the rectangle with heights[currI] as the smallest bar
                //rightI would be the current index i and left Index would the the one on 
                //stack's top
                //width of the max rectangle = rightI-leftI-1
                if(st.empty())
                {
                    area=heights[currI]*i;
                }
                else
                {
                    area=heights[currI]*(i-st.top()-1);
                }
                if(area>maxArea)
                {
                    maxArea = area;
                }
            }
        }
        while(!st.empty())
        {
            currI=st.top();
            st.pop();
            if(st.empty())
            {
                area=heights[currI]*i;
            }
            else
            {
                area=heights[currI]*(i-st.top()-1);
            }
            if(maxArea<area)
            {
                maxArea=area;
            }
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m==0)
            return 0;
        int n = matrix[0].size();
        int res = 0;
        vector<int> h(n,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='0')
                {
                    h[j]=0;
                }
                else
                {
                    h[j]+=1;
                }
            }
            res=max(res,largestRectangleArea(h));
        }
        return res;
    }
};
