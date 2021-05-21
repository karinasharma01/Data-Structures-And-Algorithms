class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        //number of persons
        int n = people.size();
        int count = 0;
        if(n<=1)
            return n;
        sort(people.begin(),people.end());
        int i=0,j=n-1;
        while(i<=j)
        {
            if(people[i]+people[j]<=limit)
            {
                count++;
                i++;
                j--;
            }
            else if(people[i]+people[j]>limit)
            {
                count++;
                j--;
            }
        }
        return count;
    }
};
