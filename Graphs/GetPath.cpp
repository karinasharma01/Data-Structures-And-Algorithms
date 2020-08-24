//Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
//The path is printed in reverse order ie the vertex v2 is printed first followed by the intermediate vertices and then the vertex v1 is printed at last.
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
