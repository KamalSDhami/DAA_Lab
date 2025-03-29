/*Note: Consider the following input format in the form of adjacency matrix for graph based
 questions (directed/undirected/weighted/unweighted graph).
 Input Format: Consider example of below given graph in Figure (a). 
A boolean matrix AdjM of size V X V is defined to represent edges of the graph. Each edge of
 graph is represented by two vertices (start vertex u, end vertex v). That means, an edge from u to v
 is represented by making AdjM[u,v] and AdjM[v,u] = 1. If there is no edge between u and v then it
 is represented by making AdjM[u,v] = 0. Adjacency matrix representation of below given graph is
 shown in Figure (b). Hence edges are taken in the form of adjacency matrix from input. In case of
 weighted graph, an edge from u to v having weight w is represented by making AdjM[u,v] and
 AdjM[v,u] = w.
 Input format for this graph is shown in Figure (c). 
First input line will obtain number of vertices V present in graph.
 After first line, V input lines are obtained. For each line i in V, it contains V space separated
 boolean integers representing whether an edge is present between i and all V*/

//  Given a (directed/undirected) graph, design an algorithm and implement it using a program to find if a path exists between two given vertices or not. (Hint: use DFS)

#include<iostream>
#include<vector>

using namespace std;

void dfs(int start, int end, vector<vector<int>> &adjMatrix, vector<bool> &visited, bool &pathExists) {
    visited[start] = true;
    if (start == end) {
        pathExists = true;
        return;
    }
    for (int i = 0; i < adjMatrix.size(); i++) {
        if (adjMatrix[start][i] == 1 && !visited[i]) {
            dfs(i, end, adjMatrix, visited, pathExists);
            if (pathExists) return; // Stop further exploration if path is found
        }
    }
}
bool DFS(vector <vector<int>>matx,int src, int dest, vector<bool>& visited,int V) { 
    if (src == dest) return true; 
    visited[src] = true; 
    for (int i = 0; i < V; i++) { 
        if (matx[src][i] == 1 && !visited[i]) { 
            if (DFS(matx,i, dest, visited,V)) 
                return true; 
        } 
    } 
    return false; 
}
void checkPath(vector<vector<int>> matx,int src, int dest,int V) { 
    vector<bool> visited(V, false); 
    if (DFS(matx,src - 1, dest - 1, visited,V))  
        cout << "Yes Path Exists" << endl; 
    else 
        cout << "No Such Path Exists" << endl; 
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
    int start, end;
    cout << "Enter the start and end vertices: ";
    cin >> start >> end;
    vector<bool> visited(V, false);
    bool pathExists = false;
    checkPath(adjMatrix, start, end,V);
    return 0;
}