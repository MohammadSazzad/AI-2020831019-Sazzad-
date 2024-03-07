#include<bits/stdc++.h>
#define int long long int
#define mod 1000000007
#define fast ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

// Structure to represent a node in the graph
struct Node 
{
    int x, y; // Coordinates of the node
    int cost; // Cost to reach this node
    int heuristic; // Heuristic value (estimated cost to reach the goal)
    Node* parent; // Pointer to the parent node

    Node(int x, int y, int cost, int heuristic, Node* parent = nullptr)
        : x(x), y(y), cost(cost), heuristic(heuristic), parent(parent) {}

    // Function to calculate the total cost (f value) of the node
    int getCost() const {
        return cost + heuristic;
    }
};

// Custom comparator for priority queue
struct CompareNode 
{
    bool operator()(const Node* a, const Node* b) const {
        return a->getCost() > b->getCost();
    }
};

// Function to check if a given coordinate is within the bounds of the grid
bool isValid(int x, int y, int rows, int cols) 
{
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

// A* search algorithm
vector<pair<int, int>> aStarSearch(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal) 
{
    int rows = grid.size();
    int cols = grid[0].size();

    // Define the movement directions (up, down, left, right)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Priority queue to store the nodes to be explored
    priority_queue<Node*, vector<Node*>, CompareNode> openList;

    // Map to store the cost to reach each node
    map<pair<int, int>, int> costMap;

    // Start node
    Node* startNode = new Node(start.first, start.second, 0, 0);
    openList.push(startNode);
    costMap[start] = 0;

    // A* search
    while (!openList.empty()) 
    {
        // Get the node with the lowest cost from the priority queue
        Node* currentNode = openList.top();
        openList.pop();

        // Check if the current node is the goal
        if (currentNode->x == goal.first && currentNode->y == goal.second) 
        {
            // Reconstruct the path
            vector<pair<int, int>> path;
            while (currentNode != nullptr) {
                path.push_back({currentNode->x, currentNode->y});
                currentNode = currentNode->parent;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        // Explore neighbors
        for (auto& dir : directions) 
        {
            int newX = currentNode->x + dir.first;
            int newY = currentNode->y + dir.second;

            if (isValid(newX, newY, rows, cols) && grid[newX][newY] != 1) 
            {
                int newCost = currentNode->cost + 1; // Assuming unit cost for movement
                int newHeuristic = abs(newX - goal.first) + abs(newY - goal.second); // Manhattan distance heuristic

                // Check if the new cost is lower than the existing cost to reach this node
                if (!costMap.count({newX, newY}) || newCost < costMap[{newX, newY}]) 
                {
                    costMap[{newX, newY}] = newCost;
                    Node* newNode = new Node(newX, newY, newCost, newHeuristic, currentNode);
                    openList.push(newNode);
                }
            }
        }
    }

    // No path found
    return {};
}

int32_t main() 
{
    fast  // Fast I/O
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    pair<int, int> start = {0, 0};
    pair<int, int> goal = {4, 4};

    vector<pair<int, int>> path = aStarSearch(grid, start, goal);

    if (!path.empty()) 
    {
        cout << "Path found:" << endl;
        for (auto& p : path) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    } 
    else 
    {
        cout << "No path found!" << endl;
    }

    return 0;
}
