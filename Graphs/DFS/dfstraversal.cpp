#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> &ans, vector<int> adj[], vector<bool> &vis)
{
    vis[node] = true;
    ans.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, ans, adj, vis);
        }
    }
}
vector<int> dfsOfGraph(int v, vector<int> adj[])
{
    vector<int> ans;
    vector<bool> vis(v + 1, false);
    dfs(0, ans, adj, vis);
    return ans;
}
int main()
{
}