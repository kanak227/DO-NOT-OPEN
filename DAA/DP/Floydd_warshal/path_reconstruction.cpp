#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
    int n, e;
    cin >> n >> e;

    vector<vector<int>> dist(n, vector<int>(n, INF));
    vector<vector<int>> next(n, vector<int>(n, -1));

    // Initialize
    for(int i = 0; i < n; i++){
        dist[i][i] = 0;
        next[i][i] = i;
    }

    // Input edges
    for(int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;

        u--; v--; // convert to 0-based

        dist[u][v] = w;
        next[u][v] = v;
    }

    // Floyd Warshall
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][k] < INF && dist[k][j] < INF){
                    if(dist[i][k] + dist[k][j] < dist[i][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next[i][j] = next[i][k]; // KEY STEP
                    }
                }
            }
        }
    }

    // Function to print path
    auto getPath = [&](int u, int v){
        if(next[u][v] == -1){
            cout << "No path\n";
            return;
        }

        vector<int> path;
        while(u != v){
            path.push_back(u);
            u = next[u][v];
        }
        path.push_back(v);

        for(int node : path)
            cout << node+1 << " "; // convert back to 1-based
        cout << endl;
    };

    // Example: print path from 1 to n
    cout << "Path from 1 to " << n << ":\n";
    getPath(0, n-1);

    return 0;
}