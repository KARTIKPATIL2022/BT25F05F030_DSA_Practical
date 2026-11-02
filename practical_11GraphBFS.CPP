#include <iostream>
#include <queue>
using namespace std;

int graph[100][100];
int visited[100];
int vertices, edges;

// Function to create graph
void createGraph() {
int u, v;

```
cout << "Enter number of vertices: ";
cin >> vertices;

cout << "Enter number of edges: ";
cin >> edges;

// Initialize graph and visited array
for (int i = 0; i < vertices; i++) {
    visited[i] = 0;

    for (int j = 0; j < vertices; j++) {
        graph[i][j] = 0;
    }
}

// Enter edges
cout << "\nEnter edges (u v):\n";

for (int i = 0; i < edges; i++) {
    cout << "Edge " << i + 1 << ": ";
    cin >> u >> v;

    if (u >= 0 && u < vertices &&
        v >= 0 && v < vertices) {

        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    else {
        cout << "Invalid edge! Enter again.\n";
        i--;
    }
}
```

}

// Function to display graph
void displayGraph() {
cout << "\nAdjacency Matrix:\n";

```
for (int i = 0; i < vertices; i++) {
    for (int j = 0; j < vertices; j++) {
        cout << graph[i][j] << " ";
    }
    cout << endl;
}
```

}

// BFS Traversal Function
void BFS(int start) {
queue<int> q;

```
visited[start] = 1;
q.push(start);

cout << "\nBFS Traversal: ";

while (!q.empty()) {
    int vertex = q.front();
    q.pop();

    cout << vertex << " ";

    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] == 1 &&
            visited[i] == 0) {

            visited[i] = 1;
            q.push(i);
        }
    }
}
```

}

// Main Function
int main() {
int start;

```
cout << "===== GRAPH IMPLEMENTATION =====\n";

createGraph();

displayGraph();

cout << "\nEnter starting vertex for BFS: ";
cin >> start;

if (start < 0 || start >= vertices) {
    cout << "Invalid starting vertex!";
    return 0;
}

BFS(start);

cout << endl;

return 0;
```

}
