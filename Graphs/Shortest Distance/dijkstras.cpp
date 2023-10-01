#include <iostream>
#include <vector>
#include <queue>
#include <limits>

const int INF = std::numeric_limits<int>::max();

struct Edge
{
    int to;
    int weight;
};

class Graph
{
    int V; // Number of vertices
    std::vector<std::vector<Edge>> adj;

public:
    Graph(int V) : V(V)
    {
        adj.resize(V);
    }

    void addEdge(int from, int to, int weight)
    {
        Edge edge = {to, weight};
        adj[from].push_back(edge);
    }

    void dijkstra(int start)
    {
        std::vector<int> dist(V, INF);
        dist[start] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push({0, start});

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            for (const Edge &edge : adj[u])
            {
                int v = edge.to;
                int weight = edge.weight;

                if (dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Print the shortest distances from the start vertex
        for (int i = 0; i < V; i++)
        {
            std::cout << "Vertex " << i << ": ";
            if (dist[i] == INF)
            {
                std::cout << "Infinity";
            }
            else
            {
                std::cout << dist[i];
            }
            std::cout << std::endl;
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

    std::cout << "Shortest distances from vertex 0:" << std::endl;
    g.dijkstra(0);

    return 0;
}
