class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //using topological sorting
        /*we consider a cell in the matrix as a node in the graph and a direct edge from node a 
        to node b if a & b are adjacent & value of a < value of b
        */
        int m = matrix.size();
        if(m==0)
            return 0;
        int n = matrix[0].size();
        vector<vector<int>> dir{{-1,0},{0,1},{1,0},{0,-1}};
        vector<vector<int>> indegree(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int d=0;d<dir.size();d++)
                {
                    int row = i + dir[d][0];
                    int col = j + dir[d][1];
                    if(row>=0 && col>=0 && row<m && col<n && matrix[row][col]>matrix[i][j])
                    {
                        //edge ids directed from cell matrix[i][j] to matrix[row][col]
                        indegree[row][col]++;
                    }
                }
            }
        }
        //add all the cells with indegree 0 to the queue
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(indegree[i][j]==0)
                {
                    q.push({i,j});
                }
            }
        }
        int len = 0;
        while(!q.empty())
        {
            int s = q.size();
            while(s--)
            {
                pair<int,int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                for(int d = 0;d<dir.size();d++)
                {
                    int nx = x + dir[d][0];
                    int ny = y + dir[d][1];
                    if(nx>=0 && ny>=0 && nx<m && ny<n)
                    {
                        if(matrix[x][y]<matrix[nx][ny] && --indegree[nx][ny]==0)
                        {
                            q.push({nx,ny});
                        }
                    }
                }
            }
            len++;
        }
        return len;
    }
};
