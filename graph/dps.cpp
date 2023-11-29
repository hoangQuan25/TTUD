#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

const int N = 1e4 + 5;
vector<int> adj[N];
vector<bool> visited(N, false);

void dfs(int u) {
    cout << "Visiting node: " << u << endl;
    visited[u] = true;

    for (const int &v : adj[u]) {
        if (!visited[v]) {
            cout << "Exploring neighbor: " << v << endl;
            dfs(v);
        }
    }
}

void input() {
    ifstream inputFile("data.inp");
    if (!inputFile.is_open()) {
        cerr << "Error opening file!" << endl;
        exit(1);
    }

    int n, m;
    inputFile >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        inputFile >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    inputFile.close();
}

int main() {
    input();

    int startNode;
    cin >> startNode;

    cout << "Starting DFS traversal from node: " << startNode << endl;

    dfs(startNode);

    return 0;
}
