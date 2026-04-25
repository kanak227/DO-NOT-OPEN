#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, int col, vector<vector<int>>& adj, vector<int>& color) {
    for (int neighbor : adj[node]) {
        if (color[neighbor] == col)
            return false;
    }
    return true;
}

bool solve(int node, int n, int m, vector<vector<int>>& adj, vector<int>& color) {
    if (node == n)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(node, c, adj, color)) {
            color[node] = c;

            if (solve(node + 1, n, m, adj, color))
                return true;

            color[node] = 0; // backtrack
        }
    }

    return false;
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<int>> adj(n);

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int m; // number of colors
    cin >> m;

    vector<int> color(n, 0);

    if (solve(0, n, m, adj, color))
        cout << "Solution exists";
    else
        cout << "Solution does not exist";

    return 0;
}