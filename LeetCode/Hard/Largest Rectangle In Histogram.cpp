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
};
