class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();//numbers of cars
        int res = 0;
        /*the car located at the position closest to the target position will lead the fleet of cars initially 
        If a car A is located at a position x & car B is located at a position y &  y<x<target then if the car B arrives faster than 
        car A at destination i.e (target-y)/speedB < (target-x)/speedA then car A takes greater time to reach the destination then that indicates that car B catches up to car A & then they form a fleet and travel together with the same speed 
        */
        vector<pair<int,double>> cars;
        for(int i=0;i<n;i++)
        {
            double arrival_time = (double)(target-position[i])/(double)speed[i];
            cars.push_back({position[i],arrival_time});
        }
        //if a car has an arrival time greater than the current car being considered as the slowest car then in that case it will become the new slowest car & would lead the fleet
        sort(cars.begin(),cars.end());
        pair<int,double> curr = cars[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(cars[i].second > curr.second)
            {
                res++;
                curr = cars[i];
            }
        }
        return res+1;
    }
};
