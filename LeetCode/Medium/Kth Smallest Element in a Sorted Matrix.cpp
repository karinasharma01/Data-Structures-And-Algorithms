//Method-1 : Using Priority Queues
class Solution {
public:
    struct compare{
        bool operator()(const pair<int,pair<int,int>>& p1,const pair<int,pair<int,int>>& p2)
    {
        return p1.first > p2.first;
    }
        
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int count = 0,ans = 0;
        //we need to find kth smallest element in m sorted lists
         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> pq;
        //insert the first element of each row in the min Heap & the heap should not contain
        //more than k elements at a time
        for(int i=0;i<m && i<k;i++)
        {
            pq.push(make_pair(matrix[i][0],make_pair(i,0)));
        }
        //remove the smallest element from the heap 
        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            count++;
            ans = p.first;
            if(count==k)
                break;
            //increment the column value
            p.second.second++;
            if(p.second.second<m)
            {
                p.first=matrix[p.second.first][p.second.second];
                pq.push(p);
            }
        }
        return ans;
    }
};
