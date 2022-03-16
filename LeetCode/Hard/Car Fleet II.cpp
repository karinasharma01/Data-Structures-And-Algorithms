class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> res(n,-1);
        stack<int> st;//used for storing the indices of the cars
        //we'll be considering only those cars while going from right to left that are moving at a speed less than our current car because only then our car would be able to collide with a car to its right
        for(int i=n-1;i>=0;i--)
        {
            //checking for cars that have a speed less than out current car
            //we maintain a stack of indices of cars in monotonic increasing order of their speeds
            while(!st.empty() && cars[i][1]<=cars[st.top()][1])
            {
                st.pop();
            }
            //if there are cars in the stack then it can surely collide with one of them
            while(!st.empty())
            {
                //calculation of the collision time of the car 
                double collision_time = (double)(cars[st.top()][0]-cars[i][0])/(cars[i][1]-cars[st.top()][1]);
                //We start with the car at the top of the stack ie the fastest car on its right.
                //If we collidde with that car before it collides with any car ahead,then we have the collision time of the current car otherwise if our current car collides with the car after it collides with any car ahead then we have to ignore that car and also pop it from the stack
                if(collision_time<=res[st.top()] || res[st.top()]==-1)
                {
                    res[i] = collision_time;
                    break;
                }
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
