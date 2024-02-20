#include<bits/stdc++.h>
#define int long long int
using namespace std;

// Graph represented as an adjacency list
vector<vector<int>> adj;

// Depth-Limited Search (DLS) function
bool DLS(int start, int goal, int depth_limit) {
    stack<pair<int, int>> st; // Using a stack to perform DFS
    st.push({start, 0});
    while (!st.empty()) {
        pair<int, int> current = st.top();
        st.pop();

        int node = current.first;
        int depth = current.second;

        // Check if goal is found
        if (node == goal) {
            cout << "Goal is found at depth: " << depth << endl;
            return true;
        }

        // If depth limit is reached, skip exploring further
        if (depth >= depth_limit)continue;

        // Explore neighbors
        for (int neighbor : adj[node])
        {
            st.push({neighbor, depth + 1});
        }
    }
    return false; // Goal not found within depth limit
}

// Iterative Deepening Depth-First Search (IDS) function
bool IDS(int start, int goal, int max_depth) {
    for (int depth_limit = 0; depth_limit <= max_depth; ++depth_limit) {
        cout << "Searching with depth limit: " << depth_limit << endl;
        if (DLS(start, goal, depth_limit))return true;
    }
    return false; // Goal not found within maximum depth
}

int32_t main() {
    // Number of vertices
    int n; 
    cin >> n;
    // The graph
    for(int i = 0; i < n; i++) {
        int u, v; 
        cin >> u >> v;

        int maxVertex = max(u, v);
        if (maxVertex >= adj.size()) {
            adj.resize(maxVertex + 1);
        }

        adj[u].push_back(v);
    }
    // Starting node
    int start; 
    cin >> start;
    // Goal node
    int goal;  
    cin >> goal;
    // Maximum depth
    int max_depth; 
    cin >> max_depth;
    if (IDS(start, goal, max_depth))cout << "Goal is found within maximum depth." << endl;
    else cout << "Goal is not found within maximum depth." << endl;

    return 0;
}