#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> keys(n), freq(n);
    for (int i = 0; i < n; i++) cin >> keys[i];
    for (int i = 0; i < n; i++) cin >> freq[i];

    // Prefix sum for fast W[i,j]
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + freq[i];
    }

    // Function to get sum freq[i..j] in O(1)
    auto getSum = [&](int i, int j) {
        return prefix[j + 1] - prefix[i];
    };

    vector<vector<int>> cost(n, vector<int>(n, 0));

    // Base case
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }

    // DP computation
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            cost[i][j] = INT_MAX;

            for (int r = i; r <= j; r++) {
                int left  = (r > i) ? cost[i][r - 1] : 0;
                int right = (r < j) ? cost[r + 1][j] : 0;

                int total = left + right + getSum(i, j);

                cost[i][j] = min(cost[i][j], total);
            }
        }
    }

    cout << cost[0][n - 1] << endl;

    return 0;
}