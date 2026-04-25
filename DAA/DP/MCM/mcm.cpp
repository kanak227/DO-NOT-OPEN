#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;   // size of array

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int m = n - 1;  // number of matrices

    vector<vector<long long>> dp(m + 1, vector<long long>(m + 1, 0));

    for(int len = 2; len <= m; len++) {
        for(int i = 1; i <= m - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;

            for(int k = i; k < j; k++) {
                long long cost = dp[i][k] 
                               + dp[k+1][j] 
                               + (long long)arr[i-1] * arr[k] * arr[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << dp[1][m] << endl;

    return 0;
}