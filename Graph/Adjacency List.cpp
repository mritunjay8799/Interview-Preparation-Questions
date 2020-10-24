======================================================================          PRINT ADJACENCY LIST        =======================================================================

#include<bits/stdc++.h>
using namespace std;

void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; v++) 
    { 
        cout << v; 
        for (auto x : adj[v]) 
           cout << "-> " << x; 
        cout<<endl;
    } 
}


int main()
{
  int n,e;
  cin>>n>>e;
  int a,b;
  vector<int>adj[n];
  for(int i = 0; i<e; i++)
  {
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  printGraph(adj,n);
}
