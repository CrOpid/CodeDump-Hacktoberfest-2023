#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

const int INF = std::numeric_limits<int>::max();

class Graph
{
    int V;
    std::vector<std::vector<std::pair<int, int>>> adj;

public:
    Graph(int V) : V(V)
    {
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight)
    {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    void primMST()
    {
        std::vector<bool> inMST(V, false);
        std::vector<int> key(V, INF);
        std::vector<int> parent(V, -1);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        int startVertex = 0;
        key[startVertex] = 0;
        pq.push({0, startVertex});

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            inMST[u] = true;

            for (const auto &neighbor : adj[u])
            {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (!inMST[v] && weight < key[v])
                {
                    key[v] = weight;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (parent[i] != -1)
            {
                std::cout << "Edge: " << parent[i] << " - " << i << " Weight: " << key[i] << std::endl;
            }
        }
    }
};

int main()
{
    Graph g(6);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 5, 2);
    g.addEdge(4, 3, 5);
    g.addEdge(4, 5, 1);

    g.primMST();

    return 0;
}
