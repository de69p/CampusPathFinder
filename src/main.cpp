#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

// Define the structure of a vertex which contains a destination and the distance to it
struct vertexType {
    string to;
    int distance;
};

// Define global adjacency list and predecessor map
unordered_map<string, list<vertexType>> adjList;
unordered_map<string, string> predecessor;

// Recursive function for depth-first search (DFS) traversal of the graph
void dfs(const string& start, const string& end, int stamina) {
    // If stamina is 0 or less, return from the function
    if (stamina <= 0) {
        return;
    }

    // If the start node is the end node, print the path and return
    if (start == end) {
        cout << "Time to cool off!\nPath: ";
        for (string node = end; node != start; node = predecessor[node]) {
            cout << node << " ";
        }
        cout << endl;
        return;
    }

    // Loop through the adjacency list and continue DFS
    for (const vertexType& neighbor : adjList[start]) {
        // Update the predecessor of the neighbor
        predecessor[neighbor.to] = start;
        // Continue DFS with the neighbor as the start node and reduced stamina
        dfs(neighbor.to, end, stamina - neighbor.distance);
    }
}

int main() {
    string start, end;
    int stamina;
    // Read the start and end nodes, and the stamina from the input
    cin >> start >> end >> stamina;

    // Read the edge data and add it to the adjacency list
    while (true) {
        string from, to;
        int distance;
        cin >> from >> to >> distance;
        if (from.empty()) {
            break;
        }

        // Push the destination and distance into the adjacency list of the source node
        adjList[from].push_back({to, distance});
    }

    // Start the DFS traversal from the start node
    dfs(start, end, stamina);

    return 0;
}
