# USING ADJACENCY MATRIX


#define initial 1
#define waiting 2
#define visited 3
int state[1000];
void BFS(int v,vector<int>&res,int N,vector<vector<int> >adj)
{
    if(N==0)
        return;
    queue<int>q;
    q.push(v);
    state[v] = waiting;
    while(!q.empty())
    {
        v = q.front();
        res.push_back(v);
        q.pop();
        state[v] = visited;
        for(int i = 0;i<N;i++)
        {
            if(adj[v][i]==1 && state[i] == initial)
            {
                q.push(i);
                state[i] = waiting;
            }
        }
    }
    return;
}
vector <int> bfs(vector<int> g[], int N) {

    // Your code here
    vector<int>res;
    vector<vector<int> >adj(N,vector<int>(N,0));
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<g[i].size();j++)
            adj[i][g[i][j]] = 1;
    }
    for(int i = 0;i<N;i++)
        state[i] = initial;
    BFS(0,res,N,adj);
    return res;
}
================================================================================================================================================================================
#  USING ADJACENCY LIST

vector <int> bfs(vector<int> g[], int N) {
    vector <bool> vis (N, false);
    int s = 0;
    vis[s] = true; // Initially mark source vertex as visited(true)
    vector <int> res;
    queue<int> q;
    q.push(s); // Push the source vertex to queue

    while (!q.empty()) // Till queue is not empty
    {
        int t = q.front();
        res.push_back (t);

        q.pop(); // Pop the queue front

        for (int v :g[t]) // Traverse through all the connected components of front
        {
            if (!vis[v]) 	{ // If they are not visited, mark them visited and add to queue
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return res;
