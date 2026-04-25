#include <bits/stdc++.h>
using namespace std;

int dp[105][105][105]; // adjust size if needed

int solve(string &a, string &b, string &c, int i, int j, int k){
    
    // base case
    if(i < 0 || j < 0 || k < 0)
        return 0;

    // already computed
    if(dp[i][j][k] != -1)
        return dp[i][j][k];

    // match case
    if(a[i] == b[j] && a[i] == c[k]){
        return dp[i][j][k] = 1 + solve(a, b, c, i-1, j-1, k-1);
    }

    // not match case
    return dp[i][j][k] = max({
        solve(a, b, c, i-1, j, k),
        solve(a, b, c, i, j-1, k),
        solve(a, b, c, i, j, k-1)
    });
}

int main(){
    string a, b, c;
    cin >> a >> b >> c;

    memset(dp, -1, sizeof(dp));

    int n = a.size();
    int m = b.size();
    int l = c.size();

    cout << solve(a, b, c, n-1, m-1, l-1);
}