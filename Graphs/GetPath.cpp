//Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
//The path is printed in reverse order ie the vertex v2 is printed first followed by the intermediate vertices and then the vertex v1 is printed at last.
#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> getPathDFS(int** edges,int V,int startV,int endV,bool* visited)
{
   vector<int> v;
    if(startV == endV)
    {
        v.push_back(startV);
        return v;
    }
    visited[startV]=true;
    for(int i=0;i<V;i++)
    {
        if(visited[i]==true)
        {
            continue;
        }
        if(edges[startV][i]==1 && !visited[i])
        {
            vector<int> v1=getPathDFS(edges,V,i,endV,visited);
            if(!v1.empty())
            {
                v1.push_back(startV);
                return v1;
            }
        }
    }
    return v;
}
vector<int> getPathBFS(int** edges,int V,int startV,int endV,bool* visited)
{
    
    queue<int> q;
    q.push(start);
    bool flag=false;
    visited[startV]=true;
    unordered_map<int,int> parent;//Hashmap to keep a track of which vertex leads to the 
    //insertion of a vertex into the queue
    while(!q.empty() && !flag)
    {
        int currentVertex=q.front();
        q.pop();
        for(int i=0;i<V;i++)
        {
            if(edges[currentVertex][i]==1 && !visited[i])
            {
                parent[i]=currentVertex;
                q.push(i);
                visited[i]=true;
                if(i==end)
                {
                    flag=true;
                    break;
                }
            }
        }
    }
    if(flag==true)
    {
        vector<int> output;
        int current=endV;
        output.push_back(current);
        while(current!=startV)
        {
            current=parent[current];
            output.push_back(current);
        }
    return output;
    }
    else
    {
      vector<int> output;
        return output;
    }
    
    
    
}
vector<int> getPath(int** edges,int V,int startV,int endV)
{
    bool* visited=new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    return getPathDFS(edges,V,startV,endV,visited);

}
int main()
{
  int V, E;
  cin >> V >> E;
    
    int** edges=new int*[V];
    for(int i=0;i<V;i++)
    {
        edges[i]=new int[V];
        for(int j=0;j<V;j++)
        {
            edges[i][j]=0;
        }
    }
    for(int i=0;i<E;i++)
    {
        int first,second;
        cin>>first>>second;
        edges[first][second]=1;
        edges[second][first]=1;
    }
    int startV,endV;
    cin >> startV >> endV;
    vector<int> path=getPath(edges,V,startV,endV);
    for(int i=0;i<path.size();i++)
    {
        cout << path[i] << " " ;
    }
    for(int i=0;i<V;i++)
    {
        delete [] edges[i];
    }
    delete [] edges;
}
