//Method-1:
//Using BFS
class Solution {
public:
    vector<vector<int>> buildGraph(int numCourses,vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> g(numCourses);
        for(auto v:prerequisites)
        {
            g[v[1]].push_back(v[0]);
        }
        return g;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //check if a cycle exists in a directed graph
        //if graph is cyclic then topological odering doesn't exists & we cannot finish all the           courses
        //there are nodes = numCourses labeled from 0 to numCourses-1
       //build graph from prerequisites
        vector<vector<int>> graph = buildGraph(numCourses,prerequisites);
        //calculating the indegree of each of the vertices
        vector<int> inDegree(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            for(auto val:graph[i])
            {
                inDegree[val]++;
            }
        }
        //using a queue we keep a track of the vertices having indegree = 0
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
            }
        }
        //
        while(!q.empty())
        {
            auto f = q.front();
            q.pop();
            numCourses--;
            //iterate through all the neighbouring nodes of the dequeued node & decrease the 
            //indegree of the neighbours by one
            //If the indegree of the neighbouring node is 0 then enqueue it
            for(auto v:graph[f])
            {
                if(--inDegree[v]==0)
                {
                    q.push(v);
                }
            }
        }
        return numCourses == 0;
    }
};
