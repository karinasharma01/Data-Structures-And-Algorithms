//basic C++ code to demonstrate Depth-First-Search(DFS) &Breadth-First-Search(BFS) 
//The given implementation handles the case of both connected and disconnected graphs.
#include<iostream>
#include<vector>
using namespace std;
void printDFS(int** edges,int n,int startV, bool* visited)
{
    cout<<startV<<endl;
    visited[startV]=true;
    for(int i=0;i<n;i++)
    {
        if(i == startV)
        {
            continue;
        }
        if(edges[startV][i]==1 && !visited[i])
        {
            printDFS(edges,n,i,visited);
        }
    }
}
void DFS(int** edges,int n)
{
    bool* visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)//ie the vertex or node hasn't been visited then that vertex becomes the startVertex for that call
        {
            printDFS(edges,n,i,visited);
        }
    }
    delete [] visited;
}
//Breadth First Search
void printBFS(int** edges,int n,int startV,bool* visited){
queue<int> pendingVertices;
pendingVertices.push(startV);
    visited[startV]=true;
while(!pendingVertices.empty())
{
    int currentVertex=pendingVertices.front();
    pendingVertices.pop();
    cout<<currentVertex<<endl;
    for(int i=0;i<n;i++)
    {
        if(i==currentVertex)
        {
            continue;
        }

    if(edges[currentVertex][i]==1 && !visited[i])
    {
        pendingVertices.push(i);
        visited[i]=true;
    }
    }
}

}
void BFS(int** edges,int n)
{
    bool* visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)//ie the vertex or node hasn't been visited then that vertex becomes the startVertex for that call
        {
            printBFS(edges,n,i,visited);
        }
    }
    delete [] visited;

}
int main()
{//the graph is being implemented using an Adjacency Matrix
int n,e;//n is the no of vertices in graph numbered from 0 to n-1
//e is the number of edges present in the graph
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
        int first,second;
        cin>>first>>second;
        edges[first][second]=1;
        edges[second][first]=1;
    }
cout<<"DFS:"<<endl;
    DFS(edges,n);
    cout<<"BFS:"<<endl;
    BFS(edges,n);
for(int i=0;i<n;i++)
    {
        delete [] edges[i];
    }
    delete [] edges;
    return 0;
}
