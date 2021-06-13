//Method:Using Depth First Search
class Solution {
public:
    int dest;
    void dfs(vector<vector<int>>& graph,int src,vector<int>& p,vector<vector<int>>& paths)
    {
        p.push_back(src);
        //if the destination is reached
        if(src==dest)
        {
            paths.push_back(p);
        }
        for(auto v:graph[src])
        {
            dfs(graph,v,p,paths);
        }
        p.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        dest = n - 1;
        vector<vector<int>> paths;
        vector<int> p;
        dfs(graph,0,p,paths);
        return paths;
    }
};
