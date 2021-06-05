class Solution {
public:
    vector<vector<int>> buildGraph(int numCourses,vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> g(numCourses);
        for(auto p:prerequisites)
        {
            g[p[1]].push_back(p[0]);
        }
        return g;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        vector<vector<int>> graph = buildGraph(numCourses,prerequisites);
        //ca;culate the indegree of each vertex
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            for(auto val:graph[i])
            {
                indegree[val]++;
            }
        }
        queue<int> q;//q to store all vertices with 0 indegree
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            order.push_back(f);
            for(auto v : graph[f])
            {
                if(--indegree[v]==0)
                {
                    q.push(v);
                }
            }
            
        }
        if(order.size()!=numCourses)
            order.clear();
        return order;
    }
};
