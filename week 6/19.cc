// Given a graph, design an algorithm and implement it using a program to find if a graph is bipartite or not. (Hint: use BFS)

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void checkBipartite(vector<vector<int>> &adjMatrix, int V) {
    vector<int> color(V, -1); // -1 means uncolored
    queue<int> q;
    
    for (int i = 0; i < V; i++) {
        if (color[i] == -1) { // If the node is uncolored
            color[i] = 0; // Start coloring with color 0
            q.push(i);
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                
                for (int j = 0; j < V; j++) {
                    if (adjMatrix[node][j] == 1) { // If there is an edge
                        if (color[j] == -1) { // If the neighbor is uncolored
                            color[j] = 1 - color[node]; // Color with opposite color
                            q.push(j);
                        } else if (color[j] == color[node]) { // If the neighbor has the same color
                            cout << "No, the graph is not bipartite." << endl;
                            return;
                        }
                    }
                }
            }
        }
    }
    cout << "Yes, the graph is bipartite." << endl;
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
    checkBipartite(adjMatrix, V);
    return 0;
}