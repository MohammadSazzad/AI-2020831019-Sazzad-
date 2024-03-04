#include <bits/stdc++.h>
#define int long long int
using namespace std;

// Function to perform Uniform Cost Search
void UCS(vector<vector<pair<int, int>>> &graph, int start, int end)
{
    // Priority queue to store nodes based on their cost
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Array to store minimum distance to each node
    vector<int> distance(graph.size(), INT_MAX);
    // Array to track visited nodes
    vector<bool> visited(graph.size(), false);
    pq.push({0, start});
    distance[start] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        // If the current node is the goal node, we can terminate
        if (u == end)
        {
            cout << "Shortest distance from " << start << " to " << end << " is: " << distance[u] << endl;
            return;
        }
        // Iterate through neighbors of the current node
        for (const auto &edge : graph[u])
        {
            int v = edge.first;
            int weight = edge.second;

            // Relaxation step: update the distance if a shorter path is found
            if (distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }
    // If the goal node is unreachable
    cout << "No path exists from " << start << " to " << end << endl;
}

int32_t main()
{
    // cout << "Enter the number of nodes and edges: ";
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    vector<vector<pair<int, int>>> graph(numNodes);
    //"Enter the edges (source destination weight);
    for (int i = 0; i < numEdges; ++i)
    {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph[source].push_back({destination, weight});
    }
    // Enter the start and end node
    int start, end;
    cin >> start >> end;
    UCS(graph, start, end);

    return 0;
}

/*

Input :

6 10
0 1 2
0 3 5
3 1 5
3 5 5
3 4 2
1 5 1
4 2 4
4 5 3
2 1 4
5 2 5
0 5

Shortest distance from 0 to 5 is: 3

*/
