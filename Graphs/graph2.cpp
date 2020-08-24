//Program to check if a path exisits between 2 given vertices in a graph.
//If the path exists between the two vertices v1 and v2, the complete path is printed in reverse order, i.e, in printing the path from vertex v1 to v2, the vertex v2 is printed first
//then the intermediate vertices in the path and then finally the vertex v1 is printed.
#include <iostream>
#include <vector>
usind namespace std;

bool hasPathDFS(int** edges,int n,int startV,int endV,bool* visited)
{
  if(startV == endV)
        return true;
    bool result=false;
     for(int i=0;i<V;i++)
    {
    
        if(edges[start][i]==1 && !visited[i])
        {
            visited[i]=1;
            result=hasPathDFS(edges,V,i,end,visited);
            if(result==true)
            {
                return true;
            }
            
        }
        
        
    }
    return result;
    
    

}
bool hasPath(int** edges,int n,int v1,int v2)
{
bool* visited=new bool[n];
for(int i=0;i<n;i++)
    {
      visited[i]=false;
    }
    hasPathDFS(edges,n,v1,v2,visited);
}
int main()
{
int n,e;//n is the no of vertices & e is the no of edges in the graph
    cin>>n>>e;
    //creating an adjacency matrix
    int** edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    if(hasPath(edges,n,v1,v2))//function to check whether a path exists b/w vertex v1 & v2 or not
    {
        cout<<"true"<<endl;
    }
    cout<<"false"<<endl;
    for(int i=0;i<n;i++)
    {
        delete [] edges[i];
    }
    delete [] edges;
}
