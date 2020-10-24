void DFSUtil (int i, vector <int> g[], int N, bool vis[], vector <int> &res)
{
    if (vis[i]) return;
    vis[i] = true;
    res.push_back (i);
    
    for (int j : g[i])
    {
        if (!vis[j]) DFSUtil (j, g, N, vis, res);
    }
}

vector <int> dfs(vector<int> g[], int N)
{
    bool vis[N];
    memset (vis, false, sizeof (vis));
    
    vector <int> res;
    for (int i = 0;i < N; i++)
    {
        if (!vis[i])
        {
            DFSUtil (i, g, N, vis, res);
        }
    }
    
    return res;
}

