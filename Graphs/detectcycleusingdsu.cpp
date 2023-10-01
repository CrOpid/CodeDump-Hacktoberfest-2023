#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
public:
    vector<int> par, sizeL;
    DisjointSet(int n)
    {
        par.resize(n);
        sizeL.resize(n, 1);
        for (int i = 0; i < n; i++)
            par[i] = i;
    }
    int findPar(int u)
    {
        if (u == par[u])
            return u;
        return par[u] = findPar(par[u]);
    }
    void unionBysize(int u, int v)
    {
        int ulpu = findPar(u);
        int ulpv = findPar(v);
        if (ulpu == ulpv)
            return;
        if (sizeL[ulpu] < sizeL[ulpv])
        {
            sizeL[ulpv] += sizeL[ulpu];
            par[ulpu] = par[ulpv];
        }
        else
        {
            sizeL[ulpu] += sizeL[ulpv];
            par[ulpv] = par[ulpu];
        }
    }
};

class Solution
{
public:
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[])
    {
        DisjointSet ds(V);
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int u = i;
                int v = it;
                if (ds.findPar(u) == ds.findPar(v) && u < v)
                    return 1;
                else
                {
                    ds.unionBysize(u, v);
                }
            }
        }
        return 0;
        // Code here
    }
};

int main()
{
}