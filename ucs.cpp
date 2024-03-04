#include<bits/stdc++.h>
#define int long long int
using namespace std;

const int N=100005;
// Array to store minimum distance to each node
vector<vector<pair<int, int>>> g(N);

// Function to perform Uniform Cost Search
void UCS(int start, int end)
{
    // Priority queue to store nodes based on their cost
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    vector<int> d(g.size(),INT_MIN);
    // Array to track visited nodes 
    vector<bool> vis(g.size(),false); 
    pq.push({0, start});
    d[start] = 0;
    while (!pq.empty()) 
    {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        // If the current node is the goal node, we can terminate
        if (u == end) {
            cout << "Shortest distance from " << start << " to " << end << " is: " << d[u] << endl;
            return;
        }
        // Iterate through neighbors of the current node
        for (auto e : g[u]) 
        {
            int v = e.first;
            int w = e.second;
            // Relaxation step: update the distance if a shorter path is found
            if (d[u] + w < d[v]) 
            {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
    // If the goal node is unreachable
    cout << "No path exists from " << start << " to " << end << endl;
}

int32_t main() 
{
    // n number of nodes and m number of edges 
    int n, m; 
    cin >> n >> m;
    g.resize(n);
    //"Enter the edges (source destination weight);
    for (int i = 0; i < n; ++i) {
        int source, dest, w;
        cin >> source >> dest >> w;
        g[source].push_back({dest, w});
    }


    //Enter the start and end node
    int start, end; cin >> start >> end;
    UCS(start, end);

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

No path exists from 4 to 2

*/