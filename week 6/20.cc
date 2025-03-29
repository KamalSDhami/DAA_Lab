// Given a directed graph, design an algorithm and implement it using a program to find whether cycle exists in the graph or not.

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void dfs(int node, vector<vector<int>> &adjMatrix, vector<bool> &visited, vector<bool> &recStack, bool &hasCycle) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < adjMatrix.size(); i++) {
        if (adjMatrix[node][i] == 1) { // If there is an edge
            if (!visited[i]) {
                dfs(i, adjMatrix, visited, recStack, hasCycle);
            } else if (recStack[i]) { // If the node is in the recursion stack
                hasCycle = true;
                return;
            }
        }
    }
    recStack[node] = false; // Remove the node from recursion stack
}

bool isCyclic(vector<vector<int>> &adjMatrix) {
    vector<bool> visited(adjMatrix.size(), false);
    vector<bool> recStack(adjMatrix.size(), false);
    bool hasCycle = false;

    for (int i = 0; i < adjMatrix.size(); i++) {
        if (!visited[i]) {
            dfs(i, adjMatrix, visited, recStack, hasCycle);
            if (hasCycle) return true;
        }
    }
    return false;
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;
    vector<vector<int>> adjMatrix(V, vector<int>(V));
    cout << "Enter the adjacency matrix: " << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> adjMatrix[i][j];
        }
    }
    if (isCyclic(adjMatrix)) {
        cout << "Yes, the graph has a cycle." << endl;
    } else {
        cout << "No, the graph does not have a cycle." << endl;
    }
    return 0;
}