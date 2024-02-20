#include<bits/stdc++.h>
#define int long long int
using namespace std;

// Graph represented as an adjacency list
vector<vector<int>> adj;

// DFS with depth limit
bool DFS(int start, int goal, int depth_limit) {
    stack<pair<int, int>> stk; // Using a stack to perform DFS

    stk.push({start, 0});

    while (!stk.empty()) {
        pair<int, int> current = stk.top();
        stk.pop();

        int node = current.first;
        int depth = current.second;

        // Check if goal is found
        if (node == goal) {
            cout << "Goal is found at depth: " << depth << endl;
            return true;
        }

        // If depth limit is reached, skip exploring further
        if (depth >= depth_limit)
            continue;

        // Explore neighbors
        for (int neighbor : adj[node]) {
            stk.push({neighbor, depth + 1});
        }
    }

    return false; // Goal not found within depth limit
}

int32_t main() {
   
   // number of vertices
    int n; cin>>n;

     //The graph
    for(int i=0; i<n; i++)
    {
        int u,v; cin>>u>>v;

        int maxVertex = max(u, v);
       if (maxVertex >= adj.size()) {
        adj.resize(maxVertex + 1);
       }

        adj[u].push_back(v);

    }


    // Starting node
    int start ; cin>>start; 

     // Goal node
    int goal ; cin>>goal;  

     // Depth limit  
    int depth_limit; cin>>depth_limit;  

    if (DFS(start, goal, depth_limit))
        cout << "Goal is found within depth limit." << endl;
    else
        cout << "Goal is not found within depth limit." << endl;

    return 0;
}

/*
Input
4
1 2
1 3
2 3
2 4
1
4
3 
Output
Goal is found at depth: 2
Goal is found within depth limit.
*/