class Solution {
public:
    bool dfs(vector<vector<char>>& grid,int m,int n,char& startC,int currX,int currY,vector<vector<int>>& dir,vector<vector<bool>>& visited,int prevX,int prevY)
    {
        visited[currX][currY]=true;
        for(int d=0;d<dir.size();d++)
        {
            int x = currX + dir[d][0];
            int y = currY + dir[d][1];
            if(x>=0 && y>=0 && x<m && y<n)
            {
                if(!(x==prevX && y==prevY))
                {
                    if(grid[x][y]==startC)
                    {
                        if(visited[x][y])
                        {
                            return true;
                        }
                        else
                        {
                            if(dfs(grid,m,n,grid[x][y],x,y,dir,visited,currX,currY))
                                return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool> (n,false));
        vector<vector<int>> dir{{-1,0},{0,1},{0,-1},{1,0}};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && dfs(grid,m,n,grid[i][j],i,j,dir,visited,-1,-1))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
