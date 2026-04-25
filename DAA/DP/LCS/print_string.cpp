#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    // DP table
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // Step 1: Fill DP table
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // Step 2: Backtrack to find LCS string
    int i = n, j = m;
    string lcs = "";

    while(i > 0 && j > 0){
        if(a[i-1] == b[j-1]){
            lcs += a[i-1];   // take character
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--; // move up
        }
        else{
            j--; // move left
        }
    }

    // reverse because we built it backwards
    reverse(lcs.begin(), lcs.end());

    cout << lcs << endl;
}