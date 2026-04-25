#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, vector<vector<int>>& maze, int n,
           vector<vector<int>>& vis, string path, vector<string>& ans) {
    
    // destination reached
    if (i == n - 1 && j == n - 1) {
        ans.push_back(path);
        return;
    }

    // directions: D, L, R, U
    int di[] = {1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};
    char move[] = {'D', 'L', 'R', 'U'};

    for (int k = 0; k < 4; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];

        if (ni >= 0 && nj >= 0 && ni < n && nj < n &&
            maze[ni][nj] == 1 && vis[ni][nj] == 0) {
            
            vis[i][j] = 1;

            solve(ni, nj, maze, n, vis, path + move[k], ans);

            vis[i][j] = 0; // backtrack
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    vector<string> ans;

    // edge case: start blocked
    if (maze[0][0] == 1) {
        vector<vector<int>> vis(n, vector<int>(n, 0));
        solve(0, 0, maze, n, vis, "", ans);
    }

    if (ans.size() == 0) {
        cout << -1;
    } else {
        sort(ans.begin(), ans.end()); // ensure lexicographic
        for (int i = 0 ;i<ans.size();i++) {
			if(i!=0)cout<<" ";
            cout << ans[i];
        }
    }

    return 0;
}