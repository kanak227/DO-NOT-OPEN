#include <bits/stdc++.h>
using namespace std;

bool isSafe(int col, int row, vector<int>& pos) {
    for (int c = 0; c < col; c++) {
        int r = pos[c];

        // same row
        if (r == row) return false;

        // diagonal check
        if (abs(r - row) == abs(c - col)) return false;
    }
    return true;
}

void solve(int col, int n, vector<int>& pos, vector<vector<int>>& ans) {
    // BASE CASE
    if (col == n) {
        ans.push_back(pos);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(col, row, pos)) {
            pos[col] = row;

            solve(col + 1, n, pos, ans); // no "if" → collect all

            pos[col] = -1; // backtrack
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> ans;
    vector<int> pos(n, -1); // pos[col] = row

    solve(0, n, pos, ans);

    if (ans.size() == 0) {
        cout << -1;
        return 0;
    }

    // print all solutions
    for (auto v : ans) {
        for (int i = 0 ;i<v.size();i++) {
			if(i!=0) cout<<" ";
            cout << v[i];
        }
        cout << endl;
    }

    return 0;
}