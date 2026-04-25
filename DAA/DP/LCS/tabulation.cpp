#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b, c;
    cin >> a >> b >> c;

    int n = a.size();
    int m = b.size();
    int l = c.size();

    // 3D DP array
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(l+1, 0)));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 1; k <= l; k++){

                if(a[i-1] == b[j-1] && a[i-1] == c[k-1]){
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                }
                else{
                    dp[i][j][k] = max({
                        dp[i-1][j][k],
                        dp[i][j-1][k],
                        dp[i][j][k-1]
                    });
                }
            }
        }
    }

    cout << dp[n][m][l];
}