class Solution
{
public:
    int findParent(int a, int par[])
    {
        if (par[a] == a)
        {
            return a;
        }
        return par[a] = findParent(par[a], par);
    }

    void union_(int a, int b, int par[], int rank1[])
    {
        a = findParent(a, par);
        b = findParent(b, par);
        if (rank1[a] > rank1[b])
        {
            par[b] = a;
        }
        else if (rank1[b] > rank1[a])
        {
            par[a] = b;
        }
        else
        {
            par[a] = b;
            rank1[b]++;
        }
    }

    bool isConnected(int x, int y, int par[], int rank1[])
    {
        x = findParent(x, par);
        y = findParent(y, par);
        if (x == y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};